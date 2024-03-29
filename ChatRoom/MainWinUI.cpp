#include "MainWin.h"

MainWin::MainWin(QWidget *parent)
    : QWidget(parent) , loginDlg(this), m_level("")
{
    initInputGrpBx();
    initMsgGrpBx();
    connectSlots();
    initMember();
    initListWidgetMenu();

    vMainLayout.addWidget(&msgGrpBx);
    vMainLayout.addWidget(&inputGrpBx);
    setLayout(&vMainLayout);

    setWindowTitle("网络聊天室");
    setMinimumSize(550, 400);
    resize(550, 400);
}

void MainWin::initMsgGrpBx()
{
    QHBoxLayout* hbl = new QHBoxLayout();

    msgEditor.setReadOnly(true);
    msgEditor.setFocusPolicy(Qt::NoFocus);
    listWidget.setFocusPolicy(Qt::NoFocus);
    listWidget.setContextMenuPolicy(Qt::CustomContextMenu); //设置listwidget使用自定义的右键菜单

    hbl->addWidget(&msgEditor, 7);
    hbl->addWidget(&listWidget, 3);
    hbl->setContentsMargins(2, 5, 2, 2);

    msgGrpBx.setLayout(hbl);    
    msgGrpBx.setTitle("聊天消息");
}

void MainWin::initInputGrpBx()
{
    QGridLayout* gl = new QGridLayout();

    gl->setSpacing(10);
    gl->addWidget(&inputEdit, 0, 0, 1, 5);
    gl->addWidget(&statusLbl, 1, 0, 1, 3);
    gl->addWidget(&logInoutBtn, 1, 3);
    gl->addWidget(&sendBtn, 1, 4);

    inputEdit.setFixedHeight(23);
    inputEdit.setEnabled(false);
    inputEdit.installEventFilter(this);

    statusLbl.setText("状态: 未登录");
    logInoutBtn.setFixedHeight(30);
    logInoutBtn.setText("登录");
    sendBtn.setFixedHeight(30);
    sendBtn.setText("发送");
    sendBtn.setEnabled(false);

    inputGrpBx.setLayout(gl);
    inputGrpBx.setTitle("用户区域");
}

void MainWin::initListWidgetMenu()
{
    QAction* act;

    //添加右键菜单对象
    act = listWidgetMenu.addAction("禁言", this, SLOT(listWidgetMenuClicked()));
    act->setObjectName("silent");

    act = listWidgetMenu.addAction("恢复", this, SLOT(listWidgetMenuClicked()));
    act->setObjectName("recover");

    act = listWidgetMenu.addAction("封账号", this, SLOT(listWidgetMenuClicked()));
    act->setObjectName("kick");
}

void MainWin::connectSlots()
{
   connect(&sendBtn, SIGNAL(clicked(bool)), this, SLOT(sendBtnClicked()));
   connect(&logInoutBtn, SIGNAL(clicked(bool)), this, SLOT(logInoutBtnClicked()));
   //连接listwidget对象的右键点击信号到对应槽函数
   connect(&listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(listWidgetContextMenu(QPoint)));
}

void MainWin::setCtrlEnable(bool enabled)
{
    inputEdit.setEnabled(enabled);
    statusLbl.setText(enabled ? "状态: 连接成功" : "状态: 未登录");
    logInoutBtn.setText(enabled ? "退出" : "登录");
    sendBtn.setEnabled(enabled);

    if( enabled )
    {

    }
    else
    {
        listWidget.clear();
        inputEdit.clear();
    }
}


