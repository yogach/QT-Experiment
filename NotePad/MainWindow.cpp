#include "MainWindow.h"
#include <QIcon>
#include <QSize>

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
    ret = ret && initToolBar();


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

bool MainWindow::initToolBar()
{
    bool ret = true;
    //获取主窗口中的menubar
    QToolBar* tb = addToolBar("Tool Bar");

    tb->setIconSize(QSize(18, 18));

    ret = ret && initFileToolItem(tb);
    tb->addSeparator();

    ret = ret && initEditToolItem(tb);
    tb->addSeparator();

    ret = ret && initFormatToolItem(tb);
    tb->addSeparator();

    ret = ret && initViewToolItem(tb);

    return ret;
}

bool MainWindow::initFileToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && MakeAction(action, "New", ":/res/pic/new.png");

    if( ret )
    {
      tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Open", ":/res/pic/open.png");

    if( ret )
    {
      tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Save", ":/res/pic/save.png");

    if( ret )
    {
       tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Save As", ":/res/pic/saveas.png");

    if( ret )
    {
       tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Print", ":/res/pic/print.png");

    if( ret )
    {
       tb->addAction(action);
    }

    return ret;
}

bool MainWindow::initEditToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && MakeAction(action, "Undo", ":/res/pic/undo.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Redo", ":/res/pic/redo.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Cut", ":/res/pic/cut.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Copy", ":/res/pic/copy.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Paste", ":/res/pic/paste.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Find", ":/res/pic/find.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Replace", ":/res/pic/replace.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Goto", ":/res/pic/goto.png");

    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::initFormatToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && MakeAction(action, "Auto Wrap", ":/res/pic/wrap.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Font", ":/res/pic/font.png");

    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::initViewToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && MakeAction(action, "Tool Bar", ":/res/pic/tool.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, "Status Bar", ":/res/pic/status.png");

    if( ret )
    {
        tb->addAction(action);
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

//创建一个action对象，参数为action, action名字，资源文件的位置
bool MainWindow::MakeAction(QAction*& action, QString tip, QString icon)
{
    bool ret = true;

    action = new QAction("", NULL);

    if( action != NULL)
    {
       action->setToolTip(tip);  //设置标签
       action->setIcon(QIcon(icon)); //设置资源文件位置
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
