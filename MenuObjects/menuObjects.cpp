/*
 * menuObjects.cpp
 * drawButton() = creates buttons at given location
 * !-- this class needs an activated lcd object being passed through the function "MI0283QT9 lcd" --!
 * Created: 26-11-2015 16:58:51
 *  Author: Eldin
 */ 

#include "menuObjects.h"

uint8_t MENUOBJECTS::drawButton(MI0283QT9 lcd, char text[], uint16_t x, uint16_t y, uint16_t w, uint16_t h){
	
	uint16_t textWidth = (8 * strlen(text));
	uint8_t buttonPressed = 0;
	
	lcd.touchRead();
	
	if(lcd.touchZ() && lcd.touchX() >= x && lcd.touchX() <= (x + w) && lcd.touchY() >= y && lcd.touchY() <= (y + h)){
	
		lcd.fillRect(x, y,w,h, OBJECTCOLOR);
		lcd.drawText(x + ((w / 2) - textWidth), (y + (h / 2) - 8) , text, BACKGROUND, OBJECTCOLOR, 2);
		
		_delay_ms(500);
		
		lcd.fillRect(x, y,w,h, BACKGROUND);
		
		buttonPressed = 1;
	
	} else {
		
		lcd.drawRect(x, y,w,h, OBJECTCOLOR);
		lcd.drawText(x + ((w / 2) - textWidth), (y + (h / 2) - 8) , text, OBJECTCOLOR, BACKGROUND, 2);
		
		buttonPressed = 0;
		
	}
		
	return buttonPressed;
}
