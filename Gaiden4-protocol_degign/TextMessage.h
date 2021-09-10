#ifndef TEXMESSAGE_H
#define TEXMESSAGE_H

#include <QObject>

class TextMessage : public QObject
{
    Q_OBJECT

    QString m_type;
    QString m_date;

public:
    explicit TextMessage(QObject *parent = nullptr);
    TextMessage(QString type, QString data, QObject *parent = nullptr);

    QString type();
    int length();
    QString data();

    QString serialize();
    bool unserialize(QString s);

signals:

public slots:
};

#endif // TEXMESSAGE_H
