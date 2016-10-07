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
    virtual ~Action() = default;
private:
    QString _name;
};
class Person
{
public:
    virtual void Accept(Action *visitor) = 0;
    virtual QString getName(){return _name;}
private:
    QString _name;
};
class Success final : public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
    QString getName() override {return _name;}   //注意：虽然子类和父类这个函数样子一样，但是必须重写，否则返回的是父类的_name！！
private:
    QString _name = "成功";
};
class Failing final : public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
    QString getName() override {return _name;}
private:
    QString _name = "失败";
};
class Amativeness final : public Action
{
public:
    void getManConclusion(Man *concreteElementA) override;
    void getWomanConclusion(Woman *concreteElementB) override;
    QString getName() override {return _name;}
private:
    QString _name = "恋爱";

};
class Man final : public Person
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
    void Attach(Person *p){_elements.append(QSharedPointer<Person>(p));}
    void Detach(Person *p)
    {
        foreach (auto iterator, _elements)
        {
            if(iterator.data() == p)
            {
                _elements.removeOne(iterator);   //QSharedPointer实现了operator==()函数，因此可以这样用。
                break;
            }
        }
    }
    void Display(Action *a)
    {
        for(auto e :_elements)
        {
            e->Accept(a);
        }
    }
private:
    QList<QSharedPointer<Person>> _elements;
};

#endif // PERSONSTATE

