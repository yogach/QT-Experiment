#include <QtGui/QApplication>
#include <QDialog>
#include <QWidget>
#include "Dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;

    d.show();

    return a.exec();
}
