#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QPlainTextEdit>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPlainTextEdit mainTextEdit;
    QLabel StatusLabel;

    MainWindow(QWidget *parent = 0);
    MainWindow(const MainWindow&);
    MainWindow* operator=(const MainWindow&);

    bool construct();
    bool initMenuBar();
    bool initToolBar();
    bool initStatusBar();
    bool initMainEdit();

    bool initFileMenu(QMenuBar* mb);    
    bool initEditMenu(QMenuBar* mb);
    bool initFormatMenu(QMenuBar* mb);
    bool initViewMenu(QMenuBar* mb);
    bool initHelpMenu(QMenuBar* mb);

    bool initFileToolItem(QToolBar* tb);
    bool initEditToolItem(QToolBar* tb);
    bool initFormatToolItem(QToolBar* tb);
    bool initViewToolItem(QToolBar* tb);

    bool MakeAction(QAction*& action, QString text, int key);
    bool MakeAction(QAction*& action, QString tip, QString icon);

public:
    static MainWindow* NewInstance();
    ~MainWindow();
};

#endif // MAINWINDOW_H
