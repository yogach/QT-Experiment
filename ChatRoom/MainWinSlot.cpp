#include "MainWin.h"
#include <QDebug>
#include <QMessageBox>

void MainWin::initMember()
{
    m_client.setHandler(this);

    m_handlerMap.insert("CONN", &MainWin::CONN_Handler);
    m_handlerMap.insert("DSCN", &MainWin::DSCN_Handler);
    m_handlerMap.insert("LGIN", &MainWin::LIOK_Handler);
    m_handlerMap.insert("LIER", &MainWin::LIER_Handler);
    m_handlerMap.insert("MSGA", &MainWin::MSGA_Handler);
}

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

}

void MainWin::LIOK_Handler(QTcpSocket&, TextMessage& msg)
{
     setCtrlEnable(true);

     inputGrpBx.setTitle(msg.data());
}

void MainWin::LIER_Handler(QTcpSocket&, TextMessage&)
{

}

void MainWin::MSGA_Handler(QTcpSocket&, TextMessage&)
{

}

MainWin::~MainWin()
{

}
