#include "Widget.h"
#include "TestThread.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //无法在子线程中直接更新ui
    /*TestThread* ptt = new TestThread;

    ptt->start();*/

    textEdit.setParent(this);
    textEdit.move(20, 20);
    textEdit.resize(200, 150);
    textEdit.setReadOnly(true);

    connect(&m_thread, SIGNAL(updateUI(QString)), this, SLOT(appendText(QString)));

    m_thread.start();
}

void Widget::appendText(QString text)
{
    textEdit.appendPlainText(text);
}

Widget::~Widget()
{
    
}
