#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainWindow(QWidget *parent = 0);
    MainWindow(const MainWindow&);
    MainWindow* operator=(const MainWindow&);

    bool construct();
    bool initMenuBar();
    bool initFileMenu(QMenuBar* mb);


    bool MakeAction(QAction*& action, QString text, int key);

public:
    static MainWindow* NewInstance();
    ~MainWindow();
};

#endif // MAINWINDOW_H
