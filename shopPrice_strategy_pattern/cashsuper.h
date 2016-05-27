#ifndef CASHSUPER
#define CASHSUPER

class CashSuper{
protected:
    virtual double acceptMoney(double money);
};

class CashNormal:public CashSuper
{
    double acceptMoney(double money)
    {
        return money;
    }
};

class CashRebate:public CashSuper
{
    double moneyRebate = 1;
public:
    CashRebate(double rebate)
    {
        moneyRebate = rebate;
    }
    double acceptMoney(double money)
    {
        return money*moneyRebate;
    }
};

#endif // CASHSUPER

