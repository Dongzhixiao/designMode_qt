#include "sign.h"
#include "signfactory.h"
#include <iostream>
using namespace std;

int main (int argc, char * argv[])
{
//    Signfactory sf;
//    Sign *s = sf.createSign("/");
    DivideFactory *di = new DivideFactory();
    Sign *s = di->createSign();
    s->setA(1);s->setB(100);
    try{
        cout<<s->getResult();
    }
    catch(...)
    {
        cerr<<"get some error when get the result";
    }
    cin.get();
    return 0;
}
