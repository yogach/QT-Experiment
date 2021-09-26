#include "MainWin.h"
#include <QDebug>
#include <QMessageBox>

void MainWin::initMember()
{
    m_client.setHandler(this);

    m_handlerMap.insert("CONN", &MainWin::CONN_Handler);
    m_handlerMap.insert("DSCN", &MainWin::DSCN_Handler);
    m_handlerMap.insert("LIOK", &MainWin::LIOK_Handler);
    m_handlerMap.insert("LIER", &MainWin::LIER_Handler);
    m_handlerMap.insert("MSGA", &MainWin::MSGA_Handler);
    m_handlerMap.insert("USER", &MainWin::USER_Handler);
}

QString MainWin::getCheckedUserId()
{
    QString ret = "";

    for(int i=0; i<listWidget.count(); i++)
    {
        QListWidgetItem* item = listWidget.item(i);

        if( item->checkState() == Qt::Checked )
        {
            ret += item->text() + "\r";
        }
    }

    return ret;
}

void MainWin::sendBtnClicked()
{
    QString text = inputGrpBx.title() + ":\n" + "   " +  inputEdit.text() + "\n";
    TextMessage tm("MSGA", text);

    if( m_client.send(tm) )
    {
        inputEdit.clear();
    }
}

void MainWin::logInoutBtnClicked()
{
    //首先检查client的连接状态
    if( !m_client.isVaild() )
    {
        if( loginDlg.exec() == QDialog::Accepted )
        {
            QString usr = loginDlg.getUser().trimmed();
            QString pwd = loginDlg.getPwd();

            if( m_client.connectTo("127.0.0.1", 8890) )
            {
                TextMessage tm("LGIN", usr + "\r" + pwd);

                m_client.send(tm); //连接上服务器后开始发送用户名密码
            }
            else
            {
                QMessageBox::critical(this, "失败", "连接不到远程服务端！");
            }
        }
    }
    else
    {
        m_client.close();
    }
}

void MainWin::handle(QTcpSocket& obj, TextMessage& msg)
{
    //检查是否包含这个键值
    if( m_handlerMap.contains( msg.type() ))
    {
        MSGHandler handler = m_handlerMap.value(msg.type());

        (this->*handler)(obj, msg);
    }

}

void MainWin::CONN_Handler(QTcpSocket&, TextMessage&)
{

}

void MainWin::DSCN_Handler(QTcpSocket&, TextMessage&)
{
    setCtrlEnable(false);
    inputGrpBx.setTitle("用户名");
    msgEditor.clear();
}

void MainWin::LIOK_Handler(QTcpSocket&, TextMessage& msg)
{
     setCtrlEnable(true);

     inputGrpBx.setTitle(msg.data());
}

void MainWin::LIER_Handler(QTcpSocket&, TextMessage&)
{
    QMessageBox::critical(this, "错误", "身份验证失败！");

    m_client.close();
}

void MainWin::MSGA_Handler(QTcpSocket&, TextMessage& msg)
{
    msgEditor.appendPlainText(msg.data());
}

void MainWin::USER_Handler(QTcpSocket&, TextMessage& msg)
{
     QStringList user = msg.data().split("\r", QString::SkipEmptyParts);
     QStringList checkedItem = getCheckedUserId().split("\r", QString::SkipEmptyParts); //获取原先已经选中的选项id

     listWidget.clear();

     for(int i=0; i<user.length(); i++)
     {
         QListWidgetItem* item = new QListWidgetItem();

         if( item != NULL )
         {
             item->setText(user[i]);
             item->setCheckState(Qt::Unchecked);

             listWidget.addItem(item);
         }
     }

     for(int i=0; i<listWidget.count(); i++)
     {
         QListWidgetItem* item = listWidget.item(i);

         for(int j=0; j<checkedItem.length(); j++)
         {
             if( checkedItem[j] == item->text() )
             {
                item->setCheckState(Qt::Checked);
             }
         }

     }
}

MainWin::~MainWin()
{
   m_client.close();
}
