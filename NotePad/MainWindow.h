#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QPlainTextEdit>
#include <QLabel>
#include <QFileDialog>
#include <QFile>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPlainTextEdit mainTextEdit;
    QLabel StatusLabel;
    QString m_filepath;
    bool m_isTextChanged;

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

    bool MakeAction(QAction*& action, QWidget* parent, QString text, int key);
    bool MakeAction(QAction*& action, QWidget* parent, QString tip, QString icon);

    void showErrorMessage(QString message);
    int showQueueMessage(QString message);
    QString showFileDialog(QFileDialog::AcceptMode mode, QString title);    

    QString saveCurrentData(QString path);
private slots:
    void onFileOpen();
    void onFileSave();
    void onFileSaveAs();
    void onTextChanged();

public:
    static MainWindow* NewInstance();
    ~MainWindow();
};

#endif // MAINWINDOW_H
