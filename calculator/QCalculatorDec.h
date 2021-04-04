#ifndef QCALCULATORDEC_H
#define QCALCULATORDEC_H

#include <QString>
#include <QQueue>
#include "ICalculator.h"

//继承接口 必须实现两个接口
class QCalculatorDec : public ICalculator
{
protected:
    QString m_exp;
    QString m_result;

    bool isDigitOrDot(QChar c);
    bool isSymbol(QChar c);
    bool isSign(QChar c);
    bool isNumber(QString s);
    bool isOperator(QString s);
    bool isLeft(QString s);
    bool isRight(QString s);
    int priority(QString s);
    QQueue<QString> split(const QString& exp);
    QString calculate(QQueue<QString>& exp);
    QString calculate(QString l , QString op , QString r);
    bool match(QQueue<QString>& exp);
    bool transform(QQueue<QString>& exp , QQueue<QString>& out);
public:
    QCalculatorDec();
    ~QCalculatorDec();
    bool expression(const QString& exp);    
    QString result();
};

#endif // QCALCULATORDEC_H
