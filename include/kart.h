#ifndef __KART_H
#define __KART_H

#include "common.h"

typedef struct Tire{
	float 			Position[3];			//Tire Location
	unsigned char 	Status;					//Tire Surface
	unsigned char 	LastAxis;
	unsigned short 	LastPointer;
	float 			Height;
	int  			Dummy;					//0000 0000 0000 00001:KAGE ON
} Tire;

typedef struct Smoke{
	float 			trx,try,trz;						//Particle Location[3]
	float 			scale;								//Particle Scale
	unsigned short 	lrflag,number;						//Left-Right Flag (Left=1;Right=0) //Case Number Flag
	float 			type,dev;							//Particle Type //Dev? (Left-Right Flipped?)
	short 			flag,timer,ang;						//On-Off Flag //Destroy Timer //Particle Angle
	float 			fwork1,fwork2,fwork3,fwork4,fwork5;	//Animation Values?
	short 			swork1,swork2,swork3,swork4,swork5;	//Color Value[3] //Alpha //Dithering Noise
	int 			dummy;
} Smoke;

typedef struct Sus{
	short 	flag,flag1; 
	float 	position,accele;
	short 	broken,jump_timer;  
	float 	jump_l,jump_firstspeed,jmp_acc_l;
	short 	gachon_timer,broken_timer; 
	float 	swing_firstspeed,gachon_firstspeed,bound_firstspeed,broken_firstspeed,y_grv;
	short 	bound_timer,swing_timer,swing_flag,bound,swing;
} Sus;


typedef struct Player{
	unsigned short   flag; 					//800F6990 //Player, Comp, Ghost, Etc.
	unsigned short   status; 				//800F6992 //Kart DMA
	short    rank; 							//800F6994 //Current Rank
	unsigned short   point; 				//800F6996 //Current Points
	short    rap; 							//800F6998 //Current Lap
	unsigned int   weapon; 					//800F699C //Item Use & Item Hit Activators
	short    item; 							//800F69A0 //Current Item

	float  position[3];						//800F69A4 //Kart Position
	float  old_position[3];					//800F69B0 //Kart Previous Position
    short  direction[3];					//800F69BE //Kart Forward Direction
	float  velocity[3];						//800F69C4 //Kart Velocity
	short    link_doshin;					//800F69D0 //Indicator Which Thwomp Flattened Kart / Resets On Thwomp Animation Finish
	short    kage_ang;						//800F69D2 //Kart Shadow Rotation Angle (Only In Air)
	short  	 handling_flag; 				//800F69D4 //Control Flags & Trophy Scene Effects
	unsigned short   hit_flag;				//800F69D6 //Hit Flag For Walls, Enemies, Thwomps, Etc.
	short    angle_y[4];					//800F69D8 //Kart Angle Y
	short    angle_z[4];					//800F69E0 //Kart Angle X
	float  up_vector[3];					//800F69E0 //Kart Up Direction
	float  gravity_xz[3];   				//800F69F4 //Kart Gravity

	float    radius;						//800F6A00 //Kart Collision Radius
	float    ground;						//800F6A04 //Kart Shadow Height Position

	short   sterrangle;						//800F6A08 //Current Steering Angle
	short   shake_flag;						//800F6A0A //Kart Engine Shake Flag
	int   	nowsterr;						//800F6A0C //Steering Angle Input
	float   turbo_power;					//800F6A10 //Boost Acceleration

	float	f_grip,r_grip;					//800F6A14 //Kart Front Grip //800F6A18 // Kart Rear Grip
	float   force;							//800F6A1C //Kart Current Input Force Until Max Speed
	float   grip;							//800F6A20 //Kart Main Grip
	float   speed,taco;  					//800F6A24 //Kart Speedometer //800F6A28 //Kart Tachometer


	float  	accelcount;						//800F6A2C //Kart Acceleration
	float 	power_down,power;				//800F6A30 //Kart Downwards Acceleration //800F6A34 //Kart Power?

	short   slipcount,sterr_count;			//800F6A38 //Kart Tumble Timer (Counter) //800F6A3A // Kart Steering Counter?
	short   offsetsterr_flag,old_direction,thunder_timer,spin_timer,offsetsterr_timer;
	unsigned short  talk;  					//800F6A46 //Comic FX & Unset Speech Bubbles
	float 	offsetsterr_speed;
	unsigned int    slip_flag;				//800F6A4C //Kart State Effect Flags
	short 	slipang,jumpcount;  			//800F6A50 //Kart Angle //800F6A52 //Air Timer
	short   kartpitch; 						//800F6A64 //Kart Pitch
	short   erase;							//800F6A56 //Kart Transparency Effects
	short   jugemu_timer;					//800F6A58 //Lakitu Rescue Timer
	short   jugemu_flag; 					//800F6A5A //Lakitu Flags & Effects
	short 	roll[4],pitch[4];				//800F6A5C //Kart Roll //800F6A64 //Kart Pitch
	short   turbo_timer;					//800F6A6C //Boost State Timer
	unsigned short  water_flag;				//800F6A6E //Water & Splash Flag
	short 	bomb_timer,slipstream_timer; 	//800F6A70 //Item/Object Hit Tumble Bounce Counter //800F6A72 //Slipstream Timer
	float   slipstream_power;				//800F6A74 //Slipstream Acceleration

	float   maxadd_power;  					//800F6A78 //Drift Turbo Acceleration
	float   jump,jmp_acc,jmp_speed;			//800F6A7C //Jump //800F6A80 //Jump Acceleration //800F6A84 //Jump Speed
	unsigned short  bump_status; 			//800F6A88 //Current Surface
	short	sterracc; //////NOT USE			//800F6A8A //Steering Angle Input Short

	float 	mass,gravity ;					//800F6A8C //Kart Mass //800F6A90 //Kart Gravity

	float  power_cont,shake;				//800F6A94 //Acceleration Control? Unsure //800F6A98 //Kart Engine Shake Height

	short  hitcount; 						//800F6A9C //Kart Bonk Timer

	Bump	 bump;
	Matrix  align2;  //800F6aE0
	Matrix  align;

	Tire    tire_FL;//800F6B28
	Tire    tire_FR;
	Tire    tire_RL;
	Tire    tire_RR;

    float	mid_front,mid_rear;  //800F6B88
	int		chasesp_sterr;
	short   drift_count,kartroll;  //800F6B96
	float	allrear_grip,brake_time;
	float	max_power,acc_maxcount;			//800F6BA0 //Max Power? //800F6BA4 //Max Acceleration
	float	spark_x,spark_z;
	short	chasepoint;						//800F6BB0 //Path Point for Lakitu Placement
	unsigned short  hangflag;				//800F6BB2 //Lakitu Rescue Flag
	float 	offsetsize;// 800F6BB4
	short   stopsetrr_count,powerstack_count;
	float	old_speed,mid_left;
	short  	hit_sterr,roliover_time;
	short	broken_timer,drift_turbo_timer;
	float	mid_right;


	int 	tcol_count;  //800f6BD0
	unsigned short  dir[4],deg[4];
	unsigned short 	kart,wallhitcount;		//800F6BE4 //Character //800F6BE6 //Timer Wallhit
	Smoke gass[10];
	Smoke smoke[10];
	Smoke letter[10];						//800F7188 //[1] Comic FX //800F71D0 //[2] Speech Bubble
	Smoke spark[10];

	Sus     sus;


} TKart;

#endif