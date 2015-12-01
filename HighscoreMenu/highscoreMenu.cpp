/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "highscoreMenu.h"

uint8_t setValue = 0;

extern void showHighscoreMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial){
	
	lcd.fillScreen(BACKGROUND);
	while(1){
		
		char title[] = "Highscore";
		uint8_t lengthOfString = (strlen(title) * 26); 
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		lcd.drawText(20, 75, "1", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(70, 75, "Eld", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(20, 135, "2", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(70, 135, "Wil", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(20, 195, "3", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(70, 195, "Mic", OBJECTCOLOR, BACKGROUND, 2);
		
		
		if(obj.drawButton(lcd, "Back", 20, 255, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
		
	}
}