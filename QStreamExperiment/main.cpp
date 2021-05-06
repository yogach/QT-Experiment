#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>

void text_stream_test(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QTextStream out(&file);

        out << QString("Test") << endl;
        out << QString("QTextStream") << endl;
        out << 5 << '*' << 6 << '=' << 5 * 6 << endl;

        file.close();
    }

     if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
     {
         QTextStream in(&file);

         while( !in.atEnd() )
         {
            QString line = in.readLine();

            qDebug() << line;
         }


         file.close();
     }
}

void data_stream_test(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::WriteOnly ) ) //使用datastream时就不需要指定读取类型为TEXT
    {
        QDataStream out(&file);

        out << QString("Test") ;
        out << QString("QDataStream") ;
        out << 3.14;

        file.close();
    }

     if( file.open(QIODevice::ReadOnly ) )
     {
         QDataStream in(&file);

         QString text1 = "";
         QString text2 = "";
         double value = 0;

         in >> text1;
         in >> text2;
         in >> value;

         file.close();

         qDebug() << text1;
         qDebug() << text2;
         qDebug() << value;
     }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    text_stream_test("/home/delphi/text.txt");
    qDebug() << endl;

    data_stream_test("/home/delphi/data.dat");

    return a.exec();
}
