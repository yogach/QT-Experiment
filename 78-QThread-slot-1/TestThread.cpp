#include "TestThread.h"
#include <QDebug>

TestThread::TestThread(QObject *parent) :
    QThread(parent)
{
    connect(this, SIGNAL(testSignal()), this, SLOT(testSlot()));
}


void TestThread::run()
{
    qDebug() << "void TestThread::run() -- begin tid = " << currentThreadId(); //打印当前线程id

    for(int i=0; i<10; i++)
    {
        qDebug() << "void TestThread::run() i = " << i;

        sleep(1);
    }

    emit testSignal(); //发送信号


    qDebug() << "void TestThread::run() -- end " ;
}

void TestThread::testSlot()
{
    qDebug() << "void TestThread::testSlot() tid = " << currentThreadId();
}
