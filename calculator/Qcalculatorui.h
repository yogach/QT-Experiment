#ifndef QCALCULATORUI_H
#define QCALCULATORUI_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class QCalculatorUI : public QWidget
{
private:
    QLineEdit* m_lineEdit;
    QPushButton* m_Button[20];

    QCalculatorUI();
    bool construct();

public:
    static QCalculatorUI* NewInstance(); //二阶构造
    void show();
    ~QCalculatorUI();
};

#endif // QCALCULATORUI_H
