#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QPointer>

class FindDialog : public QDialog
{
    Q_OBJECT

protected:
    QGroupBox m_radioGrpBx;

    QGridLayout m_layout;
    QHBoxLayout m_hbLayout;

    QLabel m_findLbl;
    QLineEdit m_findEdit;
    QPushButton m_findBtn;
    QPushButton m_closeBtn;

    //勾选按钮
    QCheckBox m_matchChkBx;

    //单选按钮
    QRadioButton m_upwardBtn;
    QRadioButton m_downwardBtn;

    QPointer<QPlainTextEdit> m_pText;

    void initControl();
    void connectSlot();

protected slots:
    void onFindClick();
    void onCloseClick();

public:
    explicit FindDialog(QWidget *parent = 0, QPlainTextEdit* pText = 0);
    bool event(QEvent* evt);
    QPlainTextEdit* getPlainTextEdit();
    void setPlainTextEdit(QPlainTextEdit* pText);
    
};

#endif // FINDDIALOG_H
