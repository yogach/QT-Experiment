#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QMutex>



static QString g_store;
static QMutex g_mutex;

class Producer : public QThread
{
protected:
    void run()
    {
        int count = 0;

        while(1)
        {
            //在对临界资源进行操作之前 需要先获取线程锁
            g_mutex.lock();

            g_store.append(QString::number((count++) % 10));

            qDebug() << objectName() << " : " + g_store;

            g_mutex.unlock(); //操作完成之后需要释放这个锁

            msleep(1);
        }


    }

};

class Customer : public QThread
{
protected:
    void run()
    {
        while(1)
        {
            g_mutex.lock();

            if( g_store != "")
            {
               g_store.remove(0, 1);
                qDebug() << objectName() << " : " + g_store;
            }
            g_mutex.unlock();

            msleep(1);
        }

    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer p;
    Customer c;

    p.setObjectName("Producer");
    c.setObjectName("Customer");

    p.start();
    c.start();
    
    return a.exec();
}
