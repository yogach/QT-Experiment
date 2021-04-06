#include <QtGui/QApplication>
#include <QDialog>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w ;
    QDialog d(&w);

    w.show();
    w.setWindowTitle("QWidget");
    d.show();
    d.setWindowTitle("QDialog");

    return a.exec();
}
