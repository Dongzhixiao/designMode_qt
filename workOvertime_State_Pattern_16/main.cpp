#include "workstatus.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);Q_UNUSED(argv);
    Work *wk = new Work();
    wk->setTime(20);    //这里设置时间，代表加班工作到几点。
    wk->writeProgram();
    return 0;
}
