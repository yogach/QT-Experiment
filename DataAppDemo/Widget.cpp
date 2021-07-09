#include "Widget.h"
#include "ScoreInfo.h"
#include "DataSource.h"
#include "ScoreInfoModel.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QEvent>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    m_view.setParent(this);
    m_view.move(10, 10);
    m_view.resize(345, 180);
    m_view.installEventFilter(this);

    m_refreshBtn.setParent(this);
    m_refreshBtn.move(10, 200);
    m_refreshBtn.resize(95, 30);
    m_refreshBtn.setText("Refresh");

    m_clearBtn.setParent(this);
    m_clearBtn.move(135, 200);
    m_clearBtn.resize(95, 30);
    m_clearBtn.setText("Clear");

    m_scoreBtn.setParent(this);
    m_scoreBtn.move(260, 200);
    m_scoreBtn.resize(95, 30);
    m_scoreBtn.setText("Score");

    m_menu.addAction("Delete"); //往QMenu对象中增加一个action

    m_model.setView(m_view);

    connect(&m_refreshBtn, SIGNAL(clicked()), this, SLOT(onRefreshBtnClicked()));
    connect(&m_clearBtn, SIGNAL(clicked()), this, SLOT(onClearBtnClicked()));
    connect(&m_scoreBtn, SIGNAL(clicked()), this, SLOT(onScoreBtnClicked()));

    //选择唯一的一个action对象作为信号来源
    connect(m_menu.actions()[0], SIGNAL(triggered()), this, SLOT(onDeleteActionClicked()));


    onRefreshBtnClicked();
}

void Widget::onDeleteActionClicked()
{

}


void Widget::onRefreshBtnClicked()
{
    DataSource ds;

    onClearBtnClicked();

    if(ds.setDataPath("/home/delphi/test.txt"))
    {
       m_model.add(ds.fetchData());
    }
    else
    {
        //显示一个消息对话框
        QMessageBox::critical(this, "Error", "Data source read error!", QMessageBox::Ok);
    }

}

void Widget::onClearBtnClicked()
{
    m_model.clear();
}

void Widget::onScoreBtnClicked()
{
    int min = 200, max = 0, average = 0;

    if( m_model.count() > 0)
    {
        for( int i=0; i<m_model.count(); i++)
        {
            ScoreInfo info = m_model.getItem(i);

            if( info.score() < min )
            {
                min = info.score();
            }

            if( info.score() > max)
            {
                max = info.score();
            }

            average += info.score();

        }

        average /= m_model.count();

        QMessageBox::information(this, "Statistic", QString().sprintf("Min: %d\nMax: %d\nAverage: %d", min, max, average), QMessageBox::Ok);
    }
    else
    {
         QMessageBox::information(this, "Statistic", "No data record!", QMessageBox::Ok);
    }

}

bool Widget::eventFilter(QObject *obj, QEvent *evt)
{
    //当检测到QTableView上的内容被点击时 打开定义好的Qmenu
    if( (obj == &m_view) && (evt->type() == QEvent::ContextMenu))
    {
       m_menu.exec(cursor().pos()); //在点击的位置上打开QMenu
    }

    return QWidget::eventFilter(obj, evt);
}


Widget::~Widget()
{
    
}
