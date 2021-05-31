#include "MainWindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QMap>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QList>
#include <QFileInfo>
#include <QUrl>
#include <QObjectList>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QPrintDialog>
#include <QPrinter>
#include <QApplication>
#include <QKeyEvent>
#include <QEvent>

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
    QMap<QString, QString> map;
    const char* filterArray[][2] =
    {
       {"Text Files (*.txt)", ".txt"},
       {"All Files (*)",      "*"   },
       {NULL, NULL}
    };

    for(int i=0; filterArray[i][0]!=NULL; i++)
    {
        filters.append(filterArray[i][0]) ;
        map.insert(filterArray[i][0], filterArray[i][1]); //设置键值对
    }

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

        if( mode == QFileDialog::AcceptSave )
        {
            QString postfix = map[fd.selectedFilter()]; //根据文件过滤器获取对应后缀名

            //使用endwith判断用户是否手动输入了后缀名
            if( (postfix != "*") && (!ret.endsWith(postfix)))
            {
               ret += postfix;
            }
        }
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

void MainWindow::openFileToEdit(QString path)
{
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

QAction* MainWindow::findMenuBarAction(QString text)
{
    QAction* ret = NULL;
    const QObjectList& list = menuBar()->children();

    for(int i=0; i<list.count(); i++)
    {
        QMenu* menu = dynamic_cast<QMenu*>(list[i]);

        if( menu != NULL)
        {
            QList<QAction*> actions = menu->actions();

            for(int j=0; j<actions.count(); j++)
            {
                if( actions[j]->text().startsWith(text) )
                {
                    ret = actions[j];
                    break;
                }
            }
        }
    }

    return ret;
}

QAction* MainWindow::findToolBarAction(QString text)
{

    QAction* ret = NULL;
    const QObjectList& list = children();

    for(int i=0; i<list.count(); i++)
    {
        QToolBar* toolBar = dynamic_cast<QToolBar*>(list[i]);

        if( toolBar != NULL)
        {
            QList<QAction*> actions = toolBar->actions();

            for(int j=0; j<actions.count(); j++)
            {
                if( actions[j]->toolTip().startsWith(text) )
                {
                    ret = actions[j];
                    break;
                }
            }
        }
    }

    return ret;
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

        openFileToEdit(path);
    }
}

void MainWindow::onFileSave()
{
    QString path = saveCurrentData(m_filepath);

    if( path!= "")
    {
      m_filepath = path;
    }
}

void MainWindow::onFileSaveAs()
{
    QString path = saveCurrentData();

    if( path!= "")
    {
      m_filepath = path;
    }
}

void MainWindow::onFilePrint()
{
    QPrintDialog dlg(this);

    dlg.setWindowTitle("Print");

    if( dlg.exec() == QPrintDialog::Accepted )
    {
        QPrinter* p = dlg.printer(); //得到所选的打印对象

        mainTextEdit.document()->print(p);
    }

}

void MainWindow::onFileExit()
{
    close();
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

void MainWindow::onCursorPositionChanged()
{
    int pos = mainTextEdit.textCursor().position(); //得到当前光标位置
    QString text = mainTextEdit.toPlainText(); //得到当前文本内容
    int col = 0, ln = 0, flag = -1;

    for(int i=0; i<pos; i++)
    {
        if( text[i] == '\n')
        {
          ln++;
          flag = i;
        }
    }

    flag++;

    col = pos - flag;

   StatusLabel.setText("Ln: " + QString::number(ln + 1) + "    Col: " + QString::number(col + 1));

}

//当点击了关闭按钮后会先调用到此函数
void MainWindow::closeEvent(QCloseEvent* e)
{
    preEditChange();

    //当文本内容未改变时，代表文本框内容已经保存或者已经放弃
    if( !m_isTextChanged)
    {
        QMainWindow::closeEvent(e);
    }
    else
    {
      e->ignore(); //忽略此次事件
    }

}

//重载拖拽事件
void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    //如果数据是一个路径
    if( e->mimeData()->hasUrls() )
    {
       e->acceptProposedAction();
    }
    else
    {
       e->ignore(); //忽略此事件
    }
}

//linux内此函数并没有执行 很奇怪
void MainWindow::dropEvent(QDropEvent *e)
{
    //如果数据是一个路径
    if( e->mimeData()->hasUrls() )
    {
        QList<QUrl> list = e->mimeData()->urls();
        QString path = list[0].toLocalFile(); //每次只获取第一个文件到路径
        QFileInfo info(path);

        if( info.isFile() )
        {
            preEditChange();

            if( !m_isTextChanged )
              openFileToEdit(path);
        }
    }
    else
    {
       e->ignore(); //忽略此事件
    }

}

//设置界面上当按钮状态
void MainWindow::onCopyAvailable(bool available)
{
    findMenuBarAction("Copy")->setEnabled(available);
    findMenuBarAction("Cut")->setEnabled(available);
    findToolBarAction("Copy")->setEnabled(available);
    findToolBarAction("Cut")->setEnabled(available);
}

void MainWindow::onRedoAvailable(bool available)
{
    findMenuBarAction("Redo")->setEnabled(available);
    findToolBarAction("Redo")->setEnabled(available);

}

void MainWindow::onUndoAvailable(bool available)
{
    findMenuBarAction("Undo")->setEnabled(available);
    findToolBarAction("Undo")->setEnabled(available);
}

void MainWindow::onEditDelete()
{
    //当按下edit中的delete之后 假设有delete按键按下

    //定义Key_Delete按键按下事件 没有其他修饰按键
    QKeyEvent keypress(QEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier);
    QKeyEvent keyrelease(QEvent::KeyRelease, Qt::Key_Delete, Qt::NoModifier);

    //发送事件
    QApplication::sendEvent(&mainTextEdit, &keypress);
    QApplication::sendEvent(&mainTextEdit, &keyrelease);

}
