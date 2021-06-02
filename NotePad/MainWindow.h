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
#include <QSharedPointer>
#include "FindDialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPlainTextEdit mainTextEdit;
    QLabel StatusLabel;
    QString m_filepath;
    bool m_isTextChanged;
    QSharedPointer<FindDialog> m_pFindDlg;

    MainWindow();
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
    QString saveCurrentData(QString path = "");
    void preEditChange();
    void openFileToEdit(QString path);
    QAction* findMenuBarAction(QString text);
    QAction* findToolBarAction(QString text);

protected:
    void closeEvent(QCloseEvent* e); //重载父类closeEvent事件
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);

private slots:
    void onFileNew();
    void onFileOpen();
    void onFileSave();
    void onFileSaveAs();
    void onFilePrint();
    void onFileExit();
    void onTextChanged();
    void onCopyAvailable(bool available);
    void onRedoAvailable(bool available);
    void onUndoAvailable(bool available);
    void onCursorPositionChanged();
    void onEditDelete();
    void onEditFind();
public:
    static MainWindow* NewInstance();
    ~MainWindow();
};

#endif // MAINWINDOW_H
