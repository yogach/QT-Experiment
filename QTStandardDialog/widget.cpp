#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QFontDialog>
#include <QProgressDialog>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPrinter>

Widget::Widget(QWidget *parent): QWidget(parent) ,
    SimpleMsgBtn(this)  , CustomMsgBtn(this) , OpenFileBtn(this) , SaveFileBtn(this), ColorDialogBtn(this) ,InputDialogBtn(this),
    FontDialogBtn(this) , ProgressDialogBtn(this) , PrintDialogBtn(this)
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

    ColorDialogBtn.setText("Color Dialog");
    ColorDialogBtn.move(20, 220);
    ColorDialogBtn.resize(180, 30);

    InputDialogBtn.setText("Input Dialog");
    InputDialogBtn.move(20, 270);
    InputDialogBtn.resize(180, 30);


    FontDialogBtn.setText("font Dialog");
    FontDialogBtn.move(20, 320);
    FontDialogBtn.resize(180, 30);

    ProgressDialogBtn.setText("progress Dialog");
    ProgressDialogBtn.move(20, 370);
    ProgressDialogBtn.resize(180, 30);

    PrintDialogBtn.setText("Print Dialog");
    PrintDialogBtn.move(20, 420);
    PrintDialogBtn.resize(180, 30);


    connect(&SimpleMsgBtn , SIGNAL(clicked()) , this , SLOT(SimpleMsgBtn_Clicked()));
    connect(&CustomMsgBtn , SIGNAL(clicked()) , this , SLOT(CustomMsgBtn_Clicked()));
    connect(&OpenFileBtn , SIGNAL(clicked()) , this , SLOT(OpenFileBtn_Clicked()));
    connect(&SaveFileBtn , SIGNAL(clicked()) , this , SLOT(SaveFileBtn_Clicked()));

    connect(&ColorDialogBtn , SIGNAL(clicked()) , this , SLOT(ColorDialogBtn_Clicked()));
    connect(&InputDialogBtn , SIGNAL(clicked()) , this , SLOT(InputDialogBtn_Clicked()));

    connect(&FontDialogBtn , SIGNAL(clicked()) , this , SLOT(FontDialogBtn_Clicked()));
    connect(&ProgressDialogBtn , SIGNAL(clicked()) , this , SLOT(ProgressDialogBtn_Clicked()));
    connect(&PrintDialogBtn , SIGNAL(clicked()) , this , SLOT(PrintDialogBtn_Clicked()));



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

void Widget::ColorDialogBtn_Clicked()
{
    QColorDialog dlg(this);

    dlg.setWindowTitle("color dialog");
    //设置初始颜色
    dlg.setCurrentColor(Qt::red);

    if(dlg.exec() == QColorDialog::Accepted)
    {
       QColor color = dlg.selectedColor();

       qDebug() << color;
       qDebug() << color.red();
       qDebug() << color.green();
       qDebug() << color.blue();
       qDebug() << color.hue();
       qDebug() << color.saturation();
       qDebug() << color.value();
    }

}

void Widget::InputDialogBtn_Clicked()
{
    QInputDialog dlg(this);

    dlg.setWindowTitle("Input Dialog.. ");
    //设置提示标签
    dlg.setLabelText("Please enter a integer");
    //设置可以输入的类型
    dlg.setInputMode(QInputDialog::IntInput);

    if(dlg.exec() == QInputDialog::Accepted)
    {
       qDebug() << dlg.intValue();
    }
}

void Widget::FontDialogBtn_Clicked()
{
    QFontDialog dlg(this);

   dlg.setWindowTitle("Font Dialog Test");
   dlg.setCurrentFont(QFont("Courier New", 10, QFont::Bold));

   if(dlg.exec() == QFontDialog::Accepted)
   {
     qDebug() << dlg.selectedFont();
   }

}

void Widget::PrintDialogBtn_Clicked()
{
    QPrintDialog dlg(this);

    dlg.setWindowTitle(" QPrintDialog Test");

    if(dlg.exec() == QPrintDialog::Accepted)
    {
       //得到选择的打印对象
       QPrinter * p = dlg.printer();
       QTextDocument td;

       td.setPlainText("Printer object Test");

       p->setOutputFileName("test.pdf");

       td.print(p);

    }


}

void Widget::ProgressDialogBtn_Clicked()
{
    QProgressDialog dlg(this);

    dlg.setWindowTitle("QProgress dialog test");
    dlg.setMinimum(0);
    dlg.setMaximum(100);
    dlg.setValue(33.5);

    // create a new thread

    dlg.exec();

}


Widget::~Widget()
{

}

