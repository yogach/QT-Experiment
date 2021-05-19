#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "MyLineEdit.h"

class Widget : public QWidget
{
    Q_OBJECT
    
    MyLineEdit myEdit;
public:
    Widget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* e); //重载父类的keyPressEvent
    bool event(QEvent* e);
    bool eventFilter(QObject *obj, QEvent *e);
    ~Widget();
};

#endif // WIDGET_H
