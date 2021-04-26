#include <QtGui/QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::NewInstance();
    int ret = -1;


    if(w)
    {
      w->show();

      ret = a.exec();
    }

    return ret;
}
