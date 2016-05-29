#include "leifengfactory.h"
#include "leifeng.h"
#include <QtDebug>

int main(int argc , char *argv[])
{
    LeiFenngInterface *factory = new UndergraduateFactory();
    LeiFeng *lf = factory->CreateLeiFeng();

    lf->BuyRice();
    lf->Sweep();
    lf->Wash();

    qDebug() <<"测试完毕！";
    return 0;
}


