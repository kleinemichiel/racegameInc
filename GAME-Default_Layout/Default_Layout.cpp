/*
 * Default_Layout.cpp
 *
 * Created: 30-11-2015 12:36:52
 *  Author: michiel
 */ 

extern void showDefaultLayout(MI0283QT9 lcd, MY_USART serial){
	
	
	while(1){	
		lcd.fillRect(0, 0,240,320, ROADCOLOR);	
		lcd.fillRect(20,0,200,320, GRASSCOLOR);	
	}
}