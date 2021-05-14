#include <QtCore/QCoreApplication>
#include <QMap>
#include <QDebug>
#include <QMapIterator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QMap<QString, int> map;

    map.insert("key 2", 2);
    map.insert("key 0", 0);
    map.insert("key 1", 1);

    QList<QString> kList = map.keys();

    for(int i=0; i< kList.count(); i++)
    {
        qDebug() << kList[i];
    }

    QList<int> vList = map.values();

    for(int i=0; i< kList.count(); i++)
    {
        qDebug() << vList[i];
    }

    QMapIterator<QString, int> it(map);

    while( it.hasNext() )
    {
        it.next();
        qDebug() << it.key() << ":" << it.value();
    }


    return a.exec();
}
