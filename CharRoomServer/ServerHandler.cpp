#include "ServerHandler.h"
#include <QDebug>

ServerHandler::ServerHandler()
{
    m_handlerMap.insert("CONN", &ServerHandler::CONN_Handler);
    m_handlerMap.insert("DSCN", &ServerHandler::DSCN_Handler);
    m_handlerMap.insert("LGIN", &ServerHandler::LGIN_Handler);
    m_handlerMap.insert("MSGA", &ServerHandler::MSGA_Handler);
    m_handlerMap.insert("MSGP", &ServerHandler::MSGP_Handler);

    static Node admin;

    admin.id = "Admin";
    admin.pwd = "dt0919";
    admin.level = "admin";

    m_nodeList.append(&admin);
}

QString ServerHandler::getOnlineUserId()
{
    QString ret = "";

    for(int i=0; i<m_nodeList.length(); i++)
    {
        if(m_nodeList[i]->socket != NULL)
        {
            ret += m_nodeList[i]->id + '\r';
        }
    }

    return ret;
}

void ServerHandler::sendToAllOnlineUser(TextMessage& msg)
{
    const QByteArray& ba = msg.serialize();

    for(int i=0; i<m_nodeList.length(); i++)
    {
        Node* node = m_nodeList[i];

        if( node->socket != NULL )
        {
            node->socket->write(ba);
        }
    }

}

void ServerHandler::handle(QTcpSocket& obj, TextMessage& msg)
{
    //检查是否包含这个键值
    if( m_handlerMap.contains( msg.type() ))
    {
        MSGHandler handler = m_handlerMap.value(msg.type());

        (this->*handler)(obj, msg);
    }
}

void ServerHandler::CONN_Handler(QTcpSocket&, TextMessage&)
{

}

void ServerHandler::DSCN_Handler(QTcpSocket& obj, TextMessage&)
{
    for(int i=0; i<m_nodeList.length(); i++)
    {
       Node* n = m_nodeList.at(i);

       if( n->socket == &obj)
       {
           n->socket = NULL;
           break;
       }
    }

    TextMessage text("USER", getOnlineUserId());

    sendToAllOnlineUser(text);

}

void ServerHandler::LGIN_Handler(QTcpSocket& obj, TextMessage& msg)
{
    QString data = msg.data();
    int index = data.indexOf('\r'); //得到'r'的位置
    QString id = data.mid(0, index); //取出到指定位置的字符串
    QString pwd = data.mid(index + 1);
    QString result = "";
    QString status = "";
    QString level = "";

    index = -1;

    for(int i=0; i<m_nodeList.length(); i++)
    {
        if( id == m_nodeList.at(i)->id )
        {
            index = i;
            break;
        }
    }

    if( index == -1 )
    {
        Node* newNode = new Node();

        if( newNode != NULL )
        {
            newNode->id = id;
            newNode->pwd = pwd;
            newNode->socket = &obj;

            m_nodeList.append(newNode);

            status = newNode->status;
            level = newNode->level;
            result = "LIOK";
        }
        else
        {
            result = "LIER";
        }
    }
    else
    {
        Node* n = m_nodeList.at(index);

        if( pwd == n->pwd )
        {
            n->socket = &obj;

            result = "LIOK";
            status = n->status;
            level = n->level;
        }
        else
        {
            result = "LIER";
        }
    }

    obj.write(TextMessage(result, id + '\r' + status + 'r' + level).serialize());

    if( result == "LIOK" )
    {
        TextMessage text("USER", getOnlineUserId());

        sendToAllOnlineUser(text);
    }

}

void ServerHandler::MSGA_Handler(QTcpSocket&, TextMessage& msg)
{
    const QByteArray& ba = msg.serialize();

    //遍历列表 发送数据
    for(int i=0; i<m_nodeList.length(); i++)
    {
       Node* n = m_nodeList.at(i);

       if( n->socket != NULL )
       {
           n->socket->write(ba);
       }
    }
}

void ServerHandler::MSGP_Handler(QTcpSocket&, TextMessage& msg)
{
    QStringList t1 = msg.data().split("\r", QString::SkipEmptyParts);
    const QByteArray& ba = TextMessage("MSGA", t1.last()).serialize(); //msg信息的最后必然是消息

    t1.removeLast(); //移除消息 剩下的则全部是id

    for(int i=0; i<t1.length(); i++)
    {
        for(int j=0; j<m_nodeList.count(); j++)
        {
            Node* n = m_nodeList.at(j);

            if( (t1[i] == n->id) && (n->socket != NULL))
            {
                n->socket->write(ba);
            }
        }
    }

}
