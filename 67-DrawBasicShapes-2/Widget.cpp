#include "Widget.h"
#include <QPainter>
#include <QPen>
#include <QPointF>
#include <qmath.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;

    pen.setColor(Qt::green);
    pen.setStyle(Qt::SolidLine);
    pen.setWidthF(0.01);

    painter.setPen(pen);

    // 设置视口 在物理坐标系上画出一块区域
    painter.setViewport(50, 50, width()-100, height()-100);
    //设置窗口，在视口的区域重新自定义一个坐标系
    painter.setWindow(-10, 2, 20, -4); // begin(-10,2) end(10,-2)

    //设置窗口背景色
    painter.fillRect(-10, 2, 20, -4, Qt::black);

    //画x轴 y轴
    painter.drawLine(QPointF(-10, 0), QPointF(10, 0));
    painter.drawLine(QPointF(0, 2), QPointF(0, -2));

    for(float x=-10; x<10; x+=0.01)
    {
        float y = qSin(x);

        painter.drawPoint(QPointF(x, y));
    }

}

Widget::~Widget()
{
    
}
