/*
 * menuObjects.h
 * drawButton() = creates buttons at given location
 * !-- this class needs an activated lcd object being passed through the function "MI0283QT9 lcd" --!
 * Created: 26-11-2015 16:49:40
 *  Author: Eldin
 */ 


#ifndef MENUOBJECTS_H_
#define MENUOBJECTS_H_

//necessary includes, in case not included on main program
//#include <stdint.h>
#include <avr/delay.h>
#include "MI0283QT9.h"

class MENUOBJECTS
{

	public:
	uint8_t drawButton(MI0283QT9 lcd, char text[], uint16_t x, uint16_t y, uint16_t w, uint16_t h);
	uint8_t drawSlider(MI0283QT9 lcd ,uint16_t y, uint8_t sValue, uint8_t sRed, uint8_t sGreen, uint8_t sBlue);
	void drawCheckbox(MI0283QT9 lcd, uint16_t x, uint16_t y, uint16_t s, uint8_t *setValue);	
	char drawCharSelector(MI0283QT9 lcd, uint16_t x, uint16_t y, char previous);
};
#endif /* MENUOBJECTS_H_ */

//default colors
#define OBJECTCOLOR RGB(255,0,0)
#define BACKGROUND RGB(0,0,0)
