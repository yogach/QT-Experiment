#include "UpdateThread.h"
#include <QApplication>
#include "StringEvent.h"

UpdateThread::UpdateThread(QObject *parent) :
    QThread(parent)
{
}

void UpdateThread::run()
{
    //在子线程中发送自定义事件 然后主线程中接收后进行ui界面的更新
    QApplication::postEvent(parent(), new StringEvent("Begin")); //接收对象是子线程的父类

    for(int i=0; i<10; i++)
    {
        QApplication::postEvent(parent(), new StringEvent(QString::number(i)));
        sleep(1);
    }

    QApplication::postEvent(parent(), new StringEvent("End"));
}

