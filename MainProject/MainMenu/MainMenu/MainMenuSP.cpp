/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "MainMenuSP.h"
#include "SettingsMenu.h"
#include "highscoreMenu.h"


uint8_t setValue = 0;

extern void showMainMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial){
	
	lcd.fillScreen(BACKGROUND);
	while(1){
		
		char title[] = "Settings";
		uint8_t lengthOfString = (strlen(title) * 26); 
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, "RaceGameInc", OBJECTCOLOR, BACKGROUND, 3);
		if(obj.drawButton(lcd, "Singleplayer", 20, 75, 200, 40)){
			
		}
		if(obj.drawButton(lcd, "Settings", 20, 135, 200, 40)){
			showSettingMenu(lcd,obj,serial);
		}
		if(obj.drawButton(lcd, "Highscore", 20, 195, 200, 40)){
			showHighscoreMenu(lcd,obj,serial);
		}
		
	}
}