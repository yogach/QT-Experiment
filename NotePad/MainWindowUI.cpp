#include "MainWindow.h"
#include <QIcon>
#include <QSize>
#include <QStatusBar>
#include <QLabel>
#include <QPalette>
#include "AppConfig.h"

MainWindow::MainWindow() :
    m_pFindDlg(new FindDialog(this, &mainTextEdit)) ,
    m_pReplaceDlg(new ReplaceDialog(this, &mainTextEdit))
{
    setWindowTitle("NotePad - [ New ]" );

    setAcceptDrops(true); //设置可以接收拖拽事件

    m_filepath = "";
    m_isTextChanged = false;
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
    AppConfig config;


    ret = ret && initMenuBar();
    ret = ret && initToolBar();
    ret = ret && initStatusBar();
    ret = ret && initMainEdit();

    //如果读取数据成功
    if( config.isVaild() )
    {
        mainTextEdit.setFont(config.editorFont());

        if( !config.isAutoWrap() )
        {
           mainTextEdit.setLineWrapMode(QPlainTextEdit::NoWrap);
           findMenuBarAction("Auto Wrap")->setChecked(false);
           findToolBarAction("Auto Wrap")->setChecked(false);
        }

        if( !config.isToolBarVisible() )
        {
           toolBar()->setVisible(false);
           findMenuBarAction("Tool Bar")->setChecked(false);
           findToolBarAction("Tool Bar")->setChecked(false);
        }

        if( !config.isStatusBarVisible() )
        {
           statusBar()->setVisible(false);
           findMenuBarAction("Status Bar")->setChecked(false);
           findToolBarAction("Status Bar")->setChecked(false);
        }

        move(config.mainWindowPoint());
        resize(config.mainWindowSize());

    }

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

bool MainWindow::initStatusBar()
{
    bool ret = true;
    QStatusBar* sb = statusBar();
    QLabel* label = new QLabel("D.T.Software");

    if( label != NULL)
    {
        StatusLabel.setText("Ln: 1    Col: 1");
        StatusLabel.setMinimumWidth(200);
        StatusLabel.setAlignment(Qt::AlignCenter);

        label->setMinimumWidth(200);
        label->setAlignment(Qt::AlignCenter);

        sb->addPermanentWidget(new QLabel()); //此行代码的作用是在状态栏添加一个分隔符
        sb->addPermanentWidget(&StatusLabel);
        sb->addPermanentWidget(label);
    }
    else
    {
       ret = false;
    }

    return ret;
}

bool MainWindow::initMainEdit()
{
    bool ret = true;
    QPalette p = mainTextEdit.palette(); //获取调色板

    //获取激活态的高亮颜色后来设置非激活态的颜色
    p.setColor(QPalette::Inactive, QPalette::Highlight, p.color(QPalette::Active, QPalette::Highlight));
    p.setColor(QPalette::Inactive, QPalette::HighlightedText, p.color(QPalette::Active, QPalette::HighlightedText));

    mainTextEdit.setPalette(p);

    mainTextEdit.setParent(this); //设置父组件

    setCentralWidget(&mainTextEdit); //设置maiawindow的中心组件

    connect(&mainTextEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()));

    //连接三个操作允许函数
    connect(&mainTextEdit, SIGNAL(copyAvailable(bool)), this, SLOT(onCopyAvailable(bool)));
    connect(&mainTextEdit, SIGNAL(undoAvailable(bool)), this, SLOT(onUndoAvailable(bool)));
    connect(&mainTextEdit, SIGNAL(redoAvailable(bool)), this, SLOT(onRedoAvailable(bool)));

    //映射光标变动信号
    connect(&mainTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorPositionChanged()));
    return ret;
}

bool MainWindow::initFileMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("File(&F)" , mb); //新建一个QMenu对象并设置快捷键为F , 设置父组件为mb
   bool ret = (menu != NULL);

   if( ret )
   {
       QAction* action = NULL;

       ret = ret && MakeAction(action, menu, "New(&N)", Qt::CTRL + Qt::Key_N);

       if( ret )
       {
           connect(action, SIGNAL(triggered()), this, SLOT(onFileNew()));
           menu->addAction(action); // add Action item to Menu
       }

       ret = ret && MakeAction(action, menu, "Open(&O)...", Qt::CTRL + Qt::Key_O);

       if( ret )
       {
           connect(action, SIGNAL(triggered()), this, SLOT(onFileOpen()));
           menu->addAction(action);
       }

       ret = ret && MakeAction(action, menu, "Save(&S)", Qt::CTRL + Qt::Key_S);

       if( ret )
       {
           connect(action, SIGNAL(triggered()), this, SLOT(onFileSave()));
           menu->addAction(action);
       }

       ret = ret && MakeAction(action, menu, "Save As(&A)...", Qt::CTRL + Qt::SHIFT + Qt::Key_P);

       if( ret )
       {
           connect(action, SIGNAL(triggered()), this, SLOT(onFileSaveAs()));
           menu->addAction(action);
       }

       menu->addSeparator(); //在两个action之间添加一个分隔符

       ret = ret && MakeAction(action, menu, "Page Setting(&U)...", 0);

       if( ret )
       {
           menu->addAction(action);
       }

       ret = ret && MakeAction(action, menu, "Print(&P)...", Qt::CTRL + Qt::Key_P);

       if( ret )
       {
           connect(action, SIGNAL(triggered()), this, SLOT(onFilePrint()));
           menu->addAction(action);
       }


       menu->addSeparator();

       ret = ret && MakeAction(action, menu, "Exit(&X)", 0);

       if( ret )
       {
           connect(action, SIGNAL(triggered()), this, SLOT(onFileExit()));
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


    QMenu* menu = new QMenu("Edit(&E)", mb); //新建一个QMenu对象并设置快捷键为F
    bool ret = (menu != NULL);

    if( ret )
    {
      QAction* action = NULL;

      ret = ret && MakeAction(action, menu, "Undo(&U)", Qt::CTRL + Qt::Key_Z);

      if( ret )
      {
          action->setEnabled(false);
          connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(undo())); //使用plaintedit内的槽函数
          menu->addAction(action);
      }

      ret = ret && MakeAction(action, menu, "Redo(&R)...", Qt::CTRL + Qt::Key_Y);

      if( ret )
      {
          action->setEnabled(false);
          connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(redo()));
          menu->addAction(action);
      }

      ret = ret && MakeAction(action, menu, "Cut(&T)", Qt::CTRL + Qt::Key_X);

      if( ret )
      {
          action->setEnabled(false);
          connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(cut()));
          menu->addAction(action);
      }

      ret = ret && MakeAction(action, menu, "Copy(&C)...", Qt::CTRL + Qt::Key_C);

      if( ret )
      {
          action->setEnabled(false);
          connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(copy()));
          menu->addAction(action);
      }

      ret = ret && MakeAction(action, menu, "Paste(&P)...", Qt::CTRL + Qt::Key_V);

      if( ret )
      {

          connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(paste()));
          menu->addAction(action);
      }

      ret = ret && MakeAction(action, menu, "Delete(&L)...", Qt::Key_Delete);

      if( ret )
      {
          connect(action, SIGNAL(triggered()), this, SLOT(onEditDelete()));
          menu->addAction(action);
      }

      ret = ret && MakeAction(action, menu, "Find(&F)...", Qt::CTRL + Qt::Key_F);

      if( ret )
      {
          connect(action, SIGNAL(triggered()), this, SLOT(onEditFind()));
          menu->addAction(action);
      }


      menu->addSeparator();

      ret = ret && MakeAction(action, menu, "Replace(&R)...", Qt::CTRL + Qt::Key_H);

      if( ret )
      {
          connect(action, SIGNAL(triggered()), this, SLOT(onEditReplace()));
          menu->addAction(action);
      }

      ret = ret && MakeAction(action, menu, "Goto(&G)...", Qt::CTRL + Qt::Key_G);

      if( ret )
      {
          connect(action, SIGNAL(triggered()), this, SLOT(onEditGoto()));
          menu->addAction(action);
      }

      menu->addSeparator();

      ret = ret && MakeAction(action, menu, "Select All(&A)", Qt::CTRL + Qt::Key_A);

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
    QMenu* menu = new QMenu("Format(&O)", mb);
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && MakeAction(action, menu, "Auto Wrap(&W)", 0);

        if( ret )
        {
            action->setCheckable(true);
            action->setChecked(true);
            connect(action, SIGNAL(triggered()), this, SLOT(onFormatWrap()));
            menu->addAction(action);
        }

        ret = ret && MakeAction(action, menu, "Font(&F)...", 0);

        if( ret )
        {
            connect(action, SIGNAL(triggered()), this, SLOT(onFormatFont()));
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
    QMenu* menu = new QMenu("View(&V)", mb);
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && MakeAction(action, menu, "Tool Bar(&T)", 0);

        if( ret )
        {
            action->setCheckable(true);
            action->setChecked(true);
            connect(action, SIGNAL(triggered()), this, SLOT(onViewToolBar()));
            menu->addAction(action);
        }

        ret = ret && MakeAction(action, menu, "Status Bar(&S)", 0);

        if( ret )
        {
            action->setCheckable(true);
            action->setChecked(true);
            connect(action, SIGNAL(triggered()), this, SLOT(onViewStatusBar()));
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
    QMenu* menu = new QMenu("Help(&H)", mb);
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && MakeAction(action, menu, "User Manual", 0);

        if( ret )
        {
            connect(action, SIGNAL(triggered()), this, SLOT(onHelpManual()));
            menu->addAction(action);
        }

        ret = ret && MakeAction(action, menu, "About NotePad...", 0);

        if( ret )
        {
            connect(action, SIGNAL(triggered()), this, SLOT(onHelpAbout()));
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

    ret = ret && MakeAction(action, tb, "New", ":/res/pic/new.png");

    if( ret )
    {
        connect(action, SIGNAL(triggered()), this, SLOT(onFileNew()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Open", ":/res/pic/open.png");

    if( ret )
    {
        connect(action, SIGNAL(triggered()), this, SLOT(onFileOpen()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Save", ":/res/pic/save.png");

    if( ret )
    {
        connect(action, SIGNAL(triggered()), this, SLOT(onFileSave()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Save As", ":/res/pic/saveas.png");

    if( ret )
    {
        connect(action, SIGNAL(triggered()), this, SLOT(onFileSaveAs()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Print", ":/res/pic/print.png");

    if( ret )
    {
        connect(action, SIGNAL(triggered()), this, SLOT(onFilePrint()));
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::initEditToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && MakeAction(action, tb,  "Undo", ":/res/pic/undo.png");

    if( ret )
    {
        action->setEnabled(false);
        connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(undo()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Redo", ":/res/pic/redo.png");

    if( ret )
    {
        action->setEnabled(false);
        connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(redo()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Cut", ":/res/pic/cut.png");

    if( ret )
    {
        action->setEnabled(false);
        connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(cut()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Copy", ":/res/pic/copy.png");

    if( ret )
    {
        action->setEnabled(false);
        connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(copy()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Paste", ":/res/pic/paste.png");

    if( ret )
    {

        connect(action, SIGNAL(triggered()), &mainTextEdit, SLOT(paste()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Find", ":/res/pic/find.png");

    if( ret )
    {
        connect(action, SIGNAL(triggered()), this, SLOT(onEditFind()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Replace", ":/res/pic/replace.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Goto", ":/res/pic/goto.png");

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

    ret = ret && MakeAction(action, tb,  "Auto Wrap", ":/res/pic/wrap.png");

    if( ret )
    {
        action->setCheckable(true);
        action->setChecked(true);
        connect(action, SIGNAL(triggered()), this, SLOT(onFormatWrap()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Font", ":/res/pic/font.png");

    if( ret )
    {
        connect(action, SIGNAL(triggered()), this, SLOT(onFormatFont()));
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::initViewToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && MakeAction(action, tb,  "Tool Bar", ":/res/pic/tool.png");

    if( ret )
    {
        action->setCheckable(true);
        action->setChecked(true);
        connect(action, SIGNAL(triggered()), this, SLOT(onViewToolBar()));
        tb->addAction(action);
    }

    ret = ret && MakeAction(action, tb,  "Status Bar", ":/res/pic/status.png");

    if( ret )
    {
        action->setCheckable(true);
        action->setChecked(true);
        connect(action, SIGNAL(triggered()), this, SLOT(onViewStatusBar()));
        tb->addAction(action);
    }

    return ret;
}

//创建一个action对象，参数为action, action名字，对应快捷键
bool MainWindow::MakeAction(QAction*& action, QWidget* parent, QString text, int key)
{
    bool ret = true;

    action = new QAction(text, parent);

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
bool MainWindow::MakeAction(QAction*& action , QWidget* parent, QString tip, QString icon)
{
    bool ret = true;

    action = new QAction("", parent);

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

QToolBar* MainWindow::toolBar()
{
    QToolBar* ret = NULL;
    const QObjectList& list = children(); //得到窗口上到所有子组件

    for(int i=0; i<list.count(); i++)
    {
        //只有在子组件为QToolBar类型时 dynamic_cast才会转化成功
        QToolBar* toolBar = dynamic_cast<QToolBar*>(list[i]);

        if( toolBar != NULL)
        {
           ret = toolBar;
           break;
        }
    }

    return ret;
}


MainWindow::~MainWindow()
{
    
}
