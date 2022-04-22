#include <ultra64.h>

#include "object.h"
#include "camera.h"
#include "screen.h"
#include "coin.h"

// object buffer
extern TObject D_8015F9B8[];
// item box flag
extern u32 D_8015F8DC; 
void func_802A0E44();
void func_802B30EC();

void display_object2(Screen * screen)
{
    Camera * camera = screen->camera;
    int     i;
    TObject * obj;

	//itembox_flag
    D_8015F8DC = 0;

	for(i = 0; i < MAX_OBJECTS; i++)
	{
	    obj = (TObject *)&D_8015F9B8[i];
        if(obj->flag == 0)	continue;
        
	    switch(obj->category)
	    {
	        // display_fake_itembox
            case FAKEIBOX:  func_802A171C(camera, obj);     break;
	        // display_itembox
            case IBOX:      func_802A1EA0(camera, obj);     break;
	        // display_itembox
            case SIBOX:     func_802A1EA0(camera, obj);     break;
            case COIN:      display_coin(camera, obj);      break;
	    }
	}
}

void object_strategy1(void)
{
    TObject * obj;
	
    for(u32 i = 0; i < MAX_OBJECTS; i++)
	{
	    obj = (TObject *)&D_8015F9B8[i];
	    if(obj->flag == 0) continue;
	    
        switch(obj->category)
	    {
	        case	IWA:        update_obj_falling_rocks(obj); break;
	        case	GSHELL:     update_obj_green_shell(obj);   break;
	        case	RSHELL:     update_obj_red_blue_shell(obj); break;
	        case	TSHELL:     update_obj_red_blue_shell(obj); break;
	        case    NUTS:       update_obj_kiwano_fruit(obj);   break;
	        case	BANANA:     update_obj_banana(obj);         break;
	        case    SHIP:       update_obj_paddle_wheel(obj);   break;
	        case    SL1:        update_obj_train_engine(obj);   break;
	        case    SL2:        update_obj_train_car1(obj);     break;
	        case    SL3:        update_obj_train_car2(obj);		break;
	        case    IBOX:       update_obj_item_box(obj);		break;
	        case    SIBOX:      update_obj_item_box_hot_air_balloon(obj);   break;
	        case    FAKEIBOX:   update_obj_fake_item_box(obj);	break;
	        case    PAKKUN :    update_obj_piranha_plant(obj);  break;
	        case    SBANANA:    update_obj_banana_bunch(obj);   break;
	        case    SGSHELL:    update_obj_triple_shell(obj, GSHELL); break;
	        case    SRSHELL:    update_obj_triple_shell(obj, RSHELL); break;
	        case    MKANBAN:    update_obj_mario_raceway_sign(obj); break;
	        case    WKANBAN:    update_obj_wario_stadium_sign(obj); break;
	        case    FUMIKIRI:   update_obj_railroad_crossing(obj);  break;
            case    COIN:       update_obj_coin(obj);               break;
	        case    TREE1:            
	        case    TREE2:            
	        case    TREE3:            
	        case    TREE4:            
	        case    TREE5:            
	        case    TREE6:            
	        case    TREE7:            
	        case    TREE8: 
	        case    SNOWTREE:
	        case    SABOTEN1:           
	        case    SABOTEN2:           
	        case    SABOTEN3:           
	        case    PALMTREE:           
                update_obj_trees_cacti_shrubs(obj); break;
	        case    EGG:
                update_obj_yoshi_valley_egg(obj);   break;
	    }
    }
    //collision_object_to_object
    func_802A0E44();
    //item_check
    func_802B30EC();
}