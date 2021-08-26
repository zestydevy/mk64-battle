#ifndef __COMMON_H
#define __COMMON_H

typedef float	Vector[3];			/* 	3 floats	*/
typedef short	SVector[3];			/* 	3 shorts	*/
typedef	float	RotateMtx[3][3];			/* 3x3 rotation matrix					*/
typedef 	float	AffineMtx[4][4];			/* 4x4 affine transformation matrix		*/
typedef 	float	Matrix[3][3];			/* 4x4 affine transformation matrix		*/

typedef struct Bump{

	unsigned short 	flag_xy;
	unsigned short 	flag_yz;
	unsigned short 	flag_zx;

	unsigned short 	last_xy;
	unsigned short 	last_yz;
	unsigned short 	last_zx;

	float    		distance_xy;
	float    		distance_yz;	   
	float    		distance_zx;	   

	float  			bump_xy[3];
	float  			bump_yz[3];
	float  			bump_zx[3];

	int				dummy;

} Bump;

typedef struct Controller{

	short			AnalogX;
	short			AnalogY;

	unsigned short		ButtonHeld;
	unsigned short		ButtonPressed;
	unsigned short		ButtonReleased;
	unsigned short  	AnalogHeld;
	unsigned short  	AnalogPressed;
	unsigned short  	AnalogReleased;

} Controller;

#endif