#include <QtCore/QCoreApplication>
#include <QBuffer>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>

void write_buffer(int type, QBuffer& buffer )
{
    //缓冲区可直接进行打开操作
    if( buffer.open(QIODevice::WriteOnly) )
    {
        QDataStream out(&buffer);

        out << type;

        if( type == 0 )
        {
            out << QString("Text Buffer");
            out << QString("3.1415");
        }
        else if( type == 1 )
        {
            out << 3;
            out << 1415;
        }
        else if( type == 2 )
        {
            out << 3.1415;
        }

        buffer.close();
    }
}

void read_buffer(QBuffer& buffer )
{
    if( buffer.open(QIODevice::ReadOnly) )
    {
        QDataStream in(&buffer);

        int type = -1;

        in >> type;

        if( type == 0 )
        {
            QString dt = "";
            QString pi = "";

            in >> dt;
            in >> pi;

            qDebug() << dt;
            qDebug() << pi;
        }
        else if( type == 1 )
        {
            int a = 0;
            int b = 0;

            in >> a;
            in >> b;

            qDebug() << a;
            qDebug() << b;
        }
        else if( type == 2 )
        {
            double pi = 0;

            in >> pi;

            qDebug() << pi;
        }

        buffer.close();

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QByteArray array;
    QBuffer buffer(&array);

    write_buffer(1, buffer);
    read_buffer(buffer);
    
    return a.exec();
}
