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
   ret = ret && initEditMenu(mb);
   ret = ret && initFormatMenu(mb);
   ret = ret && initViewMenu(mb);
   ret = ret && initHelpMenu(mb);

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
          menu->addAction(action);
       }

       ret = ret && MakeAction(action, "Open(&O)...", Qt::CTRL + Qt::Key_O);

       if( ret )
       {
          menu->addAction(action);
       }

       ret = ret && MakeAction(action, "Save(&S)", Qt::CTRL + Qt::Key_S);

       if( ret )
       {
          menu->addAction(action);
       }

       ret = ret && MakeAction(action, "Save As(&A)...", Qt::CTRL + Qt::SHIFT + Qt::Key_P);

       if( ret )
       {
          menu->addAction(action);
       }

       menu->addSeparator(); //在两个action之间添加一个分隔符

       ret = ret && MakeAction(action, "Page Setting(&U)...", 0);

       if( ret )
       {
          menu->addAction(action);
       }

       ret = ret && MakeAction(action, "Print(&P)...", Qt::CTRL + Qt::Key_P);

       if( ret )
       {
          menu->addAction(action);
       }


       menu->addSeparator();

       ret = ret && MakeAction(action, "Exit(&X)", 0);

       if( ret )
       {
          menu->addAction(action);
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

bool MainWindow::initEditMenu(QMenuBar* mb)
{


    QMenu* menu = new QMenu("Edit(&E)"); //新建一个QMenu对象并设置快捷键为F
    bool ret = (menu != NULL);

    if( ret )
    {
      QAction* action = NULL;

      ret = ret && MakeAction(action, "Undo(&U)", Qt::CTRL + Qt::Key_Z);

      if( ret )
      {
         menu->addAction(action);
      }

      ret = ret && MakeAction(action, "Redo(&R)...", Qt::CTRL + Qt::Key_Y);

      if( ret )
      {
         menu->addAction(action);
      }

      ret = ret && MakeAction(action, "Cut(&T)", Qt::CTRL + Qt::Key_X);

      if( ret )
      {
         menu->addAction(action);
      }

      ret = ret && MakeAction(action, "Copy(&C)...", Qt::CTRL + Qt::Key_C);

      if( ret )
      {
         menu->addAction(action);
      }

      ret = ret && MakeAction(action, "Paste(&P)...", Qt::CTRL + Qt::Key_V);

      if( ret )
      {
         menu->addAction(action);
      }

      ret = ret && MakeAction(action, "Delete(&L)...", Qt::Key_Delete);

      if( ret )
      {
         menu->addAction(action);
      }

      ret = ret && MakeAction(action, "Find(&F)...", Qt::CTRL + Qt::Key_F);

      if( ret )
      {
         menu->addAction(action);
      }


      menu->addSeparator();

      ret = ret && MakeAction(action, "Replace(&R)...", Qt::CTRL + Qt::Key_H);

      if( ret )
      {
         menu->addAction(action);
      }

      ret = ret && MakeAction(action, "Goto(&G)...", Qt::CTRL + Qt::Key_G);

      if( ret )
      {
          menu->addAction(action);
      }

      menu->addSeparator();

      ret = ret && MakeAction(action, "Select All(&A)", Qt::CTRL + Qt::Key_A);

      if( ret )
      {
          menu->addAction(action);
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

bool MainWindow::initFormatMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Format(&O)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && MakeAction(action, "Auto Wrap(&W)", 0);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && MakeAction(action, "Font(&F)...", 0);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initViewMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("View(&V)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && MakeAction(action, "Tool Bar(&T)", 0);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && MakeAction(action, "Status Bar(&S)", 0);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initHelpMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Help(&H)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && MakeAction(action, "User Manual", 0);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && MakeAction(action, "About NotePad...", 0);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
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
