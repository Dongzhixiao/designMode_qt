#ifndef CASHSUPER
#define CASHSUPER

class CashSuper{
public:
    virtual ~CashSuper(){}

    virtual double acceptMoney(double money) = 0;
};

class CashNormal final:public CashSuper
{
//protected:
    double acceptMoney(double money) override
    {
        return money;
    }
};

class CashRebate final:public CashSuper
{
    double moneyRebate = 1;
public:
    CashRebate(double rebate)
    {
        moneyRebate = rebate;
    }
//protected:
    double acceptMoney(double money) override
    {
        return money*moneyRebate;
    }
};

class CashReturn final:public CashSuper
{
    double moneyCondition = 0;
    double moneyReturn = 0;
public:
    CashReturn(double mc,double mr)
    {
        moneyCondition = mc;
        moneyReturn = mr;
    }
//protected:
    double acceptMoney(double money) override
    {
        double result = money;
        if(money >= moneyCondition)
            result = money - (money/moneyCondition) * moneyReturn;
        return result;
    }
};

#endif // CASHSUPER

