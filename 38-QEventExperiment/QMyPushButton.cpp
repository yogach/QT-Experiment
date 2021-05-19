#include "QMyPushButton.h"
#include <QMouseEvent>


QMyPushButton::QMyPushButton(QWidget *parent, QButtonListerner* listener) : QPushButton(parent)
{
    m_listener = listener;
}

//重载父类中的mouseReleaseEvent 发生按键事件后会先调用此函数
void QMyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if( m_listener!=NULL )
    {
        m_listener(this, e); //调用传入的事件指针

        e->accept(); // 已经处理此事件

        setDown(false); //弹起按钮
    }
    else
    {
      QPushButton::mouseReleaseEvent(e); //调用父类的对象 这样之后按键事件会转化成signal传递给slot函数
    }
}
