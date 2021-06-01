#ifndef STRINGEVENT_H
#define STRINGEVENT_H

#include <QEvent>
#include <QString>

class StringEvent : public QEvent
{
    //Q_OBJECT

    QString m_data;
public:    
    //定义自定义事件的类型：QEvent::User之前的数字已经被QT本身使用了
    const static Type TYPE = static_cast<Type>(QEvent::User + 0xff);

    explicit StringEvent(QString data = "");
    

    QString data();
    
};

#endif // STRINGEVENT_H
