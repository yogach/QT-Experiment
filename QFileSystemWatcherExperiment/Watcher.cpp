#include "Watcher.h"

#include <QDebug>

Watcher::Watcher(QObject *parent) :
    QObject(parent)
{
    connect(&m_watcher, SIGNAL(fileChanged(QString)), this, SLOT(StatusChange(QString)));
    connect(&m_watcher, SIGNAL(directoryChanged(QString)), this, SLOT(StatusChange(QString)));
}


void Watcher::StatusChange(const QString& path)
{
    qDebug() << path << "is changed!";
}

void Watcher::addPath(QString path)
{
     m_watcher.addPath(path);
}




