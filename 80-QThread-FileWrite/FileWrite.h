#ifndef FILEWRITE_H
#define FILEWRITE_H

#include <QThread>
#include <QFile>
#include <QThread>

class FileWrite : public QObject
{
    Q_OBJECT

    class Worker : public QThread
    {
        void run();
    };

    QFile m_file;
    Worker m_worker;

public:
    explicit FileWrite(QString file, QObject *parent = 0);
    bool open();
    void write(QString text);
    void close();
    ~FileWrite();

signals:
    void doWrite(QString text);
    void doClose();

protected slots:
    void writeSlot(QString text);
    void closeSlot();
};

#endif // FILEWRITE_H
