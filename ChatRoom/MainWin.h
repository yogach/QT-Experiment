#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class MainWin : public QWidget
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

    void initMsgGrpBx();
    void initInputGrpBx();
    void connectSlots();

private slots:
    void sendBtnClicked();
    void logInoutBtnClicked();
public:
    MainWin(QWidget *parent = 0);
    ~MainWin();
};

#endif // MAINWIN_H
