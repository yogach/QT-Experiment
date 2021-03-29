#include "QCalculatorDec.h"
#include <QDebug>
#include <QStack>

QCalculatorDec::QCalculatorDec()
{
    m_exp = "";
    m_result = "";

    QQueue<QString> ret = split("+9.11 + ( -3 - 1 ) * -5 ");

    for(int i = 0; i< ret.length() ; i++)
    {
       // qDebug() << ret[i];
    }

    QQueue<QString> out ;

    transform(ret , out);

    for(int i = 0; i< out.length() ; i++)
    {
        qDebug() << out[i];
    }
}

QCalculatorDec::~QCalculatorDec()
{
}

bool QCalculatorDec::isDigitOrDot(QChar c)
{
    return ( (('0' <= c )&& ( c <= '9')) || ( c == '.'));
}

bool QCalculatorDec::isSymbol(QChar c)
{
     return isOperator(c) || (c == '(') || (c == ')');
}

bool QCalculatorDec::isSign(QChar c)
{
    return (c == '+') || (c == '-');
}

bool QCalculatorDec::isNumber(QString s)
{
    bool ret = false;

    s.toDouble(&ret);

    return ret;
}

bool QCalculatorDec::isOperator(QString s)
{
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

bool QCalculatorDec::isLeft(QString s)
{
    return (s == "(");
}

bool QCalculatorDec::isRight(QString s)
{
    return (s == ")");
}

int QCalculatorDec::priority(QString s)
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


bool QCalculatorDec::expression(const QString& exp)
{
    bool ret = false;

    return ret;
}

QString QCalculatorDec::expression()
{
     return m_result;
}

QString QCalculatorDec::result()
{
     return "false";
}

QQueue<QString> QCalculatorDec::split(const QString& exp)
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

bool QCalculatorDec::match(QQueue<QString>& exp)
{
    bool ret = true;
    int len = exp.length();
    QStack<QString> stack ;

    for( int i = 0; i < len; i++)
    {
        if( isLeft(exp[i]) )
        {
            stack.push( exp[i] ); //左括号入栈
        }
        else if( isRight(exp[i]) )
        {
            if( !stack.isEmpty() && isLeft( stack.top()) ) //当检测到右括号时 检查栈顶是否有左括号
            {
              stack.pop();
            }
            else
            {
              ret = false;

              break;
            }
        }
    }

    return ret && stack.isEmpty();
}

bool QCalculatorDec::transform(QQueue<QString>& exp , QQueue<QString>& out)
{
     bool ret = match(exp);

     QStack<QString> stack;

     out.clear();

     while( !exp.isEmpty() && ret )
     {
        QString e = exp.dequeue(); //数据出队列

        if( isNumber(e) )
        {
           out.enqueue(e);
        }
        else if( isOperator(e) )
        {
            while (!stack.isEmpty() && priority(e) <= priority( stack.top() ) )
              out.enqueue( stack.pop() );

            stack.push( e );
        }
        else if( isLeft(e) )
        {
            stack.push( e );
        }
        else if( isRight(e) )
        {
            while( !stack.isEmpty() && !isLeft(stack.top() ) )
              out.enqueue( stack.pop() );

            //将左括号去掉
            if( !stack.isEmpty())
              stack.pop();
        }
        else
        {
          ret = false;
        }

     }

     while( !stack.isEmpty() )
         out.enqueue( stack.pop() );

     if( !ret )
         out.clear();

     return ret;
}
