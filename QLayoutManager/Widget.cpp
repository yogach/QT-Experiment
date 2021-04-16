#include "Widget.h"
#include <QVBoxLayout>


Widget::Widget(QWidget *parent) : QWidget(parent),
    TestBtn1(this) ,TestBtn2(this), TestBtn3(this), TestBtn4(this)
{
    //testVBoxLayout();
    //testHBoxLayout();
    testVHBoxLayout();
}

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


    //设置当前使用此布局管理器进行管理
    setLayout(layout);
}

void Widget::testVHBoxLayout()
{
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


Widget::~Widget()
{
    
}
