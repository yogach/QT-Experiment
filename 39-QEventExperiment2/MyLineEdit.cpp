#include "MyLineEdit.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

//当在MyLineEdit对象中输入数据时，只会调用MyLineEdit重载的event和keyPressEvent
bool MyLineEdit::event(QEvent *e)
{
    if( e->type() == QEvent::KeyPress )
    {
        qDebug() << "MyLineEdit::event";
    }

    return QLineEdit::event(e);
}

void MyLineEdit::keyPressEvent(QKeyEvent *e)
{

    qDebug() << "MyLineEdit::keyPressEvent";

    QLineEdit::keyPressEvent(e);

    //e->ignore(); //调用此函数代表当前忽略此事件 结果就是调用父类当event函数
}
