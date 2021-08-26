#include <ultra64.h>
#include "kart.h"

void setDriftBoost(TKart * player)
{
    u16 * dframe = (u16 *)0x8002A86E;
    player->weapon |= 0x00800000;
    player->maxadd_power = 8000.0f;
    player->talk = 0x0020;
    player->spark[0].flag = 1;
    *dframe = 5;
}