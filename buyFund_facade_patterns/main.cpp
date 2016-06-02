#include "fund.h"

int main(int argc, char *argv[])
{
    Fund *fd = new Fund();
    Fund cd = *fd;   //调用复制构造函数
//    Fund cd;
//    cd = *fd;
    delete fd;
    fd=NULL;
    cd.buy();
    cd.sell();
    return 0;
}
