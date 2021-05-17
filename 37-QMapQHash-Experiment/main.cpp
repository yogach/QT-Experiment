#include <QtCore/QCoreApplication>
#include <QMap>
#include <QDebug>
#include <QMapIterator>
#include <QHash>

void QMapTest()
{
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

}

void QHashTest()
{
    QHash<QString, int> hash;

    hash.insert("key 2", 2);
    hash.insert("key 0", 0);
    hash.insert("key 1", 1);

    QList<QString> kList = hash.keys();

    for(int i=0; i< kList.count(); i++)
    {
        qDebug() << kList[i];
    }

    QList<int> vList = hash.values();

    for(int i=0; i< kList.count(); i++)
    {
        qDebug() << vList[i];
    }

    hash["key 4"] = 4;

    QHash<QString, int>::const_iterator i;

    for(i=hash.constBegin(); i!=hash.constEnd() ; i++)
    {
      qDebug() << i.key() << ":" << i.value();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QMapTest();

    qDebug() << endl;

    QHashTest();

    return a.exec();
}
