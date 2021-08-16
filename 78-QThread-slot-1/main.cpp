#include <QtCore/QCoreApplication>
#include "MyObject.h"
#include "TestThread.h"
#include <QDebug>
#include <QThread>

/*
  从运行结果来看，所有的槽函数都会在主线程中执行
  */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestThread t;
    MyObject m;

    QObject::connect(&t, SIGNAL(started()), &m, SLOT(getStarted()));
    QObject::connect(&t, SIGNAL(finished()), &m, SLOT(getFinished()));
    QObject::connect(&t, SIGNAL(terminated()), &m, SLOT(getTerminated()));

    t.start();
    
    return a.exec();
}
