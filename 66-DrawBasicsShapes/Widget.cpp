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
    //点击按钮时生成一个链表项
    DrawParam dp =
    {
        qrand() % 3,
        static_cast<Qt::PenStyle>(qrand() % 5 + 1),
        QPoint(qrand() % 400, qrand() % 300),
        QPoint(qrand() % 400, qrand() % 300),
    };

    if(m_list.count() >= 5)
    {
       m_list.clear();
    }

    m_list.append(dp);

    update(); //执行此语句后会重新绘制页面

}

//只能在PaintEvent事件处理中进行图形的绘制
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;

    painter.begin(this); //需要指定绘制的对象

    //处理链表中的数据，一个个的绘制
    for(int i=0; i<m_list.count(); i++)
    {
        int x = (m_list[i].begin.x() < m_list[i].end.x() ) ? m_list[i].end.x() : m_list[i].begin.x();
        int y = (m_list[i].begin.y() < m_list[i].end.y() ) ? m_list[i].end.y() : m_list[i].begin.y();
        int w = qAbs( m_list[i].begin.x() - m_list[i].end.x() ) + 1;
        int h = qAbs( m_list[i].begin.y() - m_list[i].end.y() ) + 1;

        painter.setPen(m_list[i].pen);

        switch(m_list[i].type)
        {
        case LINE:
            painter.drawLine(m_list[i].begin, m_list[i].end);
            break;

        case RECT:
            painter.drawRect(x, y, w, h);
            break;

        case ELLIPSE:
            painter.drawEllipse(x, y, w, h);
            break;

        }
    }

    painter.end();

}

Widget::~Widget()
{
    
}
