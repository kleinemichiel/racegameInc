/*
 * PauseMenu.cpp
 *
 * Created: 30-11-2015 14:58:04
 *  Author: michiel
 */ 

#include "PauseMenu.h"


extern void showPauseMenu(MI0283QT9 lcd){
	lcd.fillScreen(BACKGROUND);
	
	while(1){
		
		
		lcd.drawText(centerText("Pause", 3), 15, "Pause", OBJECTCOLOR, BACKGROUND, 3);
		if(drawButton(lcd, "Resume Game", 20, 75, 200, 40)){	
			showDefaultLayout(lcd);
			break;
		}
		if(drawButton(lcd, "Restart Game", 20, 135, 200, 40)){
			restartGame = 1;
			break;
		}	
		if(drawButton(lcd, "Settings", 20, 195, 200, 40)){
			showSettingMenu(lcd);
		}
		if(drawButton(lcd, "Main Menu", 20, 255, 200, 40)){
			returnToMain = 1;
		}
		
	}
}
