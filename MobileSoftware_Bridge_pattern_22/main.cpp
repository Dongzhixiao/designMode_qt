#include "mobile.h"

int main()
{
    HandsetBrand *ab = new HandsetBrandN;

    ab->setHandsetSoft(new HandsetGame());
    ab->Run();

    ab->setHandsetSoft(new HandsetAddressList());
    ab->Run();

    delete ab;

    ab = new HandsetBrandM;

    ab->setHandsetSoft(new HandsetGame());
    ab->Run();

    ab->setHandsetSoft(new HandsetAddressList());
    ab->Run();

    return 0;
}
