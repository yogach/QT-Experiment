#include "MyObject.h"
#include <QDebug>
#include <QThread>

MyObject::MyObject(QObject *parent) :
    QObject(parent)
{
}


void MyObject::getStarted()
{
   qDebug() << "void MyObject::getStarted() tid = " << QThread::currentThreadId();
}

void MyObject::testSlot()
{
   qDebug() << "void MyObject::testSlot() tid = " << QThread::currentThreadId();
}
