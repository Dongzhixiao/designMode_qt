#ifndef SIGNFACTOR
#define SIGNFACTOR
#include "sign.h"
#include <QString>

//下面是简单工厂模式，作为对比！
class Signfactory{    //简单工厂类，为了根据传入参数返回对应需要的类
    Sign * _S = NULL;
public:
    Sign * createSign(QString str){
        if(str=="+")
            _S = new signAdd;    //这里用到多态
        else if(str=="-")
            _S = new signMinus;
        else if(str=="*")
            _S = new signMultiply;
        else if(str=="/")
            _S = new signDivide;
        else
        {
            std::cerr<<"unknow sign!";
            throw;
        }
        return _S;
    }
};
//下面是工厂方法模式的实现，本节的注意内容！！
struct FactoryInterface
{
    virtual Sign * createSign()=0;
};
class AddFactory:FactoryInterface
{
public:
    Sign * createSign()
    {
        return new signAdd();
    }
};
class MinusFactory:FactoryInterface
{
public:
    Sign * createSign()
    {
        return new signMinus();
    }
};
class MultiplyFactory:FactoryInterface
{
public:
    Sign * createSign()
    {
        return new signMultiply();
    }
};
class DivideFactory:FactoryInterface
{
public:
    Sign * createSign()
    {
        return new signDivide();
    }
};

#endif // SIGNFACTOR

