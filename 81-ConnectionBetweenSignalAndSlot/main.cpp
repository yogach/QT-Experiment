#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QThread>
#include "TestThread.h"
#include "MyObject.h"

//直接连接 相当于在发射信号的位置直接调用对应槽函数
void direct_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::DirectConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

//信号发送至目标线程执行 由目标线程处理 当前线程继续向下执行
void queued_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::QueuedConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

//信号发送至目标线程执行 由目标线程处理 当前线程等待槽函数返回
void blocking_queued_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::BlockingQueuedConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

//qt中槽函数的默认连接方式
void auto_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()));

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

//保证槽函数和信号只连接一次
void unique_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::UniqueConnection);
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::UniqueConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    qDebug() << "main() tid = " << QThread::currentThreadId();

    //direct_connection();
    //queued_connection();
    //blocking_queued_connection();
    //auto_connection();
    unique_connection();

    return a.exec();
}
