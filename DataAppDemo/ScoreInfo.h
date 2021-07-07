#ifndef SCOREINFO_H
#define SCOREINFO_H

#include <QObject>

class ScoreInfo : public QObject
{
    Q_OBJECT

    QString m_id;
    QString m_name;
    int m_score;

public:
    explicit ScoreInfo(QObject* parent = 0);
    explicit ScoreInfo(QString id, QString name, int score, QObject* parent = 0);

    //因为QObject的原因将拷贝构造函数和=号 设为了private需要重载
    ScoreInfo(const ScoreInfo& obj);
    ScoreInfo& operator = (const ScoreInfo& obj);

    QString id();
    QString name();
    int score();
};

#endif // SCOREINFO_H
