#include "Widget.h"
#include <QStandardItem>
#include <QModelIndex>
#include <QStringList>
#include <QModelIndex>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    initView();
    initModel();

    m_view.setModel(&m_model);
}

void Widget::initView()
{
    m_view.setParent(this);
    m_view.move(10, 10);
    m_view.resize(500, 200);
    m_view.setItemDelegate(&m_delegate);
}

void Widget::initModel()
{
    QStandardItem* root = m_model.invisibleRootItem();
    QStringList hl;
    QStandardItem* itemA1 = new QStandardItem();
    QStandardItem* itemB1 = new QStandardItem();
    QStandardItem* itemA2 = new QStandardItem();
    QStandardItem* itemB2 = new QStandardItem();

    hl.append("Task");
    hl.append("Progress");

    m_model.setHorizontalHeaderLabels(hl);

    itemA1->setData("Delphi", Qt::DisplayRole);
    itemB1->setData(70, Qt::DisplayRole);

    itemA2->setData("Perl", Qt::DisplayRole);
    itemB2->setData(60, Qt::DisplayRole);

    root->setChild(0, 0, itemA1);
    root->setChild(0, 1, itemB1);
    root->setChild(1, 0, itemA2);
    root->setChild(1, 1, itemB2);
}

Widget::~Widget()
{
    
}
