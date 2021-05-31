#include "Widget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>
#include <QEvent>

Widget::Widget(QWidget *parent) : QWidget(parent), m_button(this)
{
    m_button.setText("my_button");

    connect(&m_button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
}


void Widget::onButtonClicked()
{
    //点击按钮后会发送一个事件
    //testSendEvent();
    testPostEvent();
}

void Widget::testSendEvent()
{
    //声明一个鼠标双击事件，没有组合键
    //sendEvent 支持栈事件和堆事件的对象
    QMouseEvent dbcEvt(QEvent::MouseButtonDblClick, QPoint(0, 0), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

    qDebug() << "Before sendEvent()";

    QApplication::sendEvent(this, &dbcEvt);

    qDebug() << "After sendEvent()";

}

void Widget::testPostEvent()
{
    //声明一个鼠标双击事件，没有组合键
    //postEvent 堆事件的对象
    QMouseEvent* dbcEvt = new QMouseEvent(QEvent::MouseButtonDblClick, QPoint(0, 0), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

    qDebug() << "Before postEvent()";

    QApplication::postEvent(this, dbcEvt);

    qDebug() << "After postEvent()";

}

bool Widget::event(QEvent *e)
{
    if( e->type() == QEvent::MouseButtonDblClick )
    {
        qDebug() << "event(): " << e;
    }

    return QWidget::event(e);
}


Widget::~Widget()
{
    
}
