#ifndef OBSERVER
#define OBSERVER
#include <QtDebug>
#include <QString>
#include <QSharedPointer>
#include "subject.h"

class Observer
{
public:
//    Observer(){}
    Observer(QString name, Subject *sub):_name(name),_sub(QSharedPointer<Subject>(sub)){}
    virtual ~Observer() = default;
    virtual void update()=0;
protected:
    QString _name;
    QSharedPointer<Subject> _sub;
};

class StockObserver final:public Observer
{
public:
    StockObserver(QString name, Subject *sub):Observer(name, sub){}
    void update() override
    {
        qDebug() <<_sub->getSubjectState()<<_name<<"关掉股票，开始工作！";
    }
};

class AnimationObserver final:public Observer
{
public:
    AnimationObserver(QString name, Subject *sub):Observer(name, sub){}
    void update() override
    {
        qDebug() <<_sub->getSubjectState()<<_name<<"关掉动漫，开始工作！";
    }
};
#endif // OBSERVER

