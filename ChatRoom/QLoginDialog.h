#ifndef QLOGINDIALOG_H
#define QLOGINDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>

class QLoginDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel UserLabel;
    QLabel PwdLabel;
    QLabel CaptLabel;
    QLineEdit UserEdit;
    QLineEdit PwdEdit;
    QLineEdit CaptEdit;
    QPushButton LoginBtn;
    QPushButton CancelBtn;
    QString m_User;
    QString m_Pwd;
    QString m_captcha;
    Qt::GlobalColor* m_colors;
    QTimer m_timer;

protected:
    void paintEvent(QPaintEvent *);
    QString getCaptcha();
    Qt::GlobalColor* getColor();
    void showEvent(QShowEvent *);

protected slots:
    void LoginBtn_Clicked();
    void CancelBtn_Clicked();
    void onTimerOut();
public:
    QLoginDialog(QWidget *parent = 0);
    QString getUser();
    QString getPwd();
    ~QLoginDialog();

};

#endif // QLOGINDIALOG_H
