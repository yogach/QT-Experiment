#ifndef QMYPUSHBUTTON_H
#define QMYPUSHBUTTON_H

#include <QPushButton>

typedef void (QButtonListerner)(QObject*, QMouseEvent*);


class QMyPushButton : public QPushButton
{
    Q_OBJECT
protected:
    QButtonListerner* m_listener;

    void mouseReleaseEvent(QMouseEvent *e);

public:
    explicit QMyPushButton(QWidget *parent = 0, QButtonListerner* listener = 0);
    
signals:
    
public slots:
    
};

#endif // QMYPUSHBUTTON_H
