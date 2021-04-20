#include "Widget.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QStackedLayout>
#include <QtCore>

Widget::Widget(QWidget *parent) : QWidget(parent),
    TestBtn1(this) ,TestBtn2(this), TestBtn3(this), TestBtn4(this)
{
    //testVBoxLayout();
    //testHBoxLayout();
    //testVHBoxLayout();
    //testGridLayout2();
    //testFormLayout();
    testStackedLayout();
}

/*
Widget::Widget(QWidget *parent) : QWidget(parent , Qt::WindowCloseButtonHint)
{
   testFormLayout();
}*/

void Widget::testVBoxLayout()
{
    //垂直布局管理器
    QVBoxLayout* layout = new QVBoxLayout();

    TestBtn1.setText("Test Button 1");
    //设置大小策略
    TestBtn1.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160,30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160,30);

    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160,30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160,30);


    //设置组件之间当间隔距离
    layout->setSpacing(10);
    //将widget对象添加到布局管理器里
    layout->addWidget(&TestBtn1);
    layout->addWidget(&TestBtn2);
    layout->addWidget(&TestBtn3);
    layout->addWidget(&TestBtn4);

    //设置组件的缩放比例 使用制定第几个组件的方式
    //组件的初始大小是独立于布局管理器的 所有这些设置不修改组件的初始大小
    layout->setStretch(0, 1);
    layout->setStretch(1, 1);
    layout->setStretch(2, 2);
    layout->setStretch(3, 2);


    //设置当前使用此布局管理器进行管理
    setLayout(layout);
}

void Widget::testHBoxLayout()
{
    //水平方向布局管理器
    QHBoxLayout* layout = new QHBoxLayout();

    TestBtn1.setText("Test Button 1");
    //设置大小策略
    TestBtn1.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160,30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160,30);

    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160,30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160,30);


    //设置组件之间当间隔距离
    layout->setSpacing(10);
    //将widget对象添加到布局管理器里
    layout->addWidget(&TestBtn1);
    layout->addWidget(&TestBtn2);
    layout->addWidget(&TestBtn3);
    layout->addWidget(&TestBtn4);

    //设置组件的缩放比例 使用指定对象的方式
    layout->setStretchFactor(&TestBtn1, 1);
    layout->setStretchFactor(&TestBtn2, 2);
    layout->setStretchFactor(&TestBtn3, 1);
    layout->setStretchFactor(&TestBtn4, 3);

    //设置当前使用此布局管理器进行管理
    setLayout(layout);
}

void Widget::testVHBoxLayout()
{
    //垂直方向布局管理器 嵌套水平方向布局管理
    QHBoxLayout* hLayout1 = new QHBoxLayout();
    QHBoxLayout* hLayout2 = new QHBoxLayout();
    QVBoxLayout* VLayout = new QVBoxLayout();

    TestBtn1.setText("Test Button 1");
    //设置大小策略
    TestBtn1.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160,30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160,30);

    hLayout1->setSpacing(10);
    hLayout1->addWidget(&TestBtn1);
    hLayout1->addWidget(&TestBtn2);


    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160,30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160,30);

    hLayout2->setSpacing(10);
    hLayout2->addWidget(&TestBtn3);
    hLayout2->addWidget(&TestBtn4);


    VLayout->setSpacing(10);
    VLayout->addLayout(hLayout1);
    VLayout->addLayout(hLayout2);


    //设置当前使用此布局管理器进行管理
    setLayout(VLayout);
}

void Widget::testGridLayout1()
{
    //网格布局管理器
    QGridLayout* layout = new QGridLayout();

    TestBtn1.setText("Test Button 1");
    //设置大小策略
    TestBtn1.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160,30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160,30);

    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160,30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160,30);


    //将widget对象添加到网格布局管理器里
    //参数分别代表放在第几个网格
    layout->addWidget(&TestBtn1, 0, 1); //放在第0行的一位置上，之后以此类推
    layout->addWidget(&TestBtn2, 0, 2);
    layout->addWidget(&TestBtn3, 1, 0);
    layout->addWidget(&TestBtn4, 1, 1);

    //设置当前使用此布局管理器进行管理
    setLayout(layout);
}

void Widget::testGridLayout2()
{
    //网格布局管理器
    QGridLayout* layout = new QGridLayout();

    TestBtn1.setText("Test Button 1");
    //设置大小策略
    TestBtn1.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160,30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160,30);

    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160,30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160,30);


    //将widget对象添加到网格布局管理器里
    //参数分别代表放在第几个网格 占据行宽和列宽
    layout->addWidget(&TestBtn1, 0, 0, 2, 1); //放在第0行的一位置上，占据2行1列，之后以此类推
    layout->addWidget(&TestBtn2, 0, 1, 2, 1);
    layout->addWidget(&TestBtn3, 2, 1, 1, 2);
    layout->addWidget(&TestBtn4, 3, 2, 1, 2);

    //设置当前使用此布局管理器进行管理
    setLayout(layout);
}

void Widget::testFormLayout()
{
    //表单布局管理器
    QFormLayout* layout = new QFormLayout();
    QLineEdit* nameEdit = new QLineEdit();
    QLineEdit* mailEdit = new QLineEdit();
    QLineEdit* addrEdit = new QLineEdit();

    layout->addRow("Name:",nameEdit);
    layout->addRow("Mail:",mailEdit);
    layout->addRow("Address:",addrEdit);

    layout->setRowWrapPolicy(QFormLayout::WrapAllRows); //设置组件始终处于lable下方
    //layout->setAlignment(Qt::AlignLeft); //设置标签左右对齐

    layout->setSpacing(10);    //设置组件间隔

    //设置当前使用此布局管理器进行管理
    setLayout(layout);
    setWindowTitle("FTP");
}

void Widget::testStackedLayout()
{
    //栈式布局管理器
    QStackedLayout* sLayout = new QStackedLayout();
    QHBoxLayout* hLayout = new QHBoxLayout();
    QWidget* widget = new QWidget();
    QTimer* timer = new QTimer();

    TestBtn1.setText("Test Button 1");
    TestBtn2.setText("Test Button 2");
    TestBtn3.setText("Test Button 3");
    TestBtn4.setText("Test Button 4");

    //下面的代码主要目的就是将QHBoxLayout 嵌套入QStackedLauout中
    TestBtn2.setParent(widget);
    TestBtn3.setParent(widget);

    hLayout->addWidget(&TestBtn2);
    hLayout->addWidget(&TestBtn3);

    widget->setLayout(hLayout);

    ////////////////////////////

    sLayout->addWidget(&TestBtn1);
    sLayout->addWidget(widget);
    sLayout->addWidget(&TestBtn4);

    sLayout->setCurrentIndex(0);

    //设置当前使用此布局管理器进行管理
    setLayout(sLayout);

    connect(timer, SIGNAL(timeout()), this, SLOT(timeroutHandler()));

    timer->start(2000); //设置2000ms触发一次

}

void Widget::timeroutHandler()
{
    //获得管理组件的layout
    QStackedLayout* sLayout = dynamic_cast<QStackedLayout*>(layout());

    if( sLayout != NULL)
    {
        //循环显示QStackedLayout里面的组件
        int index = ( sLayout->currentIndex() + 1 ) % sLayout->count();

        sLayout->setCurrentIndex(index);

    }

}

Widget::~Widget()
{
    
}
