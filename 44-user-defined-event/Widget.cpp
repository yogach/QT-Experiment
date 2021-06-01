#include "Widget.h"
#include "StringEvent.h"
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    m_edit.setParent(this);

    m_edit.installEventFilter(this); //安装事件过滤器
}



Widget::~Widget()
{
    
}

//这个event会接收整个widget的鼠标双击事件
bool Widget::event(QEvent *evt)
{
    if( evt->type() == QMouseEvent::MouseButtonDblClick)
    {
       qDebug() << "event: Before sentEvent";

       StringEvent e("test user-define event");

       QApplication::sendEvent(&m_edit, &e); //接收到之后发送一个自定义事件

       qDebug() << "event: After sentEvent";
    }

    return QWidget::event(evt);
}

//使用事件过滤器的方式接收自定义事件
bool Widget::eventFilter(QObject *obj, QEvent *evt)
{
    if( (obj == &m_edit) && (evt->type() == StringEvent::TYPE))
    {
        StringEvent *se = dynamic_cast<StringEvent*>(evt);

        qDebug() << "Receive: " << se->data();

        m_edit.insert(se->data());

        return true; //true代表事件已经被处理
    }

     return QWidget::eventFilter(obj, evt);
}
