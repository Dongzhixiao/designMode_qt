#ifndef CASHCONTEXT
#define CASHCONTEXT
#include <QString>
#include "cashsuper.h"

class CashContext    //策略模式，以相同的方式调用各种算法，减少各种算法类和使用算法类的耦合，结果抽象在getResult函数里返回
//同时策略模式还简化了单元测试,因为每个算法都有自己的类，可以通过自己的接口单独测试！修改任意一个算法不会影响其他算法！！
{
    CashSuper * cs;
public:
    CashContext(QString qs)   //策略模式封装了变化,判断在策略类的函数里面完成,但是还有更好的方法：反射技术(抽象工厂模式中再学！)
    {
        if(qs == "正常")
        {
            cs = new CashNormal();
        }
        else if(qs == "打八折")
        {
            cs = new CashRebate(0.8);
        }
    }
    double getResult(double money)
    {
        return cs->acceptMoney(money);
    }
};

#endif // CASHCONTEXT

