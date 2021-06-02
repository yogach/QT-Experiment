#include "FindDialog.h"
#include <QEvent>

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowCloseButtonHint | Qt::Drawer)
{
    m_findLbl.setText("Find What:");
    m_findBtn.setText("Find Next");
    m_closeBtn.setText("Close");
    m_matchChkBx.setText("Match Case");

    m_backwardBtn.setText("Backward");
    m_forwardBtn.setText("Forward");
    m_forwardBtn.setChecked(true); //设置向前查找为选中状态

    m_radioGrpBx.setTitle("Direction");

    m_hbLayout.addWidget(&m_forwardBtn);
    m_hbLayout.addWidget(&m_backwardBtn);

    m_radioGrpBx.setLayout(&m_hbLayout); //使用QGroupBox包含两个单选按键

    m_layout.setSpacing(10); //设置布局管理器中组件的间隔
    m_layout.addWidget(&m_findLbl, 0, 0);
    m_layout.addWidget(&m_findEdit, 0, 1);
    m_layout.addWidget(&m_findBtn, 0, 2);
    m_layout.addWidget(&m_matchChkBx, 1, 0);
    m_layout.addWidget(&m_radioGrpBx, 1, 1);
    m_layout.addWidget(&m_closeBtn, 1, 2);

    setLayout(&m_layout);
    setWindowTitle("Find");
}


bool FindDialog::event(QEvent* evt)
{
    if( evt->type() == QEvent::Close)
    {
        hide(); //隐藏窗口 重新打开后内容依旧存在

        return true;
    }

    return QDialog::event(evt);
}
