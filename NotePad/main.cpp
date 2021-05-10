#include <QtGui/QApplication>
#include "MainWindow.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::NewInstance();
    int ret = -1;

    //qDebug() << QString("Open file error! \n\n") + "\""  "\"";

    if(w)
    {
      w->show();

      ret = a.exec();
    }

    delete w;

    return ret;
}
