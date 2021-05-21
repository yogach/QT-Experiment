#include "Widget.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDebug>
#include <QList>
#include <QUrl>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
   setAcceptDrops(true); //设置能接收拖拽事件
}

Widget::~Widget()
{

}

void Widget::dragEnterEvent(QDragEnterEvent *e)
{
    if( e->mimeData()->hasUrls() )
    {
       e->acceptProposedAction(); //接受这个拖拽事件
    }
    else
    {
       e->ignore(); //忽略此事件 交给父类处理
    }

}

void Widget::dropEvent(QDropEvent *e)
{

    if( e->mimeData()->hasUrls() )
    {
        //获取并打印url
        QList<QUrl> list = e->mimeData()->urls();

        for(int i=0; i<list.count(); i++)
        {
            qDebug() << list[i].toLocalFile();
        }
    }
    else
    {
       e->ignore(); //忽略此事件 交给父类处理
    }
}
