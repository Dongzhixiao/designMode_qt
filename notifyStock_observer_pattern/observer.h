#ifndef OBSERVER
#define OBSERVER
#include <QtDebug>
#include <QString>
#include "subject.h"

class Observer
{
public:
//    Observer(){}
    Observer(QString name, Subject *sub):_name(name),_sub(sub){}
    ~Observer()
    {
        delete _sub;
//        _sub = nullptr;
    }

    virtual void update()=0;
protected:
    QString _name;
    Subject* _sub;
};

class StockObserver:public Observer
{
public:
    StockObserver(QString name, Subject *sub):Observer(name, sub){}
    void update() override
    {
        qDebug() <<_sub->getSubjectState()<<_name<<"关掉股票，开始工作！";
    }
};

class AnimationObserver:public Observer
{
public:
    AnimationObserver(QString name, Subject *sub):Observer(name, sub){}
    void update() override
    {
        qDebug() <<_sub->getSubjectState()<<_name<<"关掉动漫，开始工作！";
    }
};
#endif // OBSERVER

