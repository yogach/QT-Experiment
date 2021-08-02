#include "Widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.save(); //保存当前的设置

    painter.setFont(QFont("Arial", 16));
    painter.setPen(Qt::black);
    painter.rotate(0); //设置旋转角度
    painter.drawText(30, 40, "D.T.SoftWare");

    painter.setPen(Qt::red);
    painter.setFont(QFont("Comic Sans Ms", 20));
    painter.rotate(20);
    painter.drawText(30, 40, "D.T.SoftWare");

    painter.restore();

    painter.drawText(130, 140, "D.T.SoftWare");

}

Widget::~Widget()
{
    
}
