#include "Widget.h"
#include <QPainter>
#include <QPoint>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    m_testBtn.setParent(this);
    m_testBtn.move(400, 300);
    m_testBtn.resize(70, 30);
    m_testBtn.setText("Test");

    resize(500, 350);

    connect(&m_testBtn, SIGNAL(clicked()), this, SLOT(onTestBtnClicked()));
}

void Widget::onTestBtnClicked()
{

}


void Widget::paintEvent(QPaintEvent *)
{
    //只能在PaintEvent事件处理中进行图形的绘制
    QPainter painter;

    painter.begin(this); //需要指定绘制的对象
    painter.drawLine(QPoint(30, 30), QPoint(100, 100));
    painter.end();

}

Widget::~Widget()
{
    
}
