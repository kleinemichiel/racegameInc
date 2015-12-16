/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "MainMenuSP.h"



uint8_t setValue = 0;

extern void showMainMenu(MI0283QT9 lcd){
	
	lcd.fillScreen(BACKGROUND);
	while(1){
		
		char title[] = "RaceGame";
		uint8_t lengthOfString = (strlen(title) * 26); 
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		if(drawButton(lcd, "Singleplayer", 20, 55, 200, 40)){
			showGame(lcd);
		}
		if(drawButton(lcd, "Settings", 20, 110, 200, 40)){
			showSettingMenu(lcd);
		}
		if(drawButton(lcd, "Highscore", 20, 165, 200, 40)){
			showHighscoreMenu(lcd);
		}
		lcd.drawRect(100, 235, 40, 64, RGB(red,green,blue));
		lcd.drawLine(100+1,235+16,100+10, 235+26, RGB(red,green,blue));
		lcd.drawLine(100+39,235+16,100+30, 235+26, RGB(red,green,blue));
		lcd.drawLine(100+10,235+26,100+30, 235+26, RGB(red,green,blue));
		lcd.drawLine(100+10,235+38,100+30, 235+38, RGB(red,green,blue));
		lcd.drawLine(100+1,235+48,100+10, 235+38, RGB(red,green,blue));
		lcd.drawLine(100+39,235+48,100+30, 235+38, RGB(red,green,blue));
		lcd.drawLine(100+10,235+26,100+10, 235+38, RGB(red,green,blue));
		lcd.drawLine(100+30,235+26,100+30, 235+38, RGB(red,green,blue));
		lcd.drawLine(100,235+16,100+38, 235+16, RGB(red,green,blue));
		lcd.drawLine(100,235+48,100+38, 235+48, RGB(red,green,blue));
		
	}
}