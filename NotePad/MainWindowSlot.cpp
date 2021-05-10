#include "MainWindow.h"
#include <QMessageBox>

void MainWindow::showErrorMessage(QString message)
{
    QMessageBox msg;

    msg.setWindowTitle("Error");
    msg.setText(message);
    msg.setIcon(QMessageBox::Critical); //设置图标
    msg.setStandardButtons(QMessageBox::Ok);

    msg.exec(); //显示对话框
}

QString MainWindow::showFileDialog(QFileDialog::AcceptMode mode, QString title)
{
    QString ret = "";
    QFileDialog fd(this);
    QStringList filters;

    filters.append("Text Files (*.txt)");
    filters.append("ALL Files (*)");

    fd.setWindowTitle(title); //设置窗口标题
    fd.setAcceptMode(mode); //设置打开或关闭方式
    fd.setFilters(filters); //设置文件过滤器

    if( mode == QFileDialog::AcceptOpen )
    {
       fd.setFileMode( QFileDialog::ExistingFile );
    }

    if( fd.exec() == QFileDialog::Accepted )
    {
        ret = fd.selectedFiles()[0];
    }

    return ret;
}

void MainWindow::onFileOpen()
{
    //得到打开的文件路径
    QString path = showFileDialog(QFileDialog::AcceptOpen, "open");

    if( path != "")
    {
        QFile file(path);//使用QFile进行操作

        if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
             mainTextEdit.setPlainText( QString(file.readAll()));

             file.close();

             m_filepath = path;

        }
        else
        {
            showErrorMessage(QString("Open file error! \n\n") + "\"" + path + "\"");
        }
    }
}
