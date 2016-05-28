#include "person.h"

int main(int argc, char *argv[])
{
    Person *a = new Person("小红");
    Tshirt *t = new Tshirt();
    Skirt *s = new Skirt();
    stocking *st = new stocking();
    t->Decorate(a);
    s->Decorate(t);
    st->Decorate(s);
    st->show();
    return 0;
}
