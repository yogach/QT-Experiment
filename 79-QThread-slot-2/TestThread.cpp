#include "TestThread.h"
#include <QDebug>

TestThread::TestThread(QObject *parent) :
    QThread(parent)
{
    connect(this, SIGNAL(testSignal()), this, SLOT(testSlot()));
}


void TestThread::run()
{
    qDebug() << "void TestThread::run() -- begin tid = " << currentThreadId();

    for(int i=0; i<5; i++)
    {
        qDebug() << "void TestThread::run() i = " << i;

        sleep(1);
    }

    emit testSignal(); //发送信号

    exec(); //子线程进入事件循环 只有开启了事件循环 依附于本线程的槽函数才会执行

    qDebug() << "void TestThread::run() -- end ";
}

void TestThread::testSlot()
{
   qDebug() << "void TestThread::testSlot() tid = " << currentThreadId();
}
