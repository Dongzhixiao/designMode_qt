#include "personstate.h"
#include <QtDebug>

int main()
{
    ObjectStructure *o = new ObjectStructure();
    Man *a = new Man();
    Woman *b = new Woman();
    o->Attach(a);
    o->Attach(b);
    Success *v = new Success();
    o->Detach(a);
//    o->Detach(b);
    o->Display(v);
    return 0;
}
