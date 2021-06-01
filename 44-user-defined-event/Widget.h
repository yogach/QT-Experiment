#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT
    
    QLineEdit m_edit;
public:
    Widget(QWidget *parent = 0);
    ~Widget();

    bool event(QEvent *evt);
    bool eventFilter(QObject *obj, QEvent *evt);
};

#endif // WIDGET_H
