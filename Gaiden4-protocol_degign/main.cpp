#include <QCoreApplication>
#include "TextMessage.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TextMessage tm("ABcdef", "1234567890");
    QString s = tm.serialize();

    qDebug() << s;

    TextMessage tmt;

    qDebug() << tmt.unserialize(s);

    qDebug() << tmt.type();
    qDebug() << tmt.length();
    qDebug() << tmt.data();

    return a.exec();
}
