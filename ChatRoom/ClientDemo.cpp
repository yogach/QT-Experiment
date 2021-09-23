#include "ClientDemo.h"
#include <QDebug>
#include <QHostAddress>


ClientDemo::ClientDemo(QObject *parent) : QObject(parent), m_handler(NULL)
{
    connect(&m_client, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(&m_client, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(&m_client, SIGNAL(readyRead()), this, SLOT(onDataReady()));
    connect(&m_client, SIGNAL(bytesWritten(qint64)), this, SLOT(onByteWriteen(qint64)));
}

void ClientDemo::onConnected()
{
    if( m_handler != NULL )
    {
       TextMessage msg("CONN", m_client.peerAddress().toString() + ":" + QString::number(m_client.peerPort()));

       m_handler->handle(m_client, msg);
    }
}
void ClientDemo::onDisconnected()
{
    m_assembler.reset(); //断开连接后 清除m_assembler内容

    if( m_handler != NULL )
    {
       TextMessage msg("DSCN", "");

       m_handler->handle(m_client, msg);
    }

}

void ClientDemo::onDataReady()
{
    char buf[256] = {0};
    int len = 0;

    //如果读出的数据长度不为0
    while( (len = m_client.read(buf, sizeof(buf) / sizeof(buf[0]))) >0 )
    {
       QSharedPointer<TextMessage> ptm = NULL;

       m_assembler.prepare(buf, len);

       while( (ptm = m_assembler.assembler()) != NULL )
       {
           if( m_handler != NULL)
           {
               m_handler->handle(m_client, *ptm);
           }
       }
    }
}

void ClientDemo::onByteWriteen(qint64 bytes)
{
    (void)bytes;
}

bool ClientDemo::connectTo(QString ip, int port)
{
    m_client.connectToHost(ip, port);

    return m_client.waitForConnected(); // 等待连接成功
}

qint64 ClientDemo::send(TextMessage& msg)
{
    QByteArray ba = msg.serialize();

    return m_client.write(ba.data(), ba.length());
}

qint64 ClientDemo::available()
{
    return m_client.bytesAvailable();
}

bool ClientDemo::isVaild()
{
    return m_client.isValid();
}

void ClientDemo::close()
{
    m_client.close();
}

void ClientDemo::setHandler(TxtMsgHandler* handler)
{
    m_handler = handler;
}
