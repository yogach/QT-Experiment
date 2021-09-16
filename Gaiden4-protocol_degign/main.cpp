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
    TextMessage tm1("aaaaaa", "这是汉字测试111111222");
    Handler handler;

    ServerDemo server;
    ClientDemo client;
    ClientDemo client1;

    server.setHandler(&handler);
    server.start(8890);

    client.setHandler(&handler);
    client.connectTo("127.0.0.1", 8890);
    client.send(tm);

    client1.setHandler(&handler);
    client1.connectTo("127.0.0.1", 8890);
    client1.send(tm1);

    return a.exec();
}
