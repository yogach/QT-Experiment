#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton TestBtn1;
    QPushButton TestBtn2;
    QPushButton TestBtn3;
    QPushButton TestBtn4;

    void testVBoxLayout();
    void testHBoxLayout();
    void testVHBoxLayout();
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
