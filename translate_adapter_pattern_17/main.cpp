#include "basketballplayer.h"

int main(int argc, char *argv)
{
    Player *ch = new Translator("姚明");
    ch->Attack();
    ch->Defense();
    return 0;
}
