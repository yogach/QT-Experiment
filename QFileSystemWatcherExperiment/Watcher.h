#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QFileSystemWatcher>

class Watcher : public QObject
{
    Q_OBJECT

    QFileSystemWatcher m_watcher;

private slots:
    void StatusChange(const QString& path);

public:
    explicit Watcher(QObject *parent = 0);
    void addPath(QString path);
};

#endif // WATCHER_H
