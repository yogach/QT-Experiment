#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);
    
signals:
    
protected slots:
    void getStarted();
    void testSlot();
};

#endif // MYOBJECT_H
