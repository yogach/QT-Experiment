#include "CustomizedItemDelegate.h"
#include <QCheckBox>
#include <QComboBox>
#include <QApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

CustomizedItemDelegate::CustomizedItemDelegate(QObject *parent) :
    QItemDelegate(parent)
{
    connect(this, SIGNAL(closeEditor(QWidget*)), this, SLOT(onCloseEditor(QWidget*)));
}

QWidget* CustomizedItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QWidget* ret = NULL;

    m_index = index;

    if( index.data().type() == QVariant::Bool)
    {
        QCheckBox* cb = new QCheckBox(parent);

        cb->setText("Check to TRUE");

        ret = cb;
    }
    else if( index.data().type() == QVariant::Char)
    {
        QComboBox* cb = new QComboBox(parent);

        cb->addItem("A");
        cb->addItem("B");
        cb->addItem("C");
        cb->addItem("D");

        ret = cb;
    }
    else
    {
        ret = QItemDelegate::createEditor(parent, option, index);
    }

    return ret;
}

void CustomizedItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect); //获取大小信息 设置编辑器大小
}

void CustomizedItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if( index.data().type() == QVariant::Bool)
    {
        QCheckBox* cb = dynamic_cast<QCheckBox*>(editor);

        if( cb != NULL)
        {
           cb->setChecked(index.data().toBool());
        }
    }
    else if( index.data().type() == QVariant::Char)
    {
        QComboBox* cb = dynamic_cast<QComboBox*>(editor);

        if( cb != NULL)
        {
            for(int i=0; i<cb->count(); i++)
            {
                //比较comboBox和模型内数据，符合则设置到编辑框内
                if( cb->itemText(i) == index.data().toString())
                {
                   cb->setCurrentIndex(i);
                   break;
                }
            }
        }
    }
    else
    {
         QItemDelegate::setEditorData(editor, index);
    }

}
void CustomizedItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if( index.data().type() == QVariant::Bool)
    {
        QCheckBox* cb = dynamic_cast<QCheckBox*>(editor);

        if( cb != NULL)
        {
           model->setData(index, cb->isChecked(), Qt::DisplayRole);
        }
    }
    else if( index.data().type() == QVariant::Char)
    {
        QComboBox* cb = dynamic_cast<QComboBox*>(editor);

        if( cb != NULL)
        {
            model->setData(index, cb->currentText().at(0), Qt::DisplayRole);
        }
    }
    else
    {
         QItemDelegate::setModelData(editor, model, index);
    }
}

void CustomizedItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //当切换到另一个视图项或者关闭编辑框时，开始绘制视图内容
    /*if( m_index != index)
    {
       QItemDelegate::paint(painter, option, index);
    }*/

    //当模型的数据类型为bool时，直接显示一个checkbox
    if( index.data().type() == QVariant::Bool)
    {
        bool data = index.data().toBool();
        QStyleOptionButton checkboxStyle;

        checkboxStyle.state = data ? QStyle::State_On : QStyle::State_Off;
        checkboxStyle.state |= QStyle::State_Enabled;
        checkboxStyle.rect = option.rect;
        checkboxStyle.rect.setX(option.rect.x() + option.rect.width() / 2 - 6);

        QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkboxStyle, painter);
    }
    else
    {
        QItemDelegate::paint(painter, option, index);
    }
}

bool CustomizedItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    bool ret = true;

    if( index.data().type() == QVariant::Bool )
    {
        QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);

        //当出现鼠标点击事件且位置位于bool型数据框内
        if( (event->type() == QEvent::MouseButtonPress ) && option.rect.contains(mouseEvent->pos()) )
        {
            bool data = index.data().toBool();

            qDebug() << "set model data: " << !data;
            qDebug() << model->setData(index, !data, Qt::DisplayRole);
        }
    }
    else
    {
       ret = QItemDelegate::editorEvent(event, model, option, index);
    }

    return ret;
}

void CustomizedItemDelegate::onCloseEditor(QWidget*)
{
    m_index = QModelIndex(); //当关闭了委托创建的编辑框时，创建一个空的索引
}
