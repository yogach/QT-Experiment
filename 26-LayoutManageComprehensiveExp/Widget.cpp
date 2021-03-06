#include "Widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initControl();
}


void Widget::initControl()
{
    QVBoxLayout* vLayout = new QVBoxLayout();

    QHBoxLayout* hLayout = new QHBoxLayout();

    preBtn.setText("Pre Button");
    preBtn.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    preBtn.setMinimumSize(160,30);

    nextBtn.setText("Next Button");
    nextBtn.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    nextBtn.setMinimumSize(160,30);

    connect(&preBtn, SIGNAL(clicked()), this, SLOT(onPreBtnClicked()));
    connect(&nextBtn, SIGNAL(clicked()), this, SLOT(onNextBtnClicked()));

    sLayout.addWidget(get1stPage());
    sLayout.addWidget(get2ndPage());
    sLayout.addWidget(get3rdPage());

    hLayout->addWidget(&preBtn);
    hLayout->addWidget(&nextBtn);

    vLayout->addLayout(&sLayout);
    vLayout->addLayout(hLayout);

    setLayout(vLayout);
}

QWidget* Widget::get1stPage()
{
    QWidget* widget = new QWidget();
    QGridLayout* gLayout = new QGridLayout();

    fLbl1.setText("this");
    fLbl2.setText("is");
    fLbl3.setText("1st");
    fLbl4.setText("Page");

    gLayout->addWidget(&fLbl1, 0, 0);
    gLayout->addWidget(&fLbl2, 0, 1);
    gLayout->addWidget(&fLbl3, 1, 0);
    gLayout->addWidget(&fLbl4, 1, 1);


    widget->setLayout(gLayout);

    return widget;
}

QWidget* Widget::get2ndPage()
{
    QWidget* widget = new QWidget();
    QFormLayout* layout = new QFormLayout();

    sLineEdit.setText("This 2nd Page");
    layout->addRow("Hint:",&sLineEdit);

    widget->setLayout(layout);

    return widget;
}

QWidget* Widget::get3rdPage()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();

    tPushBtn1.setText("This is");
    tPushBtn2.setText("3rd Page");

    layout->addWidget(&tPushBtn1);
    layout->addWidget(&tPushBtn2);

    widget->setLayout(layout);

    return widget;
}

void Widget::onPreBtnClicked()
{
    int index = (sLayout.currentIndex() - 1 + 3) % sLayout.count();

    sLayout.setCurrentIndex(index);

}

void Widget::onNextBtnClicked()
{
    int index = (sLayout.currentIndex() + 1 ) % sLayout.count();

    sLayout.setCurrentIndex(index);
}

Widget::~Widget()
{
    
}
