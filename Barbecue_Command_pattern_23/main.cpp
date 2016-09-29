#include "command.h"

int main()
{
    //开店前的准备
    Barbecuer* boy = new Barbecuer;
    Command* bakeMuttonCommand1 = new BakeMuttonCommand(boy);
    Command* bakeMuttonCommand2 = new BakeMuttonCommand(boy);
    Command* bakeChickenWingCommand1 = new BakeChickenWingCommand(boy);
    Waiter* girl = new Waiter;

    //开门营业
    girl->SetOrder(bakeMuttonCommand1);
    girl->Notify();
    girl->SetOrder(bakeMuttonCommand2);
    girl->Notify();
    girl->SetOrder(bakeChickenWingCommand1);
    girl->Notify();

    return 0;
}
