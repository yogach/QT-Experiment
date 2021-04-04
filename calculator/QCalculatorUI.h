#ifndef QCALCULATORUI_H
#define QCALCULATORUI_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

#include "ICalculator.h"

class QCalculatorUI : public QWidget
{
    Q_OBJECT //Q_OBJECT 声明类中有自定义槽
private:
    QLineEdit* m_lineEdit;
    QPushButton* m_Button[20];
    ICalculator* m_cal;

    QCalculatorUI();
    bool construct();

private slots:
    void onButtonClicked(); //使用slots声明一个槽函数

public:
    static QCalculatorUI* NewInstance(); //二阶构造
    void show();
    ~QCalculatorUI();
    void setCalculator(ICalculator* cal);
    ICalculator* getCalculator();

};

#endif // QCALCULATORUI_H
