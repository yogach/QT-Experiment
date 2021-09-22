#include "MainWin.h"
#include <QDebug>
#include <QMessageBox>


void MainWin::sendBtnClicked()
{

}

void MainWin::logInoutBtnClicked()
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

void MainWin::handle(QTcpSocket& obj, TextMessage& msg)
{
    qDebug() << msg.type();
    qDebug() << msg.data();
}

MainWin::~MainWin()
{

}
