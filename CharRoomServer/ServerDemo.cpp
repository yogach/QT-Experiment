#include "ServerDemo.h"
#include <QHostAddress>
#include <QTcpSocket>
#include <QObjectList>
#include <QDebug>

ServerDemo::ServerDemo(QObject *parent) : QObject(parent)
{
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

bool ServerDemo::start(int port)
{
    bool ret = true;

    if( !m_server.isListening() )
    {
        ret = m_server.listen(QHostAddress("127.0.0.1"), port);
    }

    return ret;
}

void ServerDemo::stop()
{
    if( m_server.isListening() )
    {
        m_server.close();
    }
}


void ServerDemo::onNewConnection()
{        
    QTcpSocket* tcp = m_server.nextPendingConnection(); //得到新连接上的客户端对象

    //每有一个新客户端连接 新建一个对象
    TxtMessageAssembler* assembler = new TxtMessageAssembler();
    m_map.insert(tcp, assembler);

    connect(tcp, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tcp, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(tcp, SIGNAL(readyRead()), this, SLOT(onDataReady()));
    connect(tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));

    if( m_handler != NULL )
    {
       TextMessage msg("CONN", tcp->peerAddress().toString() + ":" + QString::number(tcp->peerPort()));

       m_handler->handle(*tcp, msg);
    }
}

void ServerDemo::onConnected()
{
}

void ServerDemo::onDisconnected()
{
    QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(sender()); //得到信号的发送者

    if( tcp != NULL)
    {
        delete m_map.take(tcp); //得到对应键值对的值 并解除对应关系

        if( m_handler != NULL )
        {
           TextMessage msg("DSCN", "");

           m_handler->handle(*tcp, msg);
        }
    }
}

void ServerDemo::onDataReady()
{
    QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(sender()); //得到信号的发送者
    char buf[256] = {0};
    int len = 0;    

    if( tcp != NULL)
    {
        TxtMessageAssembler* assembler = m_map.value(tcp);
        //如果读出的数据长度不为0
        while( (len = tcp->read(buf, sizeof(buf) / sizeof(buf[0]))) >0 )
        {
            if( assembler != NULL )
            {
                QSharedPointer<TextMessage> ptm = NULL;

                assembler->prepare(buf, len);

                while( (ptm = assembler->assembler()) != NULL )
                {
                    if( m_handler != NULL )
                    {
                        m_handler->handle(*tcp, *ptm);
                    }
                }
            }
        }
    }
}

void ServerDemo::onBytesWritten(qint64 bytes)
{
    (void)bytes;
}

void ServerDemo::setHandler(TxtMsgHandler* handler)
{
    m_handler = handler;
}


ServerDemo::~ServerDemo()
{
    //得到服务器的所有子类
    const QObjectList& list = m_server.children();

    for(int i=0; i<list.length(); i++)
    {
        QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(list[i]);

        if( tcp != NULL)
        {
            tcp->close();
        }
    }

    //析构时释放所有的TxtMessageAssembler
    const QList<TxtMessageAssembler*>& al = m_map.values();

    for(int i=0; i<al.length(); i++)
    {
        delete al.at(i);
    }
}
