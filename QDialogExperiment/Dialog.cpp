#include "Dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent) , ModalBtn(this) , NormalBtn(this) , MixedBtn(this)
{
    ModalBtn.setText("Modal Dialog");
    ModalBtn.move(20, 20);
    ModalBtn.resize(100, 30);

    NormalBtn.setText("Modal Dialog");
    NormalBtn.move(20, 70);
    NormalBtn.resize(100, 30);

    MixedBtn.setText("Modal Dialog");
    MixedBtn.move(20, 120);
    MixedBtn.resize(100, 30);

    connect(&ModalBtn , SIGNAL(clicked()) , this ,SLOT(ModalBtn_Clicked()));
    connect(&NormalBtn , SIGNAL(clicked()) , this ,SLOT(NormalBtn_Clicked()));
    connect(&MixedBtn , SIGNAL(clicked()) , this ,SLOT(MixedBtn_Clicked()));

    resize(140, 170);
}

Dialog::~Dialog()
{
   qDebug() << "~Dialog()";
}

void Dialog::ModalBtn_Clicked()
{
   qDebug() << "ModalBtn_Clicked() Begin";
   QDialog dialog(this);

   //exec代表模态对话框
   dialog.exec();

  // done(Accepted); //用于给exec()提供返回值
   qDebug() << "ModalBtn_Clicked() End";
}

void Dialog::NormalBtn_Clicked()
{
   qDebug() << "NormalBtn_Clicked() Begin";

   //在堆上分配QDialog 这样不会出现点一下按钮 对话框闪现的问题
   //设置父类为当前对象 这样生成的对话框 会一直处于主窗口的上面
   QDialog* dialog = new QDialog(this);

   //设置此属性表示关闭非模态对话框后 自动释放在堆上申请当QDialog对象
   dialog->setAttribute(Qt::WA_DeleteOnClose);
   // show代表非模态对话框
   dialog->show();

  // done(Rejected);
   qDebug() << "NormalBtn_Clicked() End";
}

void Dialog::MixedBtn_Clicked()
{
   qDebug() << "MixedBtn_Clicked() Begin";
   QDialog* dialog = new QDialog(this);

   //设置此属性表示关闭非模态对话框后 自动释放在堆上申请当QDialog对象
   dialog->setAttribute(Qt::WA_DeleteOnClose);
   //设置当前的对话框为混合模式 同时具有非模态和模态的特性
   dialog->setModal(true);
   // show代表非模态对话框
   dialog->show();

  // done(100);
   qDebug() << "MixedBtn_Clicked() End";
}

