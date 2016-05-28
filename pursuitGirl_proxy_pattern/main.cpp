#include "persuitgirl.h"

int main(int argc, char * argv[])
{
    schoolGirl *mm= new schoolGirl;
    mm->setName("美美");
    Proxy *daili = new Proxy(mm);
    daili->GiveDolls();
    daili->GiveChocolate();
    daili->GiveFlowers();
    qDebug() <<"测试完成！";
    return 0;
}
