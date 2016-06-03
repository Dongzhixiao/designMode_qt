#ifndef SUBJECT
#define SUBJECT
#include <QtDebug>
#include <QString>
#include <QList>

class Observer;
class Subject
{
public:
//    Subject(){}
    ~Subject()
    {
        for(auto i:_observers)
        {            
            delete i;
//            i = nullptr;
        }
        _observers.clear();
    }
    virtual void Attach(Observer *observer) = 0;
    virtual void Detch(Observer *observer) = 0;
    virtual void Notify() = 0;
//    void setSubjectState(QString str){_action = str;}
    QString getSubjectState(){return _action;}
protected:
    QString _action;
    QList<Observer *> _observers;
};

class Boss:public Subject
{
public:
    Boss(){Subject::_action = QString("我是老板！");}
    void Attach(Observer *observer) override
    {
        _observers.append(observer);
    }
    void Detch(Observer *observer) override
    {
        _observers.removeOne(observer);
    }
    void Notify() override;  //override不能写在类外面！！
};

class Secretary:public Subject
{
public:
    Secretary(){Subject::_action = QString("我是秘书！");}   //子类为啥不能初始化父类的成员变量
    void Attach(Observer *observer) override
    {
        _observers.append(observer);
    }
    void Detch(Observer *observer) override
    {
        _observers.removeOne(observer);
    }
    void Notify() override;  //override不能写在类外面！！
};

#endif // SUBJECT

