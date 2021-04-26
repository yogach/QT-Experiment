#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret =  new MainWindow();

    if( ( ret == NULL ) || !ret->construct())
    {
       delete ret;
       ret = NULL;
    }

    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;

    ret = ret && initMenuBar();


    return ret;
}

bool MainWindow::initMenuBar()
{
   bool ret = true;
   //获取主窗口中的menubar
   QMenuBar* mb = menuBar();

   ret = ret && initFileMenu(mb);

   return ret;
}

bool MainWindow::initFileMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("File(&F)"); //新建一个QMenu对象并设置快捷键为F
   bool ret = (menu != NULL);

   if( ret )
   {
       QAction* action = NULL;

       ret = ret && MakeAction(action, "New(&N)", Qt::CTRL + Qt::Key_N);

       if( ret )
       {
          menu->addAction(action); // add Action item to Menu
       }

       ret = ret && MakeAction(action, "New Window(&W)", Qt::CTRL + Qt::Key_W);

       if( ret )
       {
          menu->addAction(action); // add Action item to Menu
       }

       ret = ret && MakeAction(action, "Open(&N)...", Qt::CTRL + Qt::Key_O);

       if( ret )
       {
          menu->addAction(action); // add Action item to Menu
       }

       ret = ret && MakeAction(action, "Save(&S)", Qt::CTRL + Qt::Key_S);

       if( ret )
       {
          menu->addAction(action); // add Action item to Menu
       }

       ret = ret && MakeAction(action, "Save As(&A)...", 0);

       if( ret )
       {
          menu->addAction(action); // add Action item to Menu
       }

       menu->addSeparator(); //在两个action之间添加一个分隔符

       ret = ret && MakeAction(action, "Exit(&X)", Qt::CTRL + Qt::Key_X);

       if( ret )
       {
          menu->addAction(action); // add Action item to Menu
       }

   }

   if( ret )
   {
      mb->addMenu(menu); // add Menu add to application Menu Bar
   }
   else
   {
      delete menu;
   }


   return ret;
}

//创建一个action对象，参数为action, action名字，对应快捷键
bool MainWindow::MakeAction(QAction*& action, QString text, int key)
{
    bool ret = true;

    action = new QAction(text, NULL);

    if( action != NULL)
    {
       action->setShortcut(key);
    }
    else
    {
      ret = false;
    }

    return ret;
}

MainWindow::~MainWindow()
{
    
}
