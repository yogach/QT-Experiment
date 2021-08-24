#include "SyncThread.h"
#include <QDebug>

SyncThread::SyncThread(QObject *parent) :
    QThread(parent)
{
}

void SyncThread::run()
{
   qDebug() << "void SyncThread::run() tid = " << currentThreadId();

   for(int i=0; i<3; i++)
   {
       qDebug() << "void SyncThread::run() i = " << i;

       sleep(1);
   }

   qDebug() << "void SyncThread::run() end";

}

SyncThread::~SyncThread()
{
    wait(); //在析构函数中等待线程结束后在释放对象

    qDebug() << "SyncThread::~SyncThread() destroy thread object";
}
