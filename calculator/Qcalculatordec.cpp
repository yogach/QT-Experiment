#include "Qcalculatordec.h"

QcalculatorDec::QcalculatorDec()
{
}


bool QcalculatorDec::isDigitOrDot(QChar c)
{
    return ( (('0' <= c )&& ( c <= '9')) || ( c == '.'));
}

bool QcalculatorDec::isSymbol(QChar c)
{
     return isOperator(c) || (c == '(') || (c == ')');
}

bool QcalculatorDec::isSign(QChar c)
{
    return (c == '+') || (c == '-');
}

bool QcalculatorDec::isNumber(QString s)
{
    bool ret = false;

    s.toDouble(&ret);

    return ret;
}

bool QcalculatorDec::isOperator(QString s)
{
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

bool QcalculatorDec::isLeft(QString s)
{
    return (s == "(");
}

bool QcalculatorDec::isRight(QString s)
{
    return (s == ")");
}

int QcalculatorDec::priority(QString s)
{

}

QQueue<QString> QcalculatorDec::split(const QString& exp)
{

}
