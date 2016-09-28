#ifndef ITERATOR_H
#define ITERATOR_H

#include <QSharedPointer>
#include <QList>
class Aggregate;
class Iterator   //Iterator迭代器抽象类
{
public:
    virtual QString First() = 0;
    virtual QString Next() = 0;
    virtual bool IsDone() = 0;
    virtual QString CurrentItem() = 0;
    virtual ~Iterator(){}
};

class Aggregate   //Aggregate聚集抽象类
{
public:
    virtual Iterator* CreateIterator() = 0;
    virtual ~Aggregate(){}
};

class ConcreteAggregate;
class ConcreteIterator final: public Iterator
{
public:
    ConcreteIterator(ConcreteAggregate * a);
    QString First() override ;
    QString Next() override ;
    bool IsDone() override;
    QString CurrentItem() override;
private:
    QSharedPointer<ConcreteAggregate> _aggregate;
    int _current = 0;
};

class ConcreteAggregate final : public Aggregate
{
public:
    Iterator * CreateIterator() override {return new ConcreteIterator(this);}
    int Count() {return _items.count();}
    QString& operator[](int i) {return _items[i];}
    void set(QString s){_items.append(s);}
private:
    QList<QString> _items;
};

#endif // ITERATOR_H
