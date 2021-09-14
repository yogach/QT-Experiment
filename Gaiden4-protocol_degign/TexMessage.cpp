#include "TextMessage.h"
#include <QDebug>

TextMessage::TextMessage(QObject *parent) : QObject(parent)
{
    m_type = "";
    m_data = "";
}


TextMessage::TextMessage(QString type, QString data, QObject *parent ) : QObject(parent)
{
    m_type = type.trimmed(); //去除空格

    m_type.resize(4, ' '); //重新设置type的大小为4个字节 不够4个则设置为空格 超过则丢掉多余的数据则丢

    m_data = data.mid(0, 15000); //根据协议data长度不超过两个字节
}

QString TextMessage::type()
{
    return m_type.trimmed();
}

int TextMessage::length()
{
    return m_data.length();
}

QString TextMessage::data()
{
    return m_data;
}

QByteArray TextMessage::serialize()
{
    QByteArray ret;
    QByteArray dba = m_data.toUtf8(); //将QString数据转换成utf8
    QString len = QString::asprintf("%X", dba.length()); //将数据长度转换为16进制

    len.resize(4, ' ');

    ret.append(m_type.toStdString().c_str(), 4);
    ret.append(len.toStdString().c_str(), 4);
    ret.append(dba);

    return ret;
}

bool TextMessage::unserialize(QByteArray ba)
{
    bool ret = (ba.length() >= 8); //大于8代表符合协议最小字节要求

    if( ret )
    {
        QString type = QString(ba.mid(0, 4)); //取0-4字节数据
        QString len = QString(ba.mid(4, 4)).trimmed();
        int l = len.toInt(&ret, 16);

        ret = ret && (l == (ba.length() - 8));

        if( ret )
        {
            m_type = type;
            m_data = QString(ba.mid(8, l));
        }
    }

    return ret;
}
