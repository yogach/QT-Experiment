#ifndef ICALCULATOR_H
#define ICALCULATOR_H

#include <QString>

//定义两个接口（纯虚函数）
class ICalculator
{
public:
    virtual bool expression(const QString& exp) = 0;
    virtual QString result() = 0;
};

#endif // ICALCULATOR_H
