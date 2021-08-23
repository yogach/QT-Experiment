#include <QtCore/QCoreApplication>
#include "FileWrite.h"
#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    FileWrite writer("/home/delphi/2.txt");

    if( writer.open() )
    {
        writer.write("D.T.Software\r\n");
        writer.write("中文测试\r\n");
        writer.write("狄泰软件\r\n");
        writer.close();
    }
    
    return a.exec();
}
