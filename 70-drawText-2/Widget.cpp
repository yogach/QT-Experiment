#include "Widget.h"
#include <QPainter>
#include <QFont>
#include <QFontMetrics>
#include <QRect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_sizeFactor = 0;

    m_timer.setParent(this);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    m_timer.start(50);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    const QString text = "D.T.SoftWare";
    QFont font("Comic Sans MS", 5 + (m_sizeFactor++) % 100);
    QFontMetrics metrics(font); //得到字符串的度量值

    //得到字符串在屏幕上的显示长宽
    const int w = metrics.width(text);
    const int h = metrics.height();
    QRect rect( (width() - w) / 2, (height() - h) / 2, w, h) ; //计算字符串所占矩形的起点

    painter.begin(this);
    painter.setPen(Qt::blue);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, text);

    painter.end();
}

void Widget::onTimeOut()
{
    update();
}


Widget::~Widget()
{
    
}
