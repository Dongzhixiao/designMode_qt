#include "subject.h"
#include "observer.h"

void Boss::Notify()
{
    for( auto i:_observers)
    {
        i->update();
    }
}

void Secretary::Notify()
{
    for( auto i:_observers)
    {
        i->update();
    }
}
