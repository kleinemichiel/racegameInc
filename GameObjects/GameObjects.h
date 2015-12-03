/*
 * IncFile1.h
 *
 * Created: 2-12-2015 14:39:47
 *  Author: Willem
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "stdint.h"
#include "GridLayout.h"

extern void drawCar(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y);
extern void drawTruck(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y);

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