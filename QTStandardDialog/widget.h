#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>

#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton SimpleMsgBtn;
    QPushButton CustomMsgBtn;
    QPushButton OpenFileBtn;
    QPushButton SaveFileBtn;

private slots:
    void SimpleMsgBtn_Clicked();
    void CustomMsgBtn_Clicked();
    void OpenFileBtn_Clicked();
    void SaveFileBtn_Clicked();
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
