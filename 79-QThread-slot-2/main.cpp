#include <QtCore/QCoreApplication>
#include "TestThread.h"
#include "MyObject.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId(); //打印主线程id

    //在主线程中创建的对象默认依附于主线程 槽函数也会在主线程中执行
    TestThread t;
    MyObject m;

    QObject::connect(&t, SIGNAL(started()), &m, SLOT(getStarted()));
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()));

    m.moveToThread(&t); //调整m对象依附与t线程 m中的槽函数就会在t线程中执行
    t.moveToThread(&t);

    t.start();

    t.wait(8 * 1000); //等待t线程退出 如果8秒后还在运行 则继续主线程的运行

    t.quit(); //退出t线程中的exec事件循环
    
    return a.exec();
}
