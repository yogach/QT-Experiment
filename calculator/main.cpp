#include <QtGui/QApplication>
#include "Qcalculatorui.h"
#include "Qcalculatordec.h"

int main(int argc, char *argv[])
{
   /* QApplication a(argc, argv);
    QCalculatorUI* calUI = QCalculatorUI::NewInstance();
    int ret = -1;

    if(calUI != NULL)
    {
       calUI->show();

       ret = a.exec();

       delete calUI;
    }

    return ret; */

    QcalculatorDec dec;

    return 0;
}
