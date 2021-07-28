#include "Widget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    m_group.setParent(this);
    m_group.setTitle("Setting");
    m_group.resize(600, 65);
    m_group.move(20, 20);

    m_freeBtn.setParent(&m_group);
    m_freeBtn.setText("Free");
    m_freeBtn.resize(70, 30);
    m_freeBtn.move(35, 20);
    m_freeBtn.setChecked(true);

    m_lineBtn.setParent(&m_group);
    m_lineBtn.setText("Line");
    m_lineBtn.resize(70, 30);
    m_lineBtn.move(140, 20);

    m_rectBtn.setParent(&m_group);
    m_rectBtn.setText("Rect");
    m_rectBtn.resize(70, 30);
    m_rectBtn.move(245, 20);

    m_ellipseBtn.setParent(&m_group);
    m_ellipseBtn.setText("Ellipse");
    m_ellipseBtn.resize(70, 30);
    m_ellipseBtn.move(350, 20);

    m_colorBox.setParent(&m_group);
    m_colorBox.resize(80, 25);
    m_colorBox.move(480, 23);
    m_colorBox.addItem("Black");
    m_colorBox.addItem("Blue");
    m_colorBox.addItem("Green");
    m_colorBox.addItem("Red");
    m_colorBox.addItem("Yellow");

    setFixedSize(width(), 600);

    m_current.color = Qt::white;
    m_current.type = NONE;
    m_current.points.clear();

}

Widget::DrawType Widget::drawType()
{
    DrawType ret = NONE;

    if( m_freeBtn.isChecked() ) ret = FREE;
    if( m_lineBtn.isChecked() ) ret = LINE;
    if( m_rectBtn.isChecked() ) ret = RECT;
    if( m_ellipseBtn.isChecked() ) ret = ELLIPSE;

    return ret;
}

Qt::GlobalColor Widget::drawColor()
{
    Qt::GlobalColor ret = Qt::black;

    if( m_colorBox.currentText() == "Black") ret = Qt::black;
    if( m_colorBox.currentText() == "Blue") ret = Qt::blue;
    if( m_colorBox.currentText() == "Green") ret = Qt::green;
    if( m_colorBox.currentText() == "Red") ret = Qt::red;
    if( m_colorBox.currentText() == "Yellow") ret = Qt::yellow;

    return ret;
}

void Widget::mousePressEvent(QMouseEvent *evt)
{
     m_current.color = drawColor();
     m_current.type = drawType();

     m_current.points.append(evt->pos());
}

void Widget::mouseMoveEvent(QMouseEvent *evt)
{
     m_current.points.append(evt->pos());

     update();
}

void Widget::mouseReleaseEvent(QMouseEvent *evt)
{
     m_current.points.append(evt->pos());

     m_list.append(m_current);

     m_current.color = Qt::white;
     m_current.type = NONE;
     m_current.points.clear();

     update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for(int i=0; i<m_list.count(); i++)
    {
        draw(painter, m_list[i]);
    }

    draw(painter, m_current);

}

void Widget::draw(QPainter& painter, DrawParam& param)
{
    if(( param.type != NONE) && (param.points.count() >= 2))
    {
        painter.setPen(QPen(param.color));
        painter.setBrush(QBrush(param.color));

        switch(param.type)
        {
        case FREE:
            for(int i=0; i<param.points.count()-1; i++)
            {
                painter.drawLine(param.points[i], param.points[i+1]);
            }

            break;
        case LINE:
            break;
        case RECT:
            break;
        case ELLIPSE:
            break;
        default:
            break;
        }

    }
}

Widget::~Widget()
{
    
}
