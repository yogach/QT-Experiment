#include "Qcalculatordec.h"
#include "QDebug"

QcalculatorDec::QcalculatorDec()
{
    m_exp = "";
    m_result = "";

    QQueue<QString> ret = split("+9.11 + ( -3 - 1 ) * -5 ");

    for(int i = 0; i< ret.length() ; i++)
    {
        qDebug() << ret[i];
    }
}

QcalculatorDec::~QcalculatorDec()
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
   int ret = 0;

   if( ( s == "+") || ( s == "-"))
   {
      ret = 1;
   }

   if( ( s == "*") || ( s == "/"))
   {
      ret = 2;
   }

   return ret;
}


bool QcalculatorDec::expression(const QString& exp)
{
    bool ret = false;

    return ret;
}

QString QcalculatorDec::expression()
{
     return m_result;
}

QString QcalculatorDec::result()
{
     return "false";
}

QQueue<QString> QcalculatorDec::split(const QString& exp)
{
    QQueue<QString> ret;
    QString num = "";
    QString pre = "";

    for(int i=0; i < exp.length() ; i++)
    {
        if( isDigitOrDot( exp[i]) ) //当是符号和小数点时 累计
        {
            num += exp[i];
            pre = exp[i];
        }
        else if( isSymbol( exp[i] ))
        {
            if( !num.isEmpty() )
            {
                ret.enqueue(num);

                num.clear();
            }

            //判断当前符号是不是正负号
            if( isSign(exp[i]) && ( (pre == "") || ( pre == "(" ) || isOperator(pre) ) )
            {
                num += exp[i];
            }
            else
            {
                ret.enqueue(exp[i]);
            }

            pre = exp[i];

        }

    }

    if( !num.isEmpty())
    {
       ret.enqueue(num);
    }

    return ret;
}
