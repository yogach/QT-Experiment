#include <QtCore/QCoreApplication>
#include "AnotherThread.h"
#include <QDebug>
#include <QThread>

void test()
{
   AnotherThread t;

   t.start();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    qDebug() << "main() tid = " << QThread::currentThreadId();

    test();

    return a.exec();
}
