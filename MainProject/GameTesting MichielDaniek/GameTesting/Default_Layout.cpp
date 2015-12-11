/*
 * Default_Layout.cpp
 *
 * Created: 30-11-2015 12:36:52
 *  Author: michiel
 */
#include "Default_Layout.h" 

extern void showDefaultLayout(MI0283QT9 lcd, MY_USART serial){
	
	lcd.fillScreen(ROADCOLOR);
	lcd.drawRect(0, 0, 20, 320, GRASSCOLOR);
	lcd.drawRect(220, 0, 20, 320, GRASSCOLOR);
		
}