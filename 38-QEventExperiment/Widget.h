#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "QMyPushButton.h"

class Widget : public QWidget
{
    Q_OBJECT

    QMyPushButton mybutton;


protected slots:
    void onMyButtonClicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
