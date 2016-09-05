#ifndef LEIFENG
#define LEIFENG
#include <QtDebug>

class LeiFeng
{
public:
    void Sweep()
    {
        qDebug() <<"扫地";
    }
    void Wash()
    {
        qDebug() <<"洗衣服";
    }
    void BuyRice()
    {
        qDebug() <<"买米";
    }
    virtual ~LeiFeng(){}
};

class Undergraduate final:public LeiFeng
{};
class Volunteer final:public LeiFeng
{};

#endif // LEIFENG

