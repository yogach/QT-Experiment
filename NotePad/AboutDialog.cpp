#include "AboutDialog.h"
#include <QPixmap>
#include <QPalette>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent), m_logoLbl(this), m_qqGroup(this), m_infoEdit(this), m_closeBtn(this)
{
    QPixmap pm(":/res/pic/dt.png");

    //对原图进行缩放 并保持长宽比
    pm = pm.scaled(120, 120, Qt::KeepAspectRatio);

    m_logoLbl.setPixmap(pm);
    m_logoLbl.move(20, 20);
    m_logoLbl.resize(120, 120);


    QPalette p = m_infoEdit.palette();

    //修改m_infoEdit的背景色
    p.setColor(QPalette::Active, QPalette::Base, p.color(QPalette::Active, QPalette::Background));
    p.setColor(QPalette::Inactive, QPalette::Base, p.color(QPalette::Inactive, QPalette::Background));

    m_infoEdit.setPalette(p);
    m_infoEdit.setFrameStyle(QFrame::NoFrame); //设置成无边框
    m_infoEdit.move(200, 30);
    m_infoEdit.resize(180, 130);
    m_infoEdit.setReadOnly(true);
    m_infoEdit.insertPlainText("NotePad Project\n\nPlatform: Qt 4.7.4\n\nVersion: 1.0.0\n\nCopyright: D.T.Software");

    m_qqGroup.move(22, 184);
    m_qqGroup.setText("QQ Group: 199546072");

    m_closeBtn.setText("Close");
    m_closeBtn.move(273, 175);
    m_closeBtn.resize(100, 30);

    setFixedSize(390, 230);
    setWindowTitle("About Notepad");

    connect(&m_closeBtn, SIGNAL(clicked()), this, SLOT(close()));
}


