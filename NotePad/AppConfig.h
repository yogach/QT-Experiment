#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QObject>
#include <QFont>

class AppConfig : public QObject
{
    Q_OBJECT
    QFont m_editorFont;
    bool m_isAutoWrap;
    bool m_isToolBarVisible;
    bool m_isStatusBarVisible;
    bool m_isVaild;

    bool restore();

public:
    explicit AppConfig(QObject *parent = 0);
    explicit AppConfig(QFont font, bool isWrap, bool tbVisible, bool sbVisble, QObject *parent = 0);
    bool store();
    QFont editorFont();
    bool isAutoWrap();
    bool isToolBarVisible();
    bool isStatusBarVisible();
    bool isVaild();
};

#endif // APPCONFIG_H
