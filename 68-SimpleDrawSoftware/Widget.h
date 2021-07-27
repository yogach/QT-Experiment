#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QComboBox>
#include <QPoint>

class Widget : public QWidget
{
    Q_OBJECT

    enum DrawType
    {
        NONE,
        FREE,
        LINE,
        RECT,
        ELLIPSE,
    };

    struct DrawParam
    {
        DrawType type;
        Qt::GlobalColor color;
        QList<QPoint> points; //用于保存点
    };


    QGroupBox m_group;
    QRadioButton m_freeBtn;
    QRadioButton m_lineBtn;
    QRadioButton m_rectBtn;
    QRadioButton m_ellipseBtn;
    QComboBox m_colorBox;

    QList<DrawParam> m_list;
    DrawParam m_current;

    DrawType drawType();
    Qt::GlobalColor drawColor();

protected :
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
