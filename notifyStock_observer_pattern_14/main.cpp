#include "observer.h"
#include "subject.h"

int main(int argc, char * argv[])
{
    Subject *st = new Secretary();
    Observer *a = new StockObserver("妈妈",st);
    Observer *b = new AnimationObserver("小东",st);
    st->Attach(a);
    st->Attach(b);
    st->Notify();

    return 0;
}
