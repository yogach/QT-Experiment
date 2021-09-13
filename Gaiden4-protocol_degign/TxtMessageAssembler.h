#ifndef TXTMESSAGEASSEMBLER_H
#define TXTMESSAGEASSEMBLER_H

#include <QObject>
#include <QQueue>
#include <QSharedPointer>
#include "TextMessage.h"

class TxtMessageAssembler : public QObject
{
    Q_OBJECT

    QQueue<char> m_queue;
    QString m_type;
    int m_length;
    QString m_date;

    void clear();
    QString fetch(int n);
    bool makeTypeAndLength();
    TextMessage* makeMessage();

public:
    explicit TxtMessageAssembler(QObject *parent = nullptr);
    void prepare(const char* data, int len);
    QSharedPointer<TextMessage> assembler();
    QSharedPointer<TextMessage> assembler(const char* data, int len);
    void reset();

};

#endif // TXTMESSAGEASSEMBLER_H
