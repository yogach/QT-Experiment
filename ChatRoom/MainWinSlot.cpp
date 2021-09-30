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
    m_handlerMap.insert("CTRL", &MainWin::CTRL_Handler);
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
    QString input = inputEdit.text().trimmed();

    if( input != "")
    {
        QString self = inputGrpBx.title();
        QString text = self + ":\n" + input + "\n";
        QString uid = getCheckedUserId();
        bool ok = true;

        if( uid == "")
        {
            TextMessage tm("MSGA", text);

            ok = m_client.send(tm);
        }
        else
        {
            //检查自己的id是否在uid内 如果不在就附在末尾
            QString sid = (uid.indexOf(self) >= 0) ? uid : ( uid + self + '\r');
            TextMessage tm("MSGP", sid + text);

            ok = m_client.send(tm);
        }

        if( ok )
        {
            inputEdit.clear();
        }

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
    QStringList list = msg.data().split("\r", QString::SkipEmptyParts);
    QString id = list[0];
    QString status = list[1];

    m_level = list[2];

    if( status == "silent")
    {
        setCtrlEnable(true);

        inputGrpBx.setTitle(id);
        inputEdit.setEnabled(false);
        sendBtn.setEnabled(false);
    }
    else if( status == "kick")
    {
        m_client.close();

        QMessageBox::information(this, "提示", "账号 [ " + id + " ] 被禁止登录聊天室！");
    }
    else
    {
        setCtrlEnable(true);

        inputGrpBx.setTitle(id);
    }
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

void MainWin::CTRL_Handler(QTcpSocket&, TextMessage& msg)
{
    if( msg.data() == "silent")
    {
        QMessageBox::information(this, "提示", "你已经被管理员禁言！");

        inputEdit.clear();
        inputEdit.setEnabled(false);
        sendBtn.setEnabled(false);
    }
    else if( msg.data() == "kick")
    {
        QMessageBox::information(this, "提示", "账号 [ " + inputGrpBx.title() + " ] 被禁止登录聊天室！");

        m_client.close();
    }
    else if( msg.data() == "recover")
    {
        QMessageBox::information(this,  "提示", "管理员恢复了你的聊天权限！");

        inputEdit.setEnabled(true);
        sendBtn.setEnabled(true);
    }
}

void MainWin::listWidgetMenuClicked()
{
    QAction* act = dynamic_cast<QAction*>(sender()); //得到信号的发送者

    if( act != NULL )
    {
        const QList<QListWidgetItem*>& s1 = listWidget.selectedItems(); //得到当前鼠标选择的

        if( s1.length() > 0)
        {
            QString user = s1.at(0)->text();
            QString tip = "确认对聊天成员 [ " + user + " ] 进行" + act->text() + "操作吗？";

            if(QMessageBox::question(this, "提示", tip, QMessageBox::Yes, QMessageBox::No ) == QMessageBox::Yes )
            {
                QString data = act->objectName() + '\r' + user; //得到操作名和id
                TextMessage tm("ADMN", data);

                m_client.send(tm);
            }
        }
        else
        {
            QMessageBox::information(this, "提示", "请选择聊天成员！");
        }
    }
}



void MainWin::listWidgetContextMenu(const QPoint&)
{
    if( m_level == "admin")
    {
        listWidgetMenu.exec(QCursor::pos()); //在鼠标位置打开右键菜单
    }
}

MainWin::~MainWin()
{
   m_client.close();
}
