#include "iterator.h"

ConcreteIterator::ConcreteIterator(ConcreteAggregate *a)
{
    _aggregate = QSharedPointer<ConcreteAggregate>(a);
}

QString ConcreteIterator::First()
{
    return (*_aggregate)[0];
}

QString ConcreteIterator::Next()
{
    _current++;
    if(_current<_aggregate->Count())
        return (*_aggregate)[_current];
    return nullptr;
}

bool ConcreteIterator::IsDone()
{
    return _current >= _aggregate->Count() ? true : false;
}

QString ConcreteIterator::CurrentItem()
{
    return (*_aggregate)[_current];
}
