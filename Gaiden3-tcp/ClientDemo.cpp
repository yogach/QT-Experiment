#include "ClientDemo.h"
#include <QDebug>
#include <QHostAddress>

ClientDemo::ClientDemo(QObject *parent) : QObject(parent)
{

}

void ClientDemo::onConnected()
{
    qDebug() << "onConnected()" ;
    qDebug() << "Local Address:" << m_client.localAddress();
    qDebug() << "Local Port:" << m_client.localPort();
}
void ClientDemo::onDisconnected()
{
    qDebug() << "onDisconnected";
}

void ClientDemo::onDataReady()
{
    char buf[256] = {0};

    qDebug() << "onDataReady:" << m_client.read(buf, sizeof(buf) / sizeof(buf[0]) );
    qDebug() << "Data :" << buf;
}

void ClientDemo::onByteWriteen(qint64 bytes)
{
    qDebug() << "onBytesWritten:" << bytes;
}

void ClientDemo::connectTo(QString ip, int port)
{
    m_client.connectToHost(ip, port);
}

qint64 ClientDemo::send(const char* data, int len)
{
    return m_client.write(data, len);
}

qint64 ClientDemo::available()
{
    return m_client.bytesAvailable();
}

void ClientDemo::close()
{
    m_client.close();
}
