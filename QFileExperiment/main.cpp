#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QDateTime>
#include <QTemporaryFile>

void write(QString f)
{
    QFile file(f);  //此处需要打开文件

    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        file.write("Test QFile\n");
        file.write("abc\n");
        file.close();

    }

}


void read(QString f)
{
    QFile file(f);

    if( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QByteArray ba = file.readAll();
        QString s(ba);

        qDebug() << s;

        file.close();
    }

}

void info(QString f)
{
    QFile file(f);
    QFileInfo info(file);

    qDebug() << info.exists();
    qDebug() << info.isFile();
    qDebug() << info.isReadable();
    qDebug() << info.isWritable();
    qDebug() << info.created();
    qDebug() << info.lastRead();
    qDebug() << info.lastModified();
    qDebug() << info.path();
    qDebug() << info.fileName();
    qDebug() << info.suffix();
    qDebug() << info.size();
}

void temporary()
{
    QTemporaryFile tempfile; //临时文件不需要指定路径

    if( tempfile.open() ) //临时文件默认的读写方式为可读可写
    {
        tempfile.write(" Test tempfile");
        tempfile.close();
    }

    QFileInfo info(tempfile);

    qDebug() << info.isFile();
    qDebug() << info.path();
    qDebug() << info.fileName();

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
   // write("/home/delphi/1.txt");
   // read("/home/delphi/1.txt");
  //  info("/home/delphi/1.txt");
    temporary();

    return a.exec();
}
