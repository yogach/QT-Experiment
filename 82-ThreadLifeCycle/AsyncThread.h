#ifndef ASYNCTHREAD_H
#define ASYNCTHREAD_H

#include <QThread>

class AsyncThread : public QThread
{
    Q_OBJECT
protected:
    void run();

    //需要保证是堆对象 且不能主动使用delete释放资源
    explicit AsyncThread(QObject *parent = 0);
    ~AsyncThread();

public:
    static AsyncThread* NewInstance(QObject* parent = 0);
    
};

#endif // ASYNCTHREAD_H
