#include "Widget.h"
#include <QDir>
#include <QModelIndex>
#include <QByteArray>
#include <QBuffer>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_edit.setParent(this);
    m_edit.move(10, 10);
    m_edit.resize(500, 300);

    connect(&m_fsm, SIGNAL(directoryLoaded(QString)), this, SLOT(onDirectoryLoaded(QString)));

    m_fsm.setRootPath(QDir::currentPath()); //设置文件系统模型的根目录
}


void Widget::onDirectoryLoaded(const QString& path)
{
    QModelIndex root = m_fsm.index(path);
    QByteArray array;
    QBuffer buffer(&array);

    if( buffer.open(QIODevice::WriteOnly) )
    {
        QTextStream out(&buffer);

        out << m_fsm.isDir(root) << endl; //输出当前root是否为文件夹

        out << m_fsm.data(root).toString() << endl; //输出根目录的数据
        out << root.data().toString() << endl; //输出根目录的数据

        out << &m_fsm << endl;  //输出模型的地址
        out << root.model() << endl;

        out << m_fsm.filePath(root) << endl; //输出root的绝对路径
        out << m_fsm.fileName(root) << endl;

        out << endl;

        //得到root的子节点
        for(int i=0; i<m_fsm.rowCount(root); i++)
        {
            QModelIndex ci = m_fsm.index(i, 0, root); //得到0列的数据

            out << ci.data().toString() << endl;
        }

        out.flush();
        buffer.close();

    }

    if( buffer.open(QIODevice::ReadOnly) )
    {
        QTextStream in(&buffer);

        m_edit.insertPlainText(in.readAll());

        buffer.close();

    }

}

Widget::~Widget()
{
    
}
