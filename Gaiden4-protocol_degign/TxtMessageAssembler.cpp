#include "TxtMessageAssembler.h"

TxtMessageAssembler::TxtMessageAssembler(QObject *parent) : QObject(parent)
{

}

void TxtMessageAssembler::clear()
{
    m_type = "";
    m_length = 0;
    m_data.clear();
}

QByteArray TxtMessageAssembler::fetch(int n)
{
    QByteArray ret;

    for(int i=0; i<n; i++)
    {
        ret.append( m_queue.dequeue() );
    }

    return ret;
}

QSharedPointer<TextMessage> TxtMessageAssembler::assembler()
{
    TextMessage* ret = NULL;
    bool tryMakeMsg = false;

    if( m_type == "")
    {
        tryMakeMsg = makeTypeAndLength();
    }
    else
    {
        tryMakeMsg = true;
    }

    if( tryMakeMsg )
    {
        ret = makeMessage();
    }

    //如果接收不为空 则代表生成了一个可用的TextMessage对象
    if( ret != NULL)
    {
        clear();
    }

    return QSharedPointer<TextMessage>(ret);
}


bool TxtMessageAssembler::makeTypeAndLength()
{
    bool ret = (m_queue.length() >= 8); //当缓冲区数据大于8时才进行处理

    if( ret )
    {
        QString len = "";

        m_type = QString(fetch(4)); //从队列中取出4个字节数据

        len = QString(fetch(4));

        m_length = len.trimmed().toInt(&ret, 16); //16代表是16进制数

        //判断toInt转换是否成功 如果失败则清除
        if( !ret )
        {
            clear();
        }
    }

    return ret;
}

TextMessage* TxtMessageAssembler::makeMessage()
{
    TextMessage* ret = NULL;

    if( m_type != "")
    {
        int needed = m_length - m_data.length(); //得到还需要多少长度的数据
        int n = (needed <= m_queue.length()) ? needed : m_queue.length();

        m_data.append(fetch(n));

        if( m_length == m_data.length())
        {
            ret = new TextMessage(m_type, QString(m_data)); //QString可直接将UTF8数据转换成字符串
        }

    }

    return ret;
}

void TxtMessageAssembler::prepare(const char* data, int len)
{
    if( data != NULL)
    {
        for(int i=0; i<len; i++)
        {
            m_queue.append(data[i]);
        }
    }
}


QSharedPointer<TextMessage> TxtMessageAssembler::assembler(const char* data, int len)
{
    prepare(data, len);

    return assembler();
}

void TxtMessageAssembler::reset()
{
    clear();
    m_queue.clear();
}
