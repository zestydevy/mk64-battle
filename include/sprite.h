#ifndef __SPRITE_H
#define __SPRITE_H

#include <ultra64.h>

// kw_sprite
void func_8004C364(s32 cx, s32 cy, u32 sizex, u32 sizey, u16 * addr);
// kwprintmode_init
void load_debug_font();
// kwprintmode_finish
void func_80057778();
// kw_printd
void print_str_num(u32 tx, u32 ty , char * str, s32 number);


#endif