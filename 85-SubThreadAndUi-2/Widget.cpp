#include "Widget.h"
#include "UpdateThread.h"
#include "StringEvent.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    textEdit.setParent(this);
    textEdit.move(20, 20);
    textEdit.resize(200, 150);
    textEdit.setReadOnly(true);

    m_thread.setParent(this); //设置子线程的父类
    m_thread.start();
}

bool Widget::event(QEvent *evt)
{
    bool ret = true;

    if( evt->type() == StringEvent::TYPE )
    {
        StringEvent* e = dynamic_cast<StringEvent*>(evt);

        textEdit.appendPlainText(e->data());

    }
    else
    {
       QWidget::event(evt);
    }

    return ret;
}

Widget::~Widget()
{
    
}
