#include "AboutDialog.h"
#include <QPixmap>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent), m_logoLbl(this), m_infoEdit(this), m_closeBtn(this)
{
    QPixmap pm(":/res/pic/dt.png");

    m_logoLbl.setPixmap(pm);
    m_logoLbl.move(20, 20);
    m_logoLbl.resize(120, 120);

    m_infoEdit.move(200, 30);
    m_infoEdit.resize(180, 130);


    m_infoEdit.setReadOnly(true);
    m_infoEdit.insertPlainText("NotePad Project\n\nPlatform: Qt 4.7.4\n\nVersion: 1.0.0\n\nCopyright: D.T.Software");

    m_closeBtn.setText("Close");
    m_closeBtn.move(273, 175);
    m_closeBtn.resize(100, 30);

    connect(&m_closeBtn, SIGNAL(clicked()), this, SLOT(onCloseBtnClicked()));
}

void AboutDialog::onCloseBtnClicked()
{
    close();
}
