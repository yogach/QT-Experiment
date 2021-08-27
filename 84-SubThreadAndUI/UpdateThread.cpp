#include "UpdateThread.h"

UpdateThread::UpdateThread(QObject *parent) :
    QThread(parent)
{
}

void UpdateThread::run()
{
    //在子线程中发送信号 然后主线程中接收后进行ui界面的更新

    emit updateUI("Begin");

    for(int i=0; i<10; i++)
    {
        emit updateUI(QString::number(i));

        sleep(1);
    }

    emit updateUI("End");
}

