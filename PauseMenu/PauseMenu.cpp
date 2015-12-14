/*
 * PauseMenu.cpp
 *
 * Created: 30-11-2015 14:58:04
 *  Author: michiel
 */ 

#include "PauseMenu.h"


extern void showPauseMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial){
	lcd.fillScreen(BACKGROUND);
	
	while(1){
		
		char title[] = "PauseMenu";
		uint8_t lengthOfString = (strlen(title) * 26);
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, "Pause", OBJECTCOLOR, BACKGROUND, 3);
		if(obj.drawButton(lcd, "Resume Game", 20, 75, 200, 40)){	
			showDefaultLayout(lcd,serial);
			break;
		}
		if(obj.drawButton(lcd, "Restart Game", 20, 135, 200, 40)){
			//showGame(lcd,obj,serial);	
			restartGame = 1;
			break;
		}	
		if(obj.drawButton(lcd, "Settings", 20, 195, 200, 40)){
			showSettingMenu(lcd,obj,serial);
		}
		if(obj.drawButton(lcd, "Main Menu", 20, 255, 200, 40)){
			returnToMain = 1;
		}
		
	}
}
