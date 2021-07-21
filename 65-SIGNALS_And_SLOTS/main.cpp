#include <QtCore/QCoreApplication>
#include "RxClass.h"
#include "TestSignal.h"

void emit_signal(void)
{
    qDebug() << "void emit_signal(void)" << endl;

    TestSignal t;
    RxClass r;

    //设置对象名字
    t.setObjectName("t");
    r.setObjectName("r");

    QObject::connect(&t, SIGNAL(testSignal(int)), &r, SLOT(mySlot(int)));

    for(int i=0; i<3; i++)
    {
       t.send(i); //使用send函数发送信号
    }
}

void one_to_multi()
{
    qDebug() << "void one_to_multi(void)" << endl;

    TestSignal t;
    RxClass r1;
    RxClass r2;

    //设置对象名字
    t.setObjectName("t");
    r1.setObjectName("r1");
    r2.setObjectName("r2");

    QObject::connect(&t, SIGNAL(testSignal(int)), &r1, SLOT(mySlot(int)));
    QObject::connect(&t, SIGNAL(testSignal(int)), &r2, SLOT(mySlot(int)));

    t.send(100); //使用send函数发送信号
}

void multi_to_one()
{
    qDebug() << "void multi_to_one(void)" << endl;

    TestSignal t1;
    TestSignal t2;
    RxClass r;

    //设置对象名字
    t1.setObjectName("t1");
    t2.setObjectName("t2");
    r.setObjectName("r");

    QObject::connect(&t1, SIGNAL(testSignal(int)), &r, SLOT(mySlot(int)));
    QObject::connect(&t2, SIGNAL(testSignal(int)), &r, SLOT(mySlot(int)));

    t1.send(101); //使用send函数发送信号
    t2.send(102);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    //emit_signal();
    //one_to_multi();
    multi_to_one();

    return a.exec();
}
