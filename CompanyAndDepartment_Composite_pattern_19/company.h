#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QDebug>
#include <QList>

class Company    //公司类，抽象接口
{
public:
    explicit Company(QString name):_name(name){}
    virtual void Add(Company *c) = 0;
    virtual void Remove(Company *c) = 0;
    virtual void Display(int depth) = 0;
    virtual void LineOfDuty() = 0;
    virtual ~Company() {}    //注意析构函数不能声明为纯虚函数！
protected:
    QString _name;
};

class ConcreteCompany final: public Company   //具体公司类，实现抽象接口 树枝节点
{
public:
    explicit ConcreteCompany(QString name):Company(name){}
    ConcreteCompany(const ConcreteCompany &) = delete;   //QList里面如果使用智能指针就不用delete了
    ConcreteCompany & operator =(const ConcreteCompany &) = delete;   //QList里面如果使用智能指针就不用delete了
    void Add(Company *c) override
    {
        children.append(c);
    }
    void Remove(Company *c) override
    {
        children.removeOne(c);
    }
    void Display(int depth) override
    {
        qDebug()<<QString(depth,'-')<<_name;
        foreach (Company * c, children)
        {
            c->Display(depth+2);
        }
    }
    void LineOfDuty() override
    {
        foreach(Company *c , children)
            c->LineOfDuty();
    }
    ~ConcreteCompany() override
    {
        qDeleteAll(children.begin(),children.end());   //QList里面如果使用智能指针就不用qDeleteAll了
        children.clear();
    }

private:
    QList<Company *> children;
};

class HRDepartment final: public Company   //人力资源部类，树叶节点
{
public:
    explicit HRDepartment(QString name):Company(name){}
    void Add(Company *) override {}
    void Remove(Company *) override {}
    void Display(int depth) override
    {
        qDebug()<<QString(depth,'-')<<_name;
    }
    void LineOfDuty() override
    {
        qDebug()<<_name<<"员工招聘培训管理";
    }
    ~HRDepartment() override {}
};

class FinanceDepartment final: public Company   //人力资源部类，树叶节点
{
public:
    explicit FinanceDepartment(QString name):Company(name){}
    void Add(Company *) override {}
    void Remove(Company *) override {}
    void Display(int depth) override
    {
        qDebug()<<QString(depth,'-')<<_name;
    }
    void LineOfDuty() override
    {
        qDebug()<<_name<<"公司财务收支管理";
    }
    ~FinanceDepartment() override {}
};

#endif // COMPANY_H
