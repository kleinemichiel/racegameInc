/*
 * GameOverMenu.cpp
 *
 * Created: 7-12-2015 12:31:14
 *  Author: Eldin
 */ 

#include "GameOverMenu.h"


void showNoHighScore(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial){
	while(1){
		char title[] = "You DIED!";
		uint8_t lengthOfString = (strlen(title) * 26);
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		if(obj.drawButton(lcd, "Restart", 20, 75, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showGame(lcd, serial);
		}
		
		//button for opening sub menu generator
		if(obj.drawButton(lcd, "Main Menu", 20, 135, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showMainMenu(lcd, obj, serial);
		}
	}
	
}
	
	
void showGameOverMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial, uint16_t score){
	char char1 = 'A';
	char char2 = 'A';
	char char3 = 'A';
	

	while(1){
		if(0){
			
		} else if(1) {
			
			char title[] = "Highscore";
			uint8_t lengthOfString = (strlen(title) * 26);
			uint8_t x = (240 - lengthOfString);
			
			lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			
			lcd.drawInteger(70, 80, score, DEC, OBJECTCOLOR, BACKGROUND, 3);
			
			
			char name[] = "Your Name?";
			uint8_t lengthOfString2 = (strlen(name) * 20);
			uint8_t x2 = (240 - lengthOfString2);
			lcd.drawText(x2, 140, name, OBJECTCOLOR, BACKGROUND, 2);
			
			char1 =	obj.drawCharSelector(lcd, 35, 160, char1);
			char2 =	obj.drawCharSelector(lcd, 95, 160, char2);
			char3 =	obj.drawCharSelector(lcd, 155, 160, char3);
			
			if(obj.drawButton(lcd, "Accept", 20, 240, 200, 40)){
				lcd.fillScreen(BACKGROUND);
				showNoHighScore(lcd,obj,serial);
			}
		}
		
		
		
	
	}
}