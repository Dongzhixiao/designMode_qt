#ifndef PERSON
#define PERSON
#include <QString>
#include <QTextStream>
#include <QtDebug>

class Person
{
    QString name;
public:
    Person(){}   //子类不想用构造函数，父类必须实现无参数构造函数(如果父类没有构造函数时，默认编译器产生的构造函数即可！)
    Person(QString n)
    {
        name = n;
    }
    virtual void show()
    {
        qDebug() <<"装扮的"<<name<<":";
    }
    virtual ~Person(){}
};

class Finery:public Person
{
protected:
    Person *component = nullptr;    //内含一个用来装饰的类，使用方式见main函数！
public:
    //装饰
    void Decorate(Person *com)
    {
        component = com;
    }
    void show() override   //把每个要装饰的功能放在单独的类中，并让这个类包装它所要装饰的对象，因此当需要执行特殊行为时，客户代码
                           //就可以在运行时根据需要有选择的、按顺序的使用装饰功能包装对象！！
    {
        if(component != nullptr)
            component->show();
    }
};

class Tshirt final:public Finery
{
public:
    void show() override
    {
        Finery::show();
        qDebug() <<"大T恤";
    }
};

class Skirt final:public Finery
{
public:
    void show() override
    {
        Finery::show();
        qDebug() <<"裙子";
    }
};

class stocking final:public Finery
{
public:
    void show() override
    {
        Finery::show();
        qDebug() <<"长袜";
    }
};

#endif // PERSON

