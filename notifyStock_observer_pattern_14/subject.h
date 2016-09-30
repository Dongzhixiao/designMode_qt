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
    virtual ~Subject()
    {
#if 1
        qDeleteAll(_observers);
#else
        for(auto i:_observers)
        {            
            delete i;
        }
#endif
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
    Boss(){Subject::_action = QString("I am boss!");}
    void Attach(Observer *observer) override
    {
        _observers.append(observer);
    }
    void Detch(Observer *observer) override
    {
        _observers.removeOne(observer);
        delete observer;
        observer = nullptr;
    }
    void Notify() override;  //override不能写在类外面！！
};

class Secretary:public Subject
{
public:
    Secretary(){Subject::_action = QString("I am secretary!");}   //子类为啥不能初始化父类的成员变量
    void Attach(Observer *observer) override
    {
        _observers.append(observer);
    }
    void Detch(Observer *observer) override
    {
        _observers.removeOne(observer);
        delete observer;
        observer = nullptr;
    }
    void Notify() override;  //override不能写在类外面！！
};

#endif // SUBJECT

