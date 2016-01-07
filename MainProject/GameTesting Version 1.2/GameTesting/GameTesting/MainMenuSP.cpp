/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "MainMenuSP.h"



uint8_t setValue = 0;

extern void showMainMenu(MI0283QT9 lcd){
	
	returnToMain = 0;
	
	while(1){
		
		if(drawButton(lcd, "SinglePlayer", 20, 55, 200, 40)){
			showGame(lcd);
		} else if(drawButton(lcd, "Multiplayer", 20, 105, 200, 40)){
			showMpMenu(lcd);
		} else if(drawButton(lcd, "Settings", 20, 155, 200, 40)){
			showSettingMenu(lcd);
		} else if(drawButton(lcd, "Highscore", 20, 205, 200, 40)){
			showHighscoreMenu(lcd);
		} else {
			char title[] = "RaceGame";
			
			lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			lcd.drawRect(100, 250, 40, 64, RGB(red,green,blue));
			lcd.drawLine(100+1,250+16,100+10, 250+26, RGB(red,green,blue));
			lcd.drawLine(100+39,250+16,100+30, 250+26, RGB(red,green,blue));
			lcd.drawLine(100+10,250+26,100+30, 250+26, RGB(red,green,blue));
			lcd.drawLine(100+10,250+38,100+30, 250+38, RGB(red,green,blue));
			lcd.drawLine(100+1,250+48,100+10, 250+38, RGB(red,green,blue));
			lcd.drawLine(100+39,250+48,100+30, 250+38, RGB(red,green,blue));
			lcd.drawLine(100+10,250+26,100+10, 250+38, RGB(red,green,blue));
			lcd.drawLine(100+30,250+26,100+30, 250+38, RGB(red,green,blue));
			lcd.drawLine(100,250+16,100+38, 250+16, RGB(red,green,blue));
			lcd.drawLine(100,250+48,100+38, 250+48, RGB(red,green,blue));
		}
		
		
	}
}