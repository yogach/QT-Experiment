#include <QCoreApplication>
#include "TextMessage.h"
#include "TxtMessageAssembler.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TextMessage tm("ABcdef", "1234567890");
    QString s = tm.serialize();

    qDebug() << s;

    TxtMessageAssembler as;
    QSharedPointer<TextMessage> pt;

    pt = as.assembler(s.toStdString().c_str(), s.length());

    if( pt != NULL )
    {
        qDebug() << "assemble successfully";
        qDebug() << pt->type();
        qDebug() << pt->length();
        qDebug() << pt->data();
    }


    return a.exec();
}
