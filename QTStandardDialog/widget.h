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
    QPushButton ColorDialogBtn;
    QPushButton InputDialogBtn;
    QPushButton FontDialogBtn;
    QPushButton ProgressDialogBtn;
    QPushButton PrintDialogBtn;


private slots:
    void SimpleMsgBtn_Clicked();
    void CustomMsgBtn_Clicked();
    void OpenFileBtn_Clicked();
    void SaveFileBtn_Clicked();
    void ColorDialogBtn_Clicked();
    void InputDialogBtn_Clicked();
    void FontDialogBtn_Clicked();
    void PrintDialogBtn_Clicked();
    void ProgressDialogBtn_Clicked();
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
