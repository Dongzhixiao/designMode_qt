#ifndef PERSONSTATE
#define PERSONSTATE
#include <QtDebug>
#include <QString>
#include <QList>

class Man;
class Woman;
class Action
{
public:
    virtual void getManConclusion(Man *concreteElementA) = 0;
    virtual void getWomanConclusion(Woman *concreteElementB) = 0;
    virtual QString getName(){return _name;}
private:
    QString _name = "";
};
class Person
{
public:
    virtual void Accept(Action *visitor) = 0;
    virtual QString getName(){return _name;}
private:
    QString _name = "";
};
class Success:public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
    QString getName() override {return _name;}
private:
    QString _name = "成功";
};
class Failing:public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
    QString getName() override {return _name;}
private:
    QString _name = "失败";
};
class Amativeness:public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
    QString getName() override {return _name;}
private:
    QString _name = "恋爱";
};
class Man:public Person
{
public:
    void Accept(Action *visitor)
    {
        visitor->getManConclusion(this);
    }
    QString getName() override {return _name;}
private:
    QString _name = "男人";
};
class Woman:public Person
{
public:
    void Accept(Action *visitor)
    {
        visitor->getWomanConclusion(this);
    }
    QString getName() override {return _name;}
private:
    QString _name = "女人";
};

class ObjectStructure
{
public:
    void Attach(Person *p){elements.append(p);}
    void Detach(Person *p){elements.removeOne(p);delete p;p = NULL;}  //不确定行为，不知道指针是否实现了操作符==!!
    void Display(Action *a)
    {
        for(auto e :elements)
        {
            e->Accept(a);
        }
    }

private:
    QList<Person *> elements = QList<Person *>();
};

#endif // PERSONSTATE

