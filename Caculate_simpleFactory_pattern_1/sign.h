#ifndef SIGN
#define SIGN
#include <iostream>

class Sign{   //这里封装一个抽象类,因为数据比较简单，并且一开始就初始化了，因此使用默认构造函数，析构函数和拷贝构造函数
protected:
    double _A = 0;
    double _B = 0;
    double _Result = 0;
public:
    void setA(double a)
    {
        _A = a;
    }
    void setB(double b)
    {
        _B = b;
    }
    double getA(){return _A;}
    double getB(){return _B;}

    virtual double getResult() = 0;

    virtual ~Sign(){}   //根据《Effect C++》条款七：任何class只要带有virtual函数都几乎确定应该也有一个virtual析构函数。
};
//下面用到继承
class signAdd final:public Sign   //加法类，继承符号类
{
    double getResult() override
    {
        _Result = _A + _B;
        return _Result;
    }
};

class signMinus final:public Sign  //减法类，继承符号类
{
    double getResult() override
    {
        _Result = _A - _B;
        return _Result;
    }
};

class signMultiply final:public Sign
{
    double getResult() override
    {
        _Result = _A * _B;
        return _Result;
    }
};

class signDivide final:public Sign
{
    double getResult() override
    {
        if(_B == 0){
            std::cerr<<"can't divide zero"<<std::endl;
            throw 1;
        }
        _Result = _A / _B;
        return _Result;
    }
};
#endif // SIGN

