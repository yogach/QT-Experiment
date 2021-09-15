#include <QCoreApplication>
#include "TextMessage.h"
#include "TxtMessageAssembler.h"
#include <QDebug>
#include "ServerDemo.h"
#include "ClientDemo.h"
#include "TxtMsgHandler.h"

class Handler : public TxtMsgHandler
{
  public:
    void handle(QTcpSocket& socket, TextMessage& msg)
    {
        qDebug() << &socket;
        qDebug() << msg.type();
        qDebug() << msg.length();
        qDebug() << msg.data();
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TextMessage tm("ABcdef", "汉字测试123");
    Handler handler;

    ServerDemo server;
    ClientDemo client;

    server.setHandler(&handler);
    server.start(8890);

    client.setHandler(&handler);
    client.connectTo("127.0.0.1", 8890);
    client.send(tm);

    return a.exec();
}
