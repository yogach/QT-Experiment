#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "QLoginDialog.h"
#include "ClientDemo.h"
#include "TxtMsgHandler.h"

class MainWin : public QWidget , public TxtMsgHandler
{
    Q_OBJECT

    typedef void (MainWin::*MSGHandler)(QTcpSocket&, TextMessage&); //定义一个指向MainWin内函数的函数指针

    QVBoxLayout vMainLayout;
    QGroupBox msgGrpBx;
    QGroupBox inputGrpBx;
    QPlainTextEdit msgEditor;
    QLineEdit inputEdit;
    QLabel statusLbl;
    QPushButton logInoutBtn;
    QPushButton sendBtn;
    QLoginDialog loginDlg;

    ClientDemo m_client;

    QMap<QString, MSGHandler> m_handlerMap;


    void initMsgGrpBx();
    void initInputGrpBx();
    void initMember();
    void connectSlots();

    void setCtrlEnable(bool enabled);
    void CONN_Handler(QTcpSocket&, TextMessage&);
    void DSCN_Handler(QTcpSocket&, TextMessage&);
    void LIOK_Handler(QTcpSocket&, TextMessage&);
    void LIER_Handler(QTcpSocket&, TextMessage&);
    void MSGA_Handler(QTcpSocket&, TextMessage&);

private slots:
    void sendBtnClicked();
    void logInoutBtnClicked();
public:
    MainWin(QWidget *parent = 0);
    void handle(QTcpSocket& obj, TextMessage& msg);
    ~MainWin();
};

#endif // MAINWIN_H
