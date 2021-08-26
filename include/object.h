#ifndef __OBJECT_H
#define __OBJECT_H

#include "common.h"
#include "camera.h"

#define DOSHIN   1	    //Kawaguti's Work
#define TREE1    2
#define TREE2    3
#define TREE3    4
#define IWA      5
#define BANANA   6
#define GSHELL	 7
#define RSHELL	 8
#define EGG	 9	    //KT5 yoshy's valley
#define PAKKUN	 10
#define PUKUPUKU 11
#define IBOX   	 12
#define FAKEIBOX 13
#define SBANANA  14
#define SL1      15
#define SL2      16
#define SL3      17
#define COW      18
#define TREE4    19
#define PYLON    20	    //for example!!!!
#define SGSHELL    21
#define SRSHELL    22
#define MKANBAN    23
#define FIRE       24
#define PALMTREE   25
#define TREE5      26
#define TREE6      27
#define TREE7      28
#define SNOWTREE   29
#define SABOTEN1   30
#define SABOTEN2   31
#define SABOTEN3   32
#define TREE8      33
#define BLUEFIRE   34
#define WKANBAN    35
#define FIREPILLAR 36
#define TRUCK1     37
#define SHIP       38
#define FUMIKIRI   39
#define BUS        40
#define TANKLORRY  41
#define TSHELL	   42
#define SIBOX	   43
#define RV	   44
#define SEDAN	   44
#define NUTS	   45
// custom
#define COIN       46

#define MAX_OBJECTS 100

typedef struct {
			short   category;
			short   flag;
			short   counter;
			short   sparam;
			float   fparam;
			float   radius;
			SVector angle;
			Vector position;
			Vector velocity;
			Bump    bump;
} TObject;

// display_fake_itembox
void func_802A171C(Camera * camera, TObject * object);
// display_itembox
void func_802A1EA0(Camera * camera, TObject * object);

void update_obj_falling_rocks(TObject * obj); 
void update_obj_green_shell(TObject * obj);   
void update_obj_red_blue_shell(TObject * obj); 
void update_obj_red_blue_shell(TObject * obj); 
void update_obj_kiwano_fruit(TObject * obj);   
void update_obj_banana(TObject * obj);         
void update_obj_paddle_wheel(TObject * obj);   
void update_obj_train_engine(TObject * obj);   
void update_obj_train_car1(TObject * obj);     
void update_obj_train_car2(TObject * obj);		
void update_obj_item_box(TObject * obj);		
void update_obj_item_box_hot_air_balloon(TObject * obj);   
void update_obj_fake_item_box(TObject * obj);	
void update_obj_piranha_plant(TObject * obj);  
void update_obj_banana_bunch(TObject * obj);   
void update_obj_triple_shell(TObject * obj, u32 type); 
void update_obj_mario_raceway_sign(TObject * obj); 
void update_obj_wario_stadium_sign(TObject * obj); 
void update_obj_railroad_crossing(TObject * obj);
void update_obj_trees_cacti_shrubs(TObject * obj);
void update_obj_yoshi_valley_egg(TObject * obj);

#endif