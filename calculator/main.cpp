#include <QtGui/QApplication>
#include "QCalculatorUI.h"
#include "QCalculatorDec.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCalculatorUI* calUI = QCalculatorUI::NewInstance();
    int ret = -1;

    if(calUI != NULL)
    {
       calUI->show();

       ret = a.exec();

       delete calUI;
    }

    return ret;

    /*
    QCalculatorDec c;
    QString exp = " -8 + ( 2 - -1) * 3"; //

    c.expression(exp);

    qDebug() << c.expression();
*/

    return 0;
}
