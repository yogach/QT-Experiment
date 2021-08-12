#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QSemaphore>

const int SIZE = 5;
unsigned char g_buff[SIZE] = {0};
QSemaphore g_sem_free(SIZE);
QSemaphore g_sem_used(0);

class Producer : public QThread
{
protected:
    void run()
    {
        while(true)
        {
            int value = qrand() % 256;

            g_sem_free.acquire(); //获取空闲资源

            for(int i=0; i<SIZE; i++)
            {
                if( g_buff[i] == 0 )
                {
                    g_buff[i] = value;

                    qDebug() << objectName() << " generate: {" << i << ", " << value << "}";

                    break;
                }
            }

            g_sem_used.release(); //当资源填充完成后 释放已使用信号量的资源

            sleep(2);
        }
    }

};

class Customer : public QThread
{
protected:
    void run()
    {
        while(true)
        {
            g_sem_used.acquire(); //获取已使用资源 假设资源没有准备好 则会一直阻塞

            for(int i=0; i<SIZE; i++)
            {
                if( g_buff[i] )
                {
                    int value = g_buff[i];

                    g_buff[i] = 0;

                    qDebug() << objectName() << " consume: {" << i << ", " << value << "}";

                    break;
                }
            }

            g_sem_free.release();

            sleep(1);

         }
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer p1;
    Producer p2;
    Producer p3;

    p1.setObjectName("p1");
    p2.setObjectName("p2");
    p3.setObjectName("p3");

    Customer c1;
    Customer c2;

    c1.setObjectName("c1");
    c2.setObjectName("c2");

    p1.start();
    p2.start();
    p3.start();

    c1.start();
    c2.start();
    
    return a.exec();
}
