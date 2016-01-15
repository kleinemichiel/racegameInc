/*
 * menuObjects.cpp
 * drawButton() = creates buttons at given location
 * !-- this class needs an activated lcd object being passed through the function "MI0283QT9 lcd" --!
 * Created: 26-11-2015 16:58:51
 *  Author: Eldin
 */ 
#include "menuObjects.h"
//creates buttons with somewhat visual feedback when touched, returns 1 or 0 depending on press
uint8_t drawButton(MI0283QT9 lcd, char text[], uint16_t x, uint16_t y, uint16_t w, uint16_t h){
	
	uint16_t textWidth = (8 * strlen(text));
	uint8_t returnvalue = 0;
	
	lcd.touchRead();
	
	lcd.drawRect(x, y,w,h, OBJECTCOLOR);
	lcd.drawText(x + ((w / 2) - textWidth), (y + (h / 2) - 8) , text, OBJECTCOLOR, BACKGROUND, 2);
	
	if(lcd.touchZ() && lcd.touchX() >= x && lcd.touchX() <= (x + w) && lcd.touchY() >= y && lcd.touchY() <= (y + h)){
	
		lcd.fillRect(x, y,w,h, OBJECTCOLOR);
		lcd.drawText(x + ((w / 2) - textWidth), (y + (h / 2) - 8) , text, BACKGROUND, OBJECTCOLOR, 2);
		
		_delay_ms(500);
		
		lcd.fillRect(x, y,w,h, BACKGROUND);
		
		returnvalue = 1;
		
	} 
		return returnvalue;
}
//creates a slider. If you click on the slider it will create a new fillrect on the position you touched.
uint8_t drawSlider(MI0283QT9 lcd, uint16_t y, uint8_t sValue, uint8_t sRed, uint8_t sGreen, uint8_t sBlue){
	
	uint8_t sliderValue = sValue;
	uint8_t prevSliderValue = 0;
	
	lcd.drawRect(20,y,200,10, OBJECTCOLOR);
	lcd.fillRect((sliderValue*0.785)+10, y-5, 20,20, RGB(sRed, sGreen, sBlue));
	
	lcd.touchRead();
	if(lcd.touchZ() && lcd.touchX() >= 20 && lcd.touchX() <= 200 && lcd.touchY() >= y-5 && lcd.touchY() <= (y + 15))
	{
		prevSliderValue = sliderValue;
		sliderValue = (lcd.touchX()*1.0625);
		lcd.fillRect((prevSliderValue*0.785)+10, y-5, 20,20, BACKGROUND);
		lcd.fillRect((sliderValue*0.785)+10, y-5, 20,20, OBJECTCOLOR);
	}
	
	return sliderValue;
}
//creates checkboxes which need a pointer to a int acting as a bool. The value of the pointer changes when you press the checkbox. If the value changes to 1 then the checkbox will be 'selected' and if the value changes to 0 then the checkbox will be 'not selected'.
void drawCheckbox(MI0283QT9 lcd, uint16_t x, uint16_t y, uint16_t s, uint8_t *setValue)
{
	
	
	if(*setValue){
		lcd.fillRect(x, y,s,s, OBJECTCOLOR);
	} else {
		lcd.fillRect(x, y,s,s, BACKGROUND);
	}
	
	lcd.touchRead();
	
	if(lcd.touchZ() && lcd.touchX() >= x && lcd.touchX() <= (x + s) && lcd.touchY() >= y && lcd.touchY() <= (y + s))
	{
		if(!*setValue){
			*setValue = 1;
			lcd.fillRect(x, y,s,s, OBJECTCOLOR);
		} else if(*setValue){
			*setValue = 0;
			lcd.fillRect(x, y,s,s, BACKGROUND);
		}
	}
	else 
	{	
		lcd.drawRect(x, y,s,s, OBJECTCOLOR);
	}
}
//function for center the text, you are able to center the text for every size you can choose.
uint8_t centerText(char text[], uint8_t size){
	if(size == 2){
		uint8_t textWidth = (8 * strlen(text));
		return (240 / 2) - textWidth;
	} else if(size == 3){
		uint8_t textWidth = (12 * strlen(text));
		return (240 / 2) - textWidth;
	} else if(size == 1) {
		uint8_t textWidth = (4 * strlen(text));
		return (240 / 2) - textWidth;
	} else {
		return 0;
	}
}	
	
//Creates a button. If you click on the button the next letter will be printed in the button.
char buttonChar[] = "A";
char drawCharSelector(MI0283QT9 lcd, uint16_t x, uint16_t y, char previous){
	
	buttonChar[0] = previous;
	
	if(buttonChar[0] == '['){
		buttonChar[0] = 'A';
	}
	
	if(drawButton(lcd, buttonChar, x, y, 50, 50)){
		buttonChar[0]++;
		drawButton(lcd, buttonChar, x, y, 50, 50);
	}
	
	return buttonChar[0];
}