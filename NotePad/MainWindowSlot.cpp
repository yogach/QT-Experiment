#include "MainWindow.h"
#include <QMessageBox>
#include <QTextStream>

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

             setWindowTitle("NotePad - [" + m_filepath + "]" );

        }
        else
        {
            showErrorMessage(QString("Open file error! \n\n") + "\"" + path + "\"");
        }
    }
}

void MainWindow::onFileSave()
{

    if( m_filepath == "")
    {
      m_filepath = showFileDialog(QFileDialog::AcceptSave, "open");
    }

    if( m_filepath != "")
    {
        QFile file(m_filepath);

        if( file.open( QIODevice::WriteOnly | QIODevice::Text ))
        {
            QTextStream out(&file);

            out << mainTextEdit.toPlainText(); //使用辅助类完成数据写入

            file.close();

            setWindowTitle("NotePad - [" + m_filepath + "]" );
        }
        else
        {
            showErrorMessage(QString("Save file error! \n\n") + "\"" + m_filepath + "\"");

            m_filepath = "";
        }
    }
}

void MainWindow::onFileSaveAs()
{
    QString path = showFileDialog(QFileDialog::AcceptSave, "open");

    if( path != "")
    {
        QFile file(path);

        if( file.open( QIODevice::WriteOnly | QIODevice::Text ))
        {
            QTextStream out(&file);

            out << mainTextEdit.toPlainText(); //使用辅助类完成数据写入

            file.close();

            setWindowTitle("NotePad - [" + m_filepath + "]" );
        }
        else
        {
            showErrorMessage(QString("Save As file error! \n\n") + "\"" + m_filepath + "\"");

            m_filepath = "";
        }
    }
}
