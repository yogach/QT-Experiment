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
    qDebug() << "onNewConnection" ;
    QTcpSocket* tcp = m_server.nextPendingConnection(); //得到新连接上的客户端对象

    connect(tcp, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tcp, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(tcp, SIGNAL(readyRead()), this, SLOT(onDataReady()));
    connect(tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));

}

void ServerDemo::onConnected()
{
    QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(sender()); //得到信号的发送者

    if( tcp != NULL)
    {
        qDebug() << "onConnected()" ;
        qDebug() << "Local Address:" << tcp->localAddress();
        qDebug() << "Local Port:" << tcp->localPort();
    }

}

void ServerDemo::onDisconnected()
{

}

void ServerDemo::onDataReady()
{
    QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(sender()); //得到信号的发送者
    char buf[256] = {0};

    int len = 0;

    //如果读出的数据长度不为0
    while( (len = tcp->read(buf, sizeof(buf) / sizeof(buf[0]))) >0 )
    {
       QSharedPointer<TextMessage> ptm = m_assembler.assembler(buf, len);

       if( (ptm != NULL) && (m_handler != NULL))
       {
           m_handler->handle(*tcp, *ptm);
       }

       TextMessage r("fmsr", ptm->data());
       tcp->write(r.serialize().data(), r.serialize().length());
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
}
