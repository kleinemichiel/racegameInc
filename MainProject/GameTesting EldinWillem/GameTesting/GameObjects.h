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
#include "menuObjects.h"

//make functions available outside "library" without the need for defining the class
extern void drawCar(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y, uint8_t rgb[2]);
extern void drawTruck(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y, uint8_t rgb[2]);
extern void removeCar(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y);
extern void removeTruck(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y);

//holds information for a car object
struct car
{
	uint8_t lengte =1;
	uint8_t score = lengte;
};

//holds information for a truck object
struct truck
{
	uint8_t lengte =2;
	uint8_t score = lengte;
};


//holds information for all the objects which are going to be printed on screen
typedef struct objects
{
	uint8_t posY;
	uint8_t posX;
	uint8_t type;   //type 1 = car, type 2 = truck
	uint8_t rgb[2];
	
} objects;


#endif /* INCFILE1_H_ */