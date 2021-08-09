#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>

class Sample : public QThread
{
protected:
    volatile bool m_toStop;

    void run()
    {
        qDebug() << objectName() << " : begin";

        int* p = new int[10000]; //分配10000个int变量

        for(int i=0; (m_toStop != true) && (i<10); i++)
        {
            qDebug() << objectName() << " : " << i;

            p[i] = i;

            msleep(500);
        }

        delete[] p;

        qDebug() << objectName() << " : end";
    }

public:
    Sample()
    {
      m_toStop = false;
    }

    void stop()
    {
      m_toStop = true;
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sample s;

    qDebug() << "main begin";


    s.setObjectName("t");
    s.start();

    sleep(3);

    s.stop();
    //s.terminate(); //直接调用terminate会导致线程强制结束 导致内存泄漏


    qDebug() << "main end";

    
    return a.exec();
}
