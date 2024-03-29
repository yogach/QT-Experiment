#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>
#include "ClientDemo.h"
#include "ServerDemo.h"

void SyncClientDemo()
{
    QTcpSocket client;
    char buf[256] = {0};

    client.connectToHost("127.0.0.1", 8080);

    qDebug() << "Connected:" << client.waitForConnected(); //等待连接成功

    qDebug() << "Send Bytes:" << client.write("QT Socket client");

    qDebug() << "Send Status:" << client.waitForBytesWritten();

    qDebug() << "Data Available:" << client.waitForReadyRead();

    qDebug() << "Received Bytes:" << client.read(buf, sizeof(buf) / sizeof(buf[0]));

    qDebug() << "Received Data:" << buf;

    client.close();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
/*
    char buf[20] = "qt test tcp client";
    ClientDemo client;

    client.connectTo("172.16.112.219", 8080);

    client.send(buf, sizeof(buf) / sizeof(buf[0]));
*/

    ServerDemo server;

    server.start(8080);

    return a.exec();
}
