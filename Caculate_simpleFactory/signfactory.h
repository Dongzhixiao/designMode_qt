#ifndef SIGNFACTOR
#define SIGNFACTOR
#include "sign.h"
#include <QString>

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

#endif // SIGNFACTOR

