#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent): QWidget(parent) ,
    SimpleMsgBtn(this)  , CustomMsgBtn(this) , OpenFileBtn(this) , SaveFileBtn(this)
{
    SimpleMsgBtn.setText("Simple Message Dialog");
    SimpleMsgBtn.move(20, 20);
    SimpleMsgBtn.resize(180, 30);

    CustomMsgBtn.setText("Custom Message Dialog");
    CustomMsgBtn.move(20, 70);
    CustomMsgBtn.resize(180, 30);

    OpenFileBtn.setText("Open File Dialog");
    OpenFileBtn.move(20, 120);
    OpenFileBtn.resize(180, 30);

    SaveFileBtn.setText("Save File Dialog");
    SaveFileBtn.move(20, 170);
    SaveFileBtn.resize(180, 30);

    connect(&SimpleMsgBtn , SIGNAL(clicked()) , this , SLOT(SimpleMsgBtn_Clicked()));
    connect(&CustomMsgBtn , SIGNAL(clicked()) , this , SLOT(CustomMsgBtn_Clicked()));
    connect(&OpenFileBtn , SIGNAL(clicked()) , this , SLOT(OpenFileBtn_Clicked()));
    connect(&SaveFileBtn , SIGNAL(clicked()) , this , SLOT(SaveFileBtn_Clicked()));

}

void Widget::SimpleMsgBtn_Clicked()
{
    QMessageBox msg(this);

    msg.setText("This is a message dialog!");

    msg.exec();

}

void Widget::CustomMsgBtn_Clicked()
{
    QMessageBox msg(this);

    msg.setWindowTitle("Message Title");
    msg.setText("This is a detail message dialog!");
    msg.setIcon(QMessageBox::Information);
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);

    if(msg.exec() == QMessageBox::Ok)
    {
       qDebug() << "Ok button is clicked!";
    }

}

void Widget::OpenFileBtn_Clicked()
{
    QFileDialog dlg(this);

    //设置为打开文件
    dlg.setAcceptMode(QFileDialog::AcceptOpen);

    //QFileDialog::ExistingFile 代表打开单个文件
    //QFileDialog::ExistingFiles 代表打开多个文件
    dlg.setFileMode(QFileDialog::ExistingFile);

    if(dlg.exec() == QFileDialog::Accepted)
    {
       QStringList fs = dlg.selectedFiles();

       for(int i = 0; i < fs.count() ; i++)
           qDebug() << fs[i];
    }

}

void Widget::SaveFileBtn_Clicked()
{
    QFileDialog dlg(this);

    //设置为保存文件
    dlg.setAcceptMode(QFileDialog::AcceptSave);
    //设置过滤器 只能看到指定后缀的文件
    dlg.setFilter("Text(*.txt)");

    if(dlg.exec() == QFileDialog::Accepted)
    {
       QStringList fs = dlg.selectedFiles();

       for(int i = 0; i < fs.count() ; i++)
           qDebug() << fs[i];
    }

}

Widget::~Widget()
{

}

