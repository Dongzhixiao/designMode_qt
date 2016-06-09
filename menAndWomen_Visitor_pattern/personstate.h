#ifndef PERSONSTATE
#define PERSONSTATE
#include <QtDebug>

class Man;
class Woman;
class Action
{
public:
    virtual void getManConclusion(Man *concreteElementA) = 0;
    virtual void getWomanConclusion(Woman *concreteElementB) = 0;
};
class Person
{
public:
    virtual void Accept(Action *visitor) = 0;
};
class Success:public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
};
class Failing:public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
};

#endif // PERSONSTATE

