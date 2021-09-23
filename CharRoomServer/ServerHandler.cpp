#include "ServerHandler.h"
#include <QDebug>

ServerHandler::ServerHandler()
{
    m_handlerMap.insert("CONN", &ServerHandler::CONN_Handler);
    m_handlerMap.insert("DSCN", &ServerHandler::DSCN_Handler);
    m_handlerMap.insert("LGIN", &ServerHandler::LGIN_Handler);
    m_handlerMap.insert("MSGA", &ServerHandler::MSGA_Handler);
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

void ServerHandler::DSCN_Handler(QTcpSocket&, TextMessage&)
{

}

void ServerHandler::LGIN_Handler(QTcpSocket& obj, TextMessage& msg)
{
    QString data = msg.data();
    int index = data.indexOf('\r'); //得到'r'的位置
    QString id = data.mid(0, index); //取出到指定位置的字符串
    QString pwd = data.mid(index + 1);
    QString result = "";

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
        }
        else
        {
            result = "LIER";
        }
    }

    obj.write(TextMessage(result, id).serialize());
}

void ServerHandler::MSGA_Handler(QTcpSocket&, TextMessage&)
{

}
