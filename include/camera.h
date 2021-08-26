#ifndef __CAMERA_H
#define __CAMERA_H

#include "common.h"

typedef struct Shake{
	float	cam_firstspeed,x2;
	short	cam_timer,aaaaaaa; 
	float	offset_look,z2,z3; 
}Shake;

typedef struct Camera {
	float 			camera_pos[3];
	float 			lookat_pos[3];
	float 			up_vector[3];
	unsigned short 			camera_direction[3];
	unsigned short   		flag;
	short   			chase_direction;
	float 			camera_vector[3];
	float 			lookat_vector[3];
	float 			velocity[3];   
	Bump	 			bump;
	Shake			shake;
	short    			old_chase_direction;	
	short    			watch,stickdeg;
	float    			screen_view_angle;
} Camera;

#endif