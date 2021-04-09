#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton TestBtn;
private slots:
    void TestBtn_Clicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
