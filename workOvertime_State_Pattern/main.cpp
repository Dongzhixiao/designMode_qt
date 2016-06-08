#include "workstatus.h"

static int Hour = 0;
static bool WorkFinished = false;
int main(int argc, char *argv[])
{
    Work *wk = new Work();
    wk->setTime(20);
    wk->writeProgram();
    return 0;
}
