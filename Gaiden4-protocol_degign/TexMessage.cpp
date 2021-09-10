#include "TextMessage.h"

TextMessage::TextMessage(QObject *parent) : QObject(parent)
{
    m_type = "";
    m_date = "";
}


TextMessage::TextMessage(QString type, QString data, QObject *parent ) : QObject(parent)
{
    m_type = type.trimmed(); //去除空格

    m_type.resize(4, ' '); //重新设置type的大小为4个字节 不够4个则设置为空格 超过则丢掉多余的数据则丢

    m_date = data.mid(0, 0xffff); //根据协议data长度不超过两个字节
}

QString TextMessage::type()
{
    return m_type.trimmed();
}

int TextMessage::length()
{
    return m_date.length();
}

QString TextMessage::data()
{
    return m_date;
}

QString TextMessage::serialize()
{
    QString len = QString::asprintf("%X", m_date.length()); //将数据长度转换为16进制

    len.resize(4, ' ');

    return m_type + len + m_date;
}

bool TextMessage::unserialize(QString s)
{
    bool ret = (s.length() >= 8); //大于8代表符合协议最小字节要求

    if( ret )
    {
        QString type = s.mid(0, 4); //取0-4字节数据
        QString len = s.mid(4, 4).trimmed();
        int l = len.toInt(&ret, 16);

        ret = ret && (l == (s.length() - 8));

        if( ret )
        {
            m_type = type;
            m_date = s.mid(8, l);
        }
    }

    return ret;
}
