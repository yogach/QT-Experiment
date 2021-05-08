#include <QtCore/QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QFileInfoList>

void test_dir()
{
    const char* PATH = "/home/delphi/Test/QT-Experiment";
    QDir dir(PATH);

    //使用QDir对象进行文件夹操作
    if( !dir.exists() )
    {
        dir.mkdir(PATH);
    }

    if( dir.exists() )
    {
        dir.cd(PATH);

        QStringList list = dir.entryList(); //使用entryList获取文件名

        for(int i=0; i<list.count(); i++)
        {
            qDebug() << list[i];
        }
    }
}

unsigned int calculator_size(QString path)
{
    QFileInfo info(path);
    unsigned char ret = 0;

    if( info.isFile() )
    {
       ret = info.size(); //获取文件大小
    }
    else if( info.isDir() )
    {
        QDir dir(path);
        QFileInfoList list = dir.entryInfoList();

        for(int i=0; i<list.count(); i++)
        {

            if( ( list[i].fileName() != "." ) && ( list[i].fileName() != "..") )
            {
                //qDebug() << list[i].path();
                ret += calculator_size( list[i].absoluteFilePath() );
            }
        }
    }

    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);  

    test_dir();

    qDebug() << calculator_size("/home/delphi/Test/QT-Experiment");
    
    return a.exec();
}
