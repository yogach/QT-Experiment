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

    void initMsgGrpBx();
    void initInputGrpBx();
    void connectSlots();

    void setCtrlEnable(bool enabled);
private slots:
    void sendBtnClicked();
    void logInoutBtnClicked();
public:
    MainWin(QWidget *parent = 0);
    void handle(QTcpSocket& obj, TextMessage& msg);
    ~MainWin();
};

#endif // MAINWIN_H
