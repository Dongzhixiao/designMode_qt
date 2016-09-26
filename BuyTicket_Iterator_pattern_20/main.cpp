#include "iterator.h"

#include <QDebug>

int main(int argc,char* argv[])
{
    ConcreteAggregate *a = new ConcreteAggregate();

    a->set("大鸟");
    a->set("小菜");
    a->set("行李");
    a->set("老外");
    a->set("公交内部员工");
    a->set("小偷");

    Iterator *i = new ConcreteIterator(a);
    QString item = i->First();
    while(!i->IsDone())
    {
        qDebug()<< i->CurrentItem();
        i->Next();
    }

    return 0;
}
