#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>


class Widget : public QWidget
{
    Q_OBJECT
    
    QPushButton m_testBtn;

protected slots:
    void onTestBtnClicked();
protected :
    void paintEvent(QPaintEvent *);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
