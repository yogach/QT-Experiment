#include "ScoreInfoModel.h"
#include <QStandardItem>
#include <QVariant>

ScoreInfoModel::ScoreInfoModel(QObject *parent) :
    QObject(parent)
{
}

bool ScoreInfoModel::add(ScoreInfo info)
{
    QStandardItem* root = m_model.invisibleRootItem(); //获取模型的根节点
    QStandardItem* item0 = new QStandardItem();
    QStandardItem* item1 = new QStandardItem();
    QStandardItem* item2 = new QStandardItem();
    bool ret = true;

    if( (root != NULL) && (item0 != NULL) && (item1 != NULL) && (item2 != NULL))
    {
       item0->setData(info.id(), Qt::DisplayRole);
       item1->setData(info.name(), Qt::DisplayRole);
       item2->setData(info.score(), Qt::DisplayRole);

       item0->setEditable(false);
       item1->setEditable(false);
       item2->setEditable(false);

       int newRow = count(); //得到模型中的最后一行

       root->setChild(newRow, 0, item0); //将item0放在这一行的第一个位置 之后以此类推
       root->setChild(newRow, 1, item1);
       root->setChild(newRow, 2, item2);

    }
    else
    {
       ret = false;
    }

    return ret;
}

bool ScoreInfoModel::add(QList<ScoreInfo> list)
{
   bool ret = true;

   for(int i=0; i<list.count(); i++)
   {
       ret = ret && add(list[i]);
   }

   return ret;
}

bool ScoreInfoModel::remove(int i)
{
    bool ret = true;

    if( (0 <= i) && (i <= count()) )
    {
       m_model.removeRow(i);
    }
    else
    {
       ret = false;
    }

    return ret;
}

ScoreInfo ScoreInfoModel::getItem(int i)
{
    ScoreInfo ret;

    if( (0 <= i) && (i <= count()) )
    {
        QModelIndex index0 = m_model.index(i, 0, QModelIndex()); //从模型的第i行取出数据，因为是一个表格视图，所以根节点是不存在的
        QModelIndex index1 = m_model.index(i, 1, QModelIndex());
        QModelIndex index2 = m_model.index(i, 2, QModelIndex());
        QVariant v0 = index0.data(Qt::DisplayRole); //获取数据
        QVariant v1 = index1.data(Qt::DisplayRole);
        QVariant v2 = index2.data(Qt::DisplayRole);

        ret = ScoreInfo(v0.toString(), v1.toString(), v2.toInt());
    }

    return ret;
}

int ScoreInfoModel::count()
{
   return m_model.rowCount();
}

void ScoreInfoModel::clear()
{
    m_model.clear();
}

void ScoreInfoModel::setView(QTableView& view)
{
   view.setModel(&m_model);
}
