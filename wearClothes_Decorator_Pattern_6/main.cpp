#include "person.h"

int main(int argc, char *argv[])
{
    Person *a = new Person("小红");
    Finery *t = new Tshirt();
    Finery *s = new Skirt();
    Finery *st = new stocking();
    t->Decorate(a);
    s->Decorate(t);
    st->Decorate(s);
    st->show();
    return 0;
}
