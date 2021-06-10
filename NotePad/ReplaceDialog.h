#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include "FindDialog.h"

class ReplaceDialog : public FindDialog
{
    Q_OBJECT

protected:
    QPushButton m_replaceBtn;
    QPushButton m_replaceAllBtn;
    QLabel m_replaceLbl;
    QLineEdit m_replaceEdit;

    void initControl();
    void connectSlot();

protected slots:
    void onReplaceClicked();
    void onReplaceAllClicked();

public:
    explicit ReplaceDialog(QWidget *parent = 0, QPlainTextEdit* pText = 0);

    
};

#endif // REPLACEDIALOG_H
