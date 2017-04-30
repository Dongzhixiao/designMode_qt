#ifndef SIGN
#define SIGN
#include <iostream>

class Sign{   //这里封装一个抽象类
protected:
    double _A;
    double _B;
    double _Result;
public:
    void setA(double a)
    {
        _A=a;
    }
    void setB(double b)
    {
        _B=b;
    }
    double getA(){return _A;}
    double getB(){return _B;}

    virtual double getResult(){
        _Result = 0;
        return _Result;
    }
};
//下面用到继承
class signAdd final:public Sign   //加法类，继承符号类
{
    double getResult()  override
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

class signMultiply final :public Sign
{
    double getResult() override
    {
        _Result = _A * _B;
        return _Result;
    }
};

class signDivide final :public Sign
{
    double getResult() override
    {
        if(_B==0){
            std::cerr<<"can't divide zero"<<std::endl;
            throw;
        }
        _Result = _A / _B;
        return _Result;
    }
};
#endif // SIGN

