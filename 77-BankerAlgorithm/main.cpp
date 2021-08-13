#include <QtCore/QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QList>

class Customer : public QThread
{
protected:
    int m_need;
    volatile int m_current;
    QMutex m_mutex;

    void run()
    {
        bool condition = false;

        qDebug() << objectName() << "begin to apply money";

        do
        {
            m_mutex.lock();

            condition = (m_current < m_need);

            m_mutex.unlock();

            msleep(10);

        }while( condition );


        qDebug() << objectName() << "end (get enough money)";
    }

public:
    Customer(int current, int need)
    {
       m_current = current;
       m_need = need;
    }

    void addMoney(int m)
    {
        m_mutex.lock();

        m_current += m;

        m_mutex.unlock();
    }

    int backMoney()
    {
        int ret = 0;

        m_mutex.lock();

        ret = m_current;
        m_current = 0;

        m_mutex.unlock();

        return ret;
    }

    int current()
    {
        int ret = 0;

        m_mutex.lock();
        ret = m_current;
        m_mutex.unlock();

        return ret;
    }

    int need()
    {
        return m_need;
    }

};

class Bank : public QThread
{
protected:
    QList<Customer*> m_list;
    int m_total;

    void run()
    {
        int index = -1;

        qDebug() << objectName() << " begin: " << m_total;

        do
        {
            index = -1;

            for(int i=0; i<m_list.count(); i++)
            {
                //首先检查是否有客户贷款已经完成
                //如果有则收回放出去的钱
                if( m_list[i]->need() == m_list[i]->current() )
                {
                    m_total += m_list[i]->backMoney();

                    qDebug() << objectName() << " take back money from " << m_list[i]->objectName() << " " << m_list[i]->need();
                }
            }

            qDebug() << objectName() << " current: " << m_total;

            int toGet = 0x00FFFFFFF;

            for(int i=0; i<m_list.count(); i++)
            {
                //找到还在等待队列中 需要资源最少的那个
                if( m_list[i] ->isRunning() ) // 判断线程是否还在运行
                {
                    int tmp = m_list[i]->need() - m_list[i]->current();

                    if( toGet > tmp)
                    {
                        toGet = tmp;
                        index = i;
                    }

                }

            }

            if( index >= 0)
            {

                if( toGet <= m_total)
                {
                    //如果当前资源够分配 则直接分配
                    qDebug() << objectName() << " give money to: " << m_list[index]->objectName();

                    m_total--;

                    m_list[index]->addMoney(1);
                }
                else
                {
                    //当前资源不够分配则收回资源后 终止线程
                    qDebug() << objectName() << " terminate: " << m_list[index]->objectName();

                    m_total += m_list[index]->backMoney();

                    m_list[index]->terminate();
                }

            }

            sleep(1);
        }
        while(index >= 0);

        qDebug() << objectName() << " end: " << m_total;
    }
public:
    Bank(int total)
    {
        m_total = total;
    }

    void addCustomer(Customer* customer)
    {
        m_list.append(customer);
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Customer p(4, 8);
    Customer q(2, 3);
    Customer r(2, 11);

    Bank bank(2);

    p.setObjectName("P");
    q.setObjectName("Q");
    r.setObjectName("R");

    bank.setObjectName("Bank");

    bank.addCustomer(&p);
    bank.addCustomer(&q);
    bank.addCustomer(&r);

    bank.start();

    p.start();
    q.start();
    r.start();

    
    return a.exec();
}
