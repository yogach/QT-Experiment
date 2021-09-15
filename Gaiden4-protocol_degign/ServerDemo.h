#ifndef SERVERDEMO_H
#define SERVERDEMO_H

#include <QObject>
#include <QTcpServer>
#include "TextMessage.h"
#include "TxtMessageAssembler.h"
#include "TxtMsgHandler.h"

class ServerDemo : public QObject
{
    Q_OBJECT

    QTcpServer m_server;
    TxtMessageAssembler m_assembler;
    TxtMsgHandler* m_handler;

public:
    explicit ServerDemo(QObject *parent = nullptr);
    bool start(int port);
    void stop();
    void setHandler(TxtMsgHandler* handler);
    ~ServerDemo();


protected slots:
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onDataReady();
    void onBytesWritten(qint64 bytes);

};

#endif // SERVERDEMO_H
