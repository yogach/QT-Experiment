#include "MainWindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

void MainWindow::showErrorMessage(QString message)
{
    QMessageBox msg(this);

    msg.setWindowTitle("Error");
    msg.setText(message);
    msg.setIcon(QMessageBox::Critical); //设置图标
    msg.setStandardButtons(QMessageBox::Ok);

    msg.exec(); //显示对话框
}

int MainWindow::showQueueMessage(QString message)
{
    QMessageBox msg(this);

    msg.setWindowTitle("Queue");
    msg.setText(message);
    msg.setIcon(QMessageBox::Question); //设置图标
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    return msg.exec(); //显示对话框

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

void MainWindow::preEditChange()
{
    if( m_isTextChanged )
    {
        int r = showQueueMessage("Do you want to save the changes to file?");

        switch(r)
        {
          case QMessageBox::Yes:
            saveCurrentData(m_filepath);
            break;

          case QMessageBox::No:
            m_isTextChanged = false;
            break;

          case QMessageBox::Cancel:
            break;
        }
    }
}

QString MainWindow::saveCurrentData(QString path)
{
    //当传入的路径为空时 需要选择一个文件进行保存
    if( path == "")
    {
      path = showFileDialog(QFileDialog::AcceptSave, "open");
    }

    if( path != "")
    {
        QFile file(path);

        if( file.open( QIODevice::WriteOnly | QIODevice::Text ))
        {
            QTextStream out(&file);

            out << mainTextEdit.toPlainText(); //使用辅助类完成数据写入

            file.close();

            setWindowTitle("NotePad - [" + path + "]" );

            m_isTextChanged = false;
        }
        else
        {
            showErrorMessage(QString("Save file error! \n\n") + "\"" + path + "\"");

            path = "";
        }
    }

    return path;
}

void MainWindow::onFileNew()
{
    preEditChange();

    if( !m_isTextChanged )
    {
        setWindowTitle("NotePad - [ New ]");
        mainTextEdit.clear(); //清除文本编辑框内容

        m_filepath = "";

        m_isTextChanged = false;
    }
}

void MainWindow::onFileOpen()
{

    preEditChange();

    if( !m_isTextChanged)
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

                 m_isTextChanged = false;

            }
            else
            {
                showErrorMessage(QString("Open file error! \n\n") + "\"" + path + "\"");
            }
        }

    }
}

void MainWindow::onFileSave()
{
    saveCurrentData(m_filepath);

}

void MainWindow::onFileSaveAs()
{
    saveCurrentData();
}

void MainWindow::onTextChanged()
{
    //从没改变到改变时 标题栏加一个*
    if( !m_isTextChanged )
    {
        setWindowTitle("*" + windowTitle());
    }

    m_isTextChanged = true;
}
