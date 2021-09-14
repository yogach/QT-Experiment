#ifndef TEXMESSAGE_H
#define TEXMESSAGE_H

#include <QObject>
#include <QByteArray>

class TextMessage : public QObject
{
    Q_OBJECT

    QString m_type;
    QString m_data;

public:
    explicit TextMessage(QObject *parent = nullptr);
    TextMessage(QString type, QString data, QObject *parent = nullptr);

    QString type();
    int length();
    QString data();

    QByteArray serialize();
    bool unserialize(QByteArray ba);

signals:

public slots:
};

#endif // TEXMESSAGE_H
