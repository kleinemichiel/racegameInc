/*
 * Default_Layout.cpp
 *
 * Created: 30-11-2015 12:36:52
 *  Author: michiel
 */
#include "Default_Layout.h" 

extern void showDefaultLayout(MI0283QT9 lcd, MY_USART serial){
	
	
		lcd.fillRect(0, 0,240,320, GRASSCOLOR);	
		lcd.fillRect(35,0,170,320, ROADCOLOR);	
		
}