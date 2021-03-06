#include <QtCore/QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QDebug>

QMutex g_mutex_1;
QMutex g_mutex_2;

//本程序会造成线程死锁
//原因时ta和tb会分别获取到mutex1和mutex2 造成无法程序无法运行 无法释放锁
//主要原因出在没有按照递增的顺序获取Mutex

class ThreadA : public QThread
{
protected:
    void run()
    {
        while(1)
        {
            g_mutex_1.lock();

            qDebug() << objectName() << "get lock1";

            g_mutex_2.lock();

            qDebug() << objectName() << "get lock2";


            qDebug() << objectName() << "run ...";

            g_mutex_2.unlock();
            g_mutex_1.unlock();

        }

    }

};

class ThreadB : public QThread
{
protected:
    void run()
    {
        while(1)
        {
            //原程序没有按照递增的顺序获取锁
            /*
            g_mutex_2.lock();

            qDebug() << objectName() << "get lock2";

            g_mutex_1.lock();

            qDebug() << objectName() << "get lock1";
            */

            g_mutex_1.lock();

            qDebug() << objectName() << "get lock1";

            g_mutex_2.lock();

            qDebug() << objectName() << "get lock2";

            qDebug() << objectName() << "run ...";

            g_mutex_2.unlock();
            g_mutex_1.unlock();

        }

    }

};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadA ta;
    ThreadB tb;

    ta.setObjectName("ta");
    tb.setObjectName("tb");

    ta.start();
    tb.start();
    
    return a.exec();
}
