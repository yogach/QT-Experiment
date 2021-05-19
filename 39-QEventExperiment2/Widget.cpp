#include "Widget.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

Widget::Widget(QWidget *parent): QWidget(parent) , myEdit(this)
{
    myEdit.installEventFilter(this); //安装事件过滤器
}

Widget::~Widget()
{
    
}

bool Widget::event(QEvent* e)
{
    //此函数会接收所有QWidget对象收到的事件 之后再转发给各种具体的事件
    //我们对收到的事件做一个过滤
    if( e->type() == QEvent::KeyPress)
      qDebug() << "Widget::event";

    return QWidget::event(e);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    //在主窗口按键后会打印以下内容
    qDebug() << "Widget::keyPressEvent";

    QWidget::keyPressEvent(e);
}

//事件过滤器 事件会先传到过滤器中 再传到event处理函数中
bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    bool ret = true; //true--代表事件被过滤

    //过滤掉myEdit中的按键事件
    if( (obj == &myEdit) && (e->type() == QEvent::KeyPress) )
    {
         qDebug() << "Widget::eventFilter";

         QKeyEvent* evt = dynamic_cast<QKeyEvent*>(e);

         //当输入的数据为数字时，不过滤此事件
         switch(evt->key())
         {
         case Qt::Key_0:
         case Qt::Key_1:
         case Qt::Key_2:
         case Qt::Key_3:
         case Qt::Key_4:
         case Qt::Key_5:
         case Qt::Key_6:
         case Qt::Key_7:
         case Qt::Key_8:
         case Qt::Key_9:
             ret = false;
             break;
         default:
             break;
         }
    }
    else
    {
       ret = QWidget::eventFilter(obj, e);
    }

    return ret;
}
