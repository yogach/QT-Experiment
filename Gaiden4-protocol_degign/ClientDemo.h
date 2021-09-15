#ifndef CLIENTDEMO_H
#define CLIENTDEMO_H

#include <QObject>
#include <QTcpSocket>
#include "TextMessage.h"
#include "TxtMessageAssembler.h"
#include "TxtMsgHandler.h"


class ClientDemo : public QObject
{
    Q_OBJECT

    QTcpSocket m_client;

    TxtMessageAssembler m_assembler;
    TxtMsgHandler* m_handler;
protected slots:
    void onConnected();
    void onDisconnected();
    void onDataReady();
    void onByteWriteen(qint64 bytes);


public:
    explicit ClientDemo(QObject *parent = nullptr);
    bool connectTo(QString ip, int port);
    qint64 send(TextMessage& msg);
    qint64 available();
    void close();
    void setHandler(TxtMsgHandler* handler);

};

#endif // CLIENTDEMO_H
