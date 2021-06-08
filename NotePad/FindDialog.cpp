#include "FindDialog.h"
#include <QEvent>
#include <QString>
#include <QTextCursor>
#include <QMessageBox>

FindDialog::FindDialog(QWidget *parent, QPlainTextEdit* pText)
    :  QDialog(parent, Qt::WindowCloseButtonHint | Qt::Drawer)
{
    initControl();
    connectSlot();

    setLayout(&m_layout);
    setWindowTitle("Find");
    setPlainTextEdit(pText);
}

void FindDialog::initControl()
{
    m_findLbl.setText("Find What:");
    m_findBtn.setText("Find Next");
    m_closeBtn.setText("Close");
    m_matchChkBx.setText("Match Case");

    m_downwardBtn.setText("Downward");
    m_downwardBtn.setChecked(true); //设置向后查找为选中状态

    m_upwardBtn.setText("Upward");

    m_radioGrpBx.setTitle("Direction");

    m_hbLayout.addWidget(&m_upwardBtn);
    m_hbLayout.addWidget(&m_downwardBtn);

    m_radioGrpBx.setLayout(&m_hbLayout); //使用QGroupBox包含两个单选按键

    m_layout.setSpacing(10); //设置布局管理器中组件的间隔
    m_layout.addWidget(&m_findLbl, 0, 0);
    m_layout.addWidget(&m_findEdit, 0, 1);
    m_layout.addWidget(&m_findBtn, 0, 2);
    m_layout.addWidget(&m_matchChkBx, 1, 0);
    m_layout.addWidget(&m_radioGrpBx, 1, 1);
    m_layout.addWidget(&m_closeBtn, 1, 2);
}

void FindDialog::connectSlot()
{
    connect(&m_findBtn, SIGNAL(clicked()), this, SLOT(onFindClick()));
    connect(&m_closeBtn, SIGNAL(clicked()), this, SLOT(onCloseClick()));
}

void FindDialog::onFindClick()
{
    QString target = m_findEdit.text();

    if( (m_pText != NULL) && (target != "") )
    {
        QString text = m_pText->toPlainText();
        QTextCursor c = m_pText->textCursor(); //获取当前光标位置
        int index = -1;

        if( m_downwardBtn.isChecked() )
        {
            //从前往后查找
            index = text.indexOf(target, c.position(), m_matchChkBx.isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);

            //如果有找到对应字符串 选中字符串
            if( index >= 0)
            {
                c.setPosition(index);
                c.setPosition(index + target.length(), QTextCursor::KeepAnchor);

                m_pText->setTextCursor(c);
            }
        }

        if( m_upwardBtn.isChecked() )
        {
            //从前往后查找
            index = text.lastIndexOf(target, c.position() - text.length() - 1, m_matchChkBx.isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);

            //如果有找到对应字符串 选中字符串
            if( index >= 0)
            {
                c.setPosition(index + target.length());
                c.setPosition(index, QTextCursor::KeepAnchor);

                m_pText->setTextCursor(c);
            }
        }

        if( index < 0)
        {
            QMessageBox msg(this);

            msg.setWindowTitle("Find");
            msg.setText("Can not find \"" + target + "\" any more...");
            msg.setIcon(QMessageBox::Information);
            msg.setStandardButtons(QMessageBox::Ok);

            msg.exec();

        }

    }
}

void FindDialog::onCloseClick()
{
    close();
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

QPlainTextEdit* FindDialog::getPlainTextEdit()
{
   return m_pText;
}

void FindDialog::setPlainTextEdit(QPlainTextEdit* pText)
{
   m_pText = pText;
}
