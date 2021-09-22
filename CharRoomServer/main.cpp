#include <QCoreApplication>
#include "ServerDemo.h"
#include "ServerHandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerDemo server;
    ServerHandler serverHandler;

    server.setHandler(&serverHandler);
    server.start(8890);

    return a.exec();
}
