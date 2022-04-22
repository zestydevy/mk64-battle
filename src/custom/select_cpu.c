#include <ultra64.h>
#include "common.h"

// player 2 select flag
extern s8 D_8018EDE9;

void selectCpu()
{
    D_8018EDE9 = TRUE;
    read_controllers();
}