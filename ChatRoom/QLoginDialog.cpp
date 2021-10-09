#include "QLoginDialog.h"
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QMessageBox>

QLoginDialog::QLoginDialog(QWidget *parent) : QDialog(parent , Qt::WindowCloseButtonHint) ,
    UserLabel(this), PwdLabel(this), CaptLabel(this),
    UserEdit(this), PwdEdit(this), CaptEdit(this),
    LoginBtn(this), CancelBtn(this),
    m_vf(NULL)
{
    UserLabel.setText("用户名:");
    UserLabel.move(20, 30);
    UserLabel.resize(60, 25);

    UserEdit.move(85, 30);
    UserEdit.resize(180, 25);

    PwdLabel.setText("密码:");
    PwdLabel.move(20, 65);
    PwdLabel.resize(60,25);

    CaptLabel.setText("验证码:");
    CaptLabel.move(20, 100);
    CaptLabel.resize(60, 25);

    CaptEdit.move(85, 100);
    CaptEdit.resize(85, 25);


    PwdEdit.move(85, 65);
    PwdEdit.resize(180, 25);
    PwdEdit.setEchoMode(QLineEdit::Password);

    CancelBtn.setText("取消");
    CancelBtn.move(85, 145);
    CancelBtn.resize(85, 30);

    LoginBtn.setText("登录");
    LoginBtn.move(180, 145);
    LoginBtn.resize(85, 30);

    setWindowTitle("登录....");
    setFixedSize(285, 205);

    m_timer.setParent(this);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
    connect(&LoginBtn , SIGNAL(clicked()) , this , SLOT(LoginBtn_Clicked()));
    connect(&CancelBtn , SIGNAL(clicked()) , this , SLOT(CancelBtn_Clicked()));

    qsrand(QTime::currentTime().second() * 1000 + QTime::currentTime().msec() );


    m_timer.start(200);
}

void QLoginDialog::LoginBtn_Clicked()
{
    QString captcha = CaptEdit.text().replace(" ", "");//去除验证码输入框中的空格

    m_User = UserEdit.text();
    m_Pwd = PwdEdit.text();

    //验证码不区分大小写
    if( captcha.toLower() == m_captcha.toLower())
    {

        if( (m_User == "") || (m_Pwd == ""))
        {
            QMessageBox::information(this, "消息", "用户名和密码不能为空！");
        }
        else if( (m_vf != NULL) && ( !m_vf(m_User) ))
        {
            QMessageBox::critical(this, "错误", "用户名不合法，请重新输入！");
        }
        else
        {
            done(Accepted);  //Closes the dialog and sets its result code to r
        }
    }
    else
    {
        //验证码验证失败后 提示输入错误并重新生成
        QMessageBox().critical(this, "错误", "验证码输入错误！");

        m_captcha = getCaptcha();

        update();

        CaptEdit.selectAll();
    }

}

void QLoginDialog::CancelBtn_Clicked()
{
    done(Rejected);
}

QString QLoginDialog::getCaptcha()
{
    QString ret;

    for(int i=0; i<4; i++)
    {
        int c = (qrand() % 2) ? 'a' : 'A';

        ret += static_cast<QChar>(c + qrand() % 26);
    }

    return ret;
}

Qt::GlobalColor* QLoginDialog::getColor()
{
    static Qt::GlobalColor color[4];

    for(int i=0; i<4; i++)
    {
        color[i] = static_cast<Qt::GlobalColor>(2 +qrand() % 16);
    }

    return color;
}

void QLoginDialog::paintEvent(QPaintEvent *evt)
{
    QPainter painter(this);

    painter.fillRect(180, 100, 84, 24, Qt::white);

    painter.setFont(QFont("Comic Sans MS", 12));

    //在指定的区域生成一些噪点
    for(int i=0; i<150; i++)
    {
        painter.setPen(m_colors[i%4]);
        painter.drawPoint(180 + qrand() % 84 ,100 + qrand() % 24);
    }

    //在指定的区域里生成字符串
    for(int i=0; i<4; i++)
    {
        painter.setPen(m_colors[i]);
        painter.drawText(180 + 20 * i, 100, 20, 24, Qt::AlignCenter, QString(m_captcha[i]));
    }

    QDialog::paintEvent(evt);
}

void QLoginDialog::showEvent(QShowEvent *evt)
{
    //在每次显示出登录框时 更新验证码
    m_captcha = getCaptcha();
    m_colors = getColor();

    QDialog::showEvent(evt);
}

void QLoginDialog::setValFunc(ValFunc valfunc)
{
    m_vf = valfunc;
}

void QLoginDialog::onTimerOut()
{
    m_colors = getColor();

    update();
}

QString QLoginDialog::getUser()
{
   return m_User;
}

QString QLoginDialog::getPwd()
{
   return m_Pwd;
}

QLoginDialog::~QLoginDialog()
{
    
}
