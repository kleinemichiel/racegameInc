/*
 * IncFile1.h
 *
 * Created: 2-12-2015 14:39:47
 *  Author: Willem
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "stdint.h"
struct car
{
	uint8_t lengte =1;
	uint8_t score = lengte;
};

struct truck
{
	uint8_t lengte =2;
	uint8_t score = lengte;
};


struct objects
{
	uint8_t posY;
	uint8_t posX;
	uint8_t type;   //type 1 = car, type 2 = truck
	
};


#endif /* INCFILE1_H_ */