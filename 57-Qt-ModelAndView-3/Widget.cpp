#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initModel();
    initView();

    m_tableView.setModel(&m_model);

}

void Widget::initModel()
{
    QStandardItem* root = m_model.invisibleRootItem();
    QStandardItem* itemA = new QStandardItem();
    QStandardItem* itemB = new QStandardItem();
    QStandardItem* itemC = new QStandardItem();

    itemA->setData("A");
    itemA->setData("Tip A");
    itemA->setData("Help A");

    itemB->setData("B");
    itemB->setData("Tip B");

    itemC->setData("C");
    itemC->setData("Tip C");
    itemC->setData("Help C");

    root->setChild(0, 0, itemA);
    root->setChild(0, 1, itemB);
    root->setChild(1, 0, itemC);

}

void Widget::initView()
{
    m_tableView.setParent(this);
    m_tableView.move(10, 10);
    m_tableView.resize(300, 100);
}


Widget::~Widget()
{
    
}
