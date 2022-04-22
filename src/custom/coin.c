#include <ultra64.h>

#include "camera.h"
#include "object.h"
#include "variables.h"
#include "sprite.h"
#include "common.h"

#include "model_coin.h"

extern Controller gControllers[];

extern Gfx * gDisplayListHead;
extern u8 _objectSegmentRomStart[];
extern u8 _objectSegmentRomEnd[];
extern u8 _objectSegmentStart[];

s32 flag = 0;

void place_blocks_coins_Donut()
{
    Vector vec;
    Vector velo;
    SVector angle;
    vec[0] = -40.0f;
    vec[1] = 222.0f + 8.0f;
    vec[2] = 824.0f;

    angle[0] = 0;
    angle[1] = 0;
    angle[2] = 0;

    velo[0] = 0.0f;
    velo[1] = 0.0f;
    velo[2] = 0.0f;

    place_all_item_boxes(0x06000058);
    func_8029EC88(vec, angle, velo, COIN);
}

void update_obj_coin(TObject * obj)
{
    //Vector vec = {gPlayer1PosX, gPlayer1PosY, gPlayer1PosZ};
    Vector velo;
    SVector angle;
    Vector * vec = (Vector *)&gPlayer1PosX; 
    
    angle[0] = 0;
    angle[1] = 0;
    angle[2] = 0;

    velo[0] = 0.0f;
    velo[1] = 0.0f;
    velo[2] = 0.0f;
    
    // speen
    obj->angle[1] += 360*4;

    if (gControllers[0].ButtonReleased & CONT_B) {
        if (flag == FALSE) {
            func_8029EC88(*vec, angle, velo, COIN);
            flag = TRUE;
        }
    }

    if (!(gControllers[0].ButtonReleased & CONT_B)) {
        flag = FALSE;
    }

    
    // kw_sprite
    //func_8004C364(50-16, 46-16, 16, 16, (u16 *)coin_hud_texture);
    //load_debug_font();
    //print_str_num(0-16, -8, "", 0);
    //print_str_num(24-16, -8, "/", 25);
    //func_8004C364(50-16, 164-16, 16, 16, (u16 *)coin_hud_texture);
    //load_debug_font();
    //print_str_num(0-16, 112, "", 0);
    //print_str_num(24-16, 112, "/", 25);
    //func_80057778();
    
}

void display_coin(Camera * camera, TObject * obj)
{
    AffineMtx aff;

    func_802B5F74(aff, obj->position, obj->angle);
    func_802B5F00(aff, 0.01f);
	if(func_802B4FF8(aff, LOADNOPUSH) == FALSE)  return;

    func_8004C364(50-16, 46-16, 16, 16, (u16 *)coin_hud_texture);
    load_debug_font();
    print_str_num(0-16, -8, "", 0);
    print_str_num(24-16, -8, "/", 25);
    func_8004C364(50-16, 164-16, 16, 16, (u16 *)coin_hud_texture);
    load_debug_font();
    print_str_num(0-16, 112, "", 0);
    print_str_num(24-16, 112, "/", 25);
    func_80057778();
    
    gSPDisplayList(gDisplayListHead++, coin_Coin_16_mesh);

}

/*
void func_8006B8B4(s32 arg0, s8 arg1) {
    
    s16 * sp1C;
    s16 * temp_v1;
    s16 temp_a3;
    s32 temp_a0;
    s8 temp_a2;
    u16 * temp_v0;
    u16 temp_t5;

    temp_v1 = (arg1 * 2) + &D_8018D8C0;
    temp_a3 = *temp_v1;
    temp_a2 = arg1;
    if ((s32) temp_a3 >= 0) {
        temp_v0 = (arg1 * 6) + (temp_a3 * 2) + &D_8018D5F0;
        temp_t5 = *temp_v0 & 0xFFFE;
        *temp_v0 = temp_t5;
        *temp_v0 = (u16) (temp_t5 | 2);
        *temp_v1 = (s16) (temp_a3 - 1);
        temp_a0 = temp_a2 & 0xFF;
        sp1C = temp_v1;
        arg1 = temp_a2;
        func_800C9060(temp_a0, 0x19009051, temp_a2, temp_a3);
        if ((s32) *temp_v1 < 0) {
            func_8008FD4C(arg0, arg1, arg1);
        }
    }
}
*/