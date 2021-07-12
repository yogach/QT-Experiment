#include "Widget.h"
#include <QModelIndex>
#include <QDebug>


Widget::Widget(QWidget* parent) : QWidget(parent)
{
    initView();
    initModel();

    m_view.setModel(&m_model);

    m_testBtn.setParent(this);
    m_testBtn.move(10, 120);
    m_testBtn.resize(300, 30);
    m_testBtn.setText("Test");

    connect(&m_testBtn, SIGNAL(clicked()), this, SLOT(onTestBtnClicked()));
}

void Widget::initView()
{
    m_view.setParent(this);
    m_view.move(10, 10);
    m_view.resize(300, 100);

}

void Widget::initModel()
{
    QStandardItem* root = m_model.invisibleRootItem();
    QStandardItem* itemA = new QStandardItem();
    QStandardItem* itemB = new QStandardItem();
    QStandardItem* itemC = new QStandardItem();
    QStandardItem* itemD = new QStandardItem();

    itemA->setData("A", Qt::DisplayRole);
    itemB->setData("B", Qt::DisplayRole);
    itemC->setData("C", Qt::DisplayRole);
    itemD->setData("D", Qt::DisplayRole);

    root->setChild(0, 0, itemA);
    root->setChild(0, 1, itemB);
    root->setChild(1, 0, itemC);
    root->setChild(1, 1, itemD);
}

void Widget::onTestBtnClicked()
{

}

Widget::~Widget()
{

}
