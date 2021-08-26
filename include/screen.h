#ifndef __SCREEN_H
#define __SCREEN_H

#include "common.h"
#include "camera.h"
#include "kart.h"

typedef struct Viewport{
	short	ScaleWidth;
	short	ScaleHeight;
	short	ScaleDepth;
	short	ScalePad;
	short	TranslateWidth;
	short	TranslateHeight;
	short	TranslateDepth;
	short	TranslatePad;
} Viewport;

typedef struct Screen{
	Controller	*cont;
	Camera	     *camera;
	TKart	     *kart;
	AffineMtx		*matrix;
	Viewport		viewport;
	float 	   	screen_aspect;
	float      	screen_angle;
	short      	horizon;
	short      	pad;
	short      	width;
	short      	height;
	short	   	posx;
	short      	posy;
	short      	flag;
	short      	camera_direction;
	short      	camera_point;
} Screen;

#endif