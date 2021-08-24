#include <QtCore/QCoreApplication>
#include "MyThread.h"
#include <QDebug>
#include "SyncThread.h"
#include "AsyncThread.h"


void test()
{
    //在线程对象被销毁后 线程依然在运行 因为对象是分配在栈上的 所以会出现非法的内存操作
    MyThread m;

    m.start();
}

void sync()
{
    //在线程对象的析构函数中等待线程执行结束 适用于栈对象和堆对象 适用于运行时间短的任务
    SyncThread t;

    t.start();
}

void Async()
{
    //在线程对象的线程任务执行结束后 调用deleteLater()通知qt销魂此对象 适用于堆对象 适用于运行时间不确定的任务
    AsyncThread* t = AsyncThread::NewInstance();

    t->start();

    //不能主动释放资源
    //delete t;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //test();
    //sync();
    Async();
    
    return a.exec();
}
