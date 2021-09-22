#include "ServerHandler.h"
#include <QDebug>

ServerHandler::ServerHandler()
{

}


void ServerHandler::handle(QTcpSocket& obj, TextMessage& msg)
{
    qDebug() << &obj;
    qDebug() << msg.type();
    qDebug() << msg.data();

    if( msg.type() == "CONN" )
    {

    }
    else if( msg.type() == "DSCN")
    {

    }

}
