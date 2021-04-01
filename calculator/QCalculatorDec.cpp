#include "QCalculatorDec.h"
#include <QDebug>
#include <QStack>

QCalculatorDec::QCalculatorDec()
{
    m_exp = "";
    m_result = "";


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
    QQueue<QString> spExp = split(exp);
    QQueue<QString> postExp;

    m_exp = exp;

    if( transform(spExp,postExp) )
    {
       m_result = calculate(postExp);

       ret = (m_result != "Error");
    }
    else
    {
       ret = false;
    }

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

//中缀表达式分离算法
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

QString QCalculatorDec::calculate(QQueue<QString>& exp)
{
    QString ret = "Error";
    QStack<QString> stack;

    while( !exp.isEmpty() )
    {
         QString e = exp.dequeue();

         if( isNumber(e) )
         {
             stack.push( e );
         }
         else if( isOperator(e) )
         {
             QString rp = !stack.isEmpty() ? stack.pop() : "";
             QString lp = !stack.isEmpty() ? stack.pop() : "";

             QString result = calculate(lp , e , rp);
             if( result != "Error" )
             {
                 stack.push(result);
             }
             else
             {
                 break;
             }

         }
         else
         {
            break;
         }
    }

    //当传入的队列为空 栈中只有一个元素并且是数字时，判断为运算成功
    if(exp.isEmpty() && isNumber(stack.top()) && ( stack.size() == 1 ))
    {
        ret = stack.pop();
    }

    return ret;
}

QString QCalculatorDec::calculate(QString l , QString op , QString r)
{
    QString ret = "Error";

    if( (isNumber(l) && isNumber(r) ) )
    {
        double lp = l.toDouble();
        double rp = r.toDouble();

        if( op == "+")
        {
            ret.sprintf("%f" , lp + rp);
        }
        else if( op == "-")
        {
            ret.sprintf("%f" , lp - rp);
        }
        else if( op == "*")
        {
            ret.sprintf("%f" , lp * rp);
        }
        else if( op == "/")
        {
            const double p = 0.000000000000001;

            //需要首先判断一下除数是否为0
            //且因为double类型数无法直接和0比较 所以使用以下方法进行
            if(( -p < rp ) && ( rp < p))
            {
               ret = "Error";
            }
            else
            {
              ret.sprintf("%f" , lp / rp);
            }
        }
        else
        {
          ret = "Error";
        }
    }
    else
    {
        ret = "Error";
    }

    return ret;
}
