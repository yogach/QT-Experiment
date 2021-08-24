#include "AsyncThread.h"
#include <QDebug>


AsyncThread::AsyncThread(QObject *parent) :
    QThread(parent)
{
}

void AsyncThread::run()
{
    qDebug() << "void AsyncThread::run() tid = " << currentThreadId();

    for(int i=0; i<3; i++)
    {
        qDebug() << "void AsyncThread::run() i = " << i;

        sleep(1);
    }

    qDebug() << "void AsyncThread::run() end";

    deleteLater(); //调用此函数通知qt销毁此对象
}

AsyncThread* AsyncThread::NewInstance(QObject* parent)
{
    return new AsyncThread(parent);
}

AsyncThread::~AsyncThread()
{
   qDebug() << "AsyncThread::~AsyncThread() destroy thread object";
}
