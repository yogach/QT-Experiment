#include "Widget.h"
#include <QDebug>

void onMyButtonMouseRelease(QObject* sender, QMouseEvent* e)
{
    qDebug() << "Widget::onMyButtonMouseRelease";
}

Widget::Widget(QWidget *parent) : QWidget(parent), mybutton(this, onMyButtonMouseRelease)
{
    mybutton.setText("QMyButton");

    connect(&mybutton, SIGNAL(clicked()), this, SLOT(onMyButtonClicked()));
}

Widget::~Widget()
{
    
}

void Widget::onMyButtonClicked()
{
    qDebug() << "Widget::onMyButtonClicked";
}
