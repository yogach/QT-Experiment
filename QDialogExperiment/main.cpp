#include <QtGui/QApplication>
#include <QDialog>
#include <QWidget>
#include "Dialog.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;
    int r = d.exec();

    //d.show();
    if( r == QDialog::Accepted )
    {
        qDebug() << "Accepted";
    }
    else if( r == QDialog::Rejected )
    {
        qDebug() << "Rejected";
    }
    else
    {
        qDebug() << r;
    }

    return r;
}
