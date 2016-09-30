#define use_sharedPtr

#ifndef FUND
#define FUND
#include <QString>
#include <QtDebug>

class Stock1
{
public:
    void buy(){qDebug()<<"买入股票1";}
    void sell(){qDebug()<<"卖出股票1";}
};
class Stock2
{
public:
    void buy(){qDebug()<<"买入股票2";}
    void sell(){qDebug()<<"卖出股票2";}
};
class Stock3
{
public:
    void buy(){qDebug()<<"买入股票3";}
    void sell(){qDebug()<<"卖出股票3";}
};
//一般需要自己写析构函数的类，都需要实现复制构造函数和赋值运算符重载，以便能够完成深拷贝
class Fund
{
public:
    Fund()
    {
#ifdef use_sharedPtr
        _stock1 = QSharedPointer<Stock1>(new Stock1());
        _stock2 = QSharedPointer<Stock2>(new Stock2());
        _stock3 = QSharedPointer<Stock3>(new Stock3());
#else
        _stock1 = new Stock1();
        _stock2 = new Stock2();
        _stock3 = new Stock3();
#endif
    }
#ifndef use_sharedPtr
    Fund(const Fund & f)   //一般类里面有指针，且析构函数销毁了，则需要完成复制构造函数来深拷贝！！
    {
        _stock1 = new Stock1(*f._stock1);
        _stock2 = new Stock2(*f._stock2);
        _stock3 = new Stock3(*f._stock3);
    }
    Fund& operator=(const Fund& a)
    {
        if(this == &a)    //判断相等的情况！！
            return *this;
        if(_stock1 != NULL)
            delete _stock1;
        if(_stock2 != NULL)
            delete _stock2;
        if(_stock3 != NULL)
            delete _stock3;
        _stock1 = new Stock1(*a._stock1);
        _stock2 = new Stock2(*a._stock2);
        _stock3 = new Stock3(*a._stock3);
        return *this;
    }
    ~Fund()
    {
        delete _stock1;
        _stock1 = NULL;
        delete _stock2;
        _stock2 = NULL;
        delete _stock3;
        _stock3 = NULL;
    }
#endif
    void buy()
    {
        _stock1->buy();
        _stock2->buy();
        _stock3->buy();
    }
    void sell()
    {
        _stock1->sell();
        _stock2->sell();
        _stock3->sell();
    }
private:
#ifdef use_sharedPtr
    QSharedPointer<Stock1> _stock1;
    QSharedPointer<Stock2> _stock2;
    QSharedPointer<Stock3> _stock3;
#else
    Stock1 * _stock1;
    Stock2 * _stock2;
    Stock3 * _stock3;
#endif
};

#endif // FUND

