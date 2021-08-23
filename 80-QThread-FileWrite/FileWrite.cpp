#include "FileWrite.h"
#include <QDebug>

FileWrite::FileWrite(QString file, QObject *parent) :
    QObject(parent), m_file(file)
{
    connect(this, SIGNAL(doWrite(QString)), this, SLOT(writeSlot(QString)));
    connect(this, SIGNAL(doClose()), this, SLOT(closeSlot()));

    moveToThread(&m_worker); //修改线程依附性 调整槽函数的运行线程

    m_worker.start();

}

void FileWrite::Worker::run()
{
    qDebug() << "void FileWriter::Worker::run() - begin: tid = " << currentThreadId();
    exec(); //线程函数中开启事件循环 用于处理槽函数
    qDebug() << "void FileWriter::Worker::run() - end";
}

bool FileWrite::open()
{
    return m_file.open(QIODevice::ReadWrite | QIODevice::Text);
}

void FileWrite::write(QString text)
{
    qDebug() << "void FileWriter::write(QString text) tid = " << QThread::currentThreadId();
    emit doWrite(text); //发送写指令
}

void FileWrite::close()
{
    qDebug() << "void FileWriter::close() tid = " << QThread::currentThreadId();
    emit doClose();
}

FileWrite::~FileWrite()
{
    m_worker.quit(); //在对象的析构函数中结束线程的事件循环
}

void FileWrite::writeSlot(QString text)
{
     qDebug() << "void FileWriter::writeSlot(QString text) tid = " << QThread::currentThreadId();
     m_file.write(text.toAscii());
     m_file.flush(); //将文件写入硬盘
}

void FileWrite::closeSlot()
{
     qDebug() << "void FileWriter::closeSlot() tid = " << QThread::currentThreadId();
     m_file.close();
}
