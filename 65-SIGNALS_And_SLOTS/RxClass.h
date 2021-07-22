#ifndef RXCLASS_H
#define RXCLASS_H

#include <QObject>
#include <QDebug>

class RxClass : public QObject
{
    Q_OBJECT

protected slots:
    void mySlot(int v)
    {
        qDebug() << "void mySlot(int v)";
        qDebug() << "Sender:" << sender()->objectName();  //获取信号的发送者
        qDebug() << "Receiver:" << this->objectName();
        qDebug() << "value:" << v;
        qDebug() << endl;

    }

};

#endif // RXCLASS_H
