#include "Qcalculatorui.h"

QCalculatorUI::QCalculatorUI() : QWidget(NULL,Qt::WindowCloseButtonHint)
{
}


bool QCalculatorUI::construct()
{
   bool ret = true;
   const char* btnText[20] =
   {
       "7", "8", "9", "+", "(",
       "4", "5", "6", "-", ")",
       "1", "2", "3", "*", "<-",
       "0", ".", "=", "/", "C",
   };


   m_lineEdit = new QLineEdit(this);
   if(m_lineEdit != NULL)
   {
       m_lineEdit->resize(240,30);
       m_lineEdit->move(10,10);
       m_lineEdit->setReadOnly(true); //设置文本框为只读
   }
   else
   {
     ret = false;
   }

   for(int i = 0; (i < 4) && ret; i++ )
   {
       for(int j = 0; (j < 5) && ret ; j++)
       {
           m_Button[i*5 + j] = new QPushButton(this);
           if(m_Button != NULL)
           {
                m_Button[i*5 + j]->resize(40,40);
                m_Button[i*5 + j]->move(10 + (40 + 10)*j , 50 + (40 + 10)*i );
                m_Button[i*5 + j]->setText(btnText[i*5 + j]);
           }
           else
           {
              ret = false;
           }

       }
   }


   return ret;
}


QCalculatorUI* QCalculatorUI::NewInstance()
{
   QCalculatorUI* ret = new QCalculatorUI();

   if( ( ret == NULL) || ( !ret->construct() ))
   {
      delete ret;
      ret = NULL;
   }


   return ret;
}

void QCalculatorUI::show()
{
    QWidget::show();
    setFixedSize(width(), height()); //设置主窗口为固定大小
}


QCalculatorUI::~QCalculatorUI()
{

}
