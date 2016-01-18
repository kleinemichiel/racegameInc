/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "SettingsMenu.h"

//these are values which are being set in the setting menu
extern uint8_t easy = 1;
extern uint8_t medium = 0;
extern uint8_t hard = 0;

extern uint8_t sLow = 1;
extern uint8_t sMedium = 0;
extern uint8_t sHigh = 0;

extern uint8_t red = 255;
extern uint8_t blue = 255;
extern uint8_t green = 255;

void showPlayerColor(MI0283QT9 lcd){
	
	while(1){
	
		lcd.drawText(centerText("Color", 3), 15, "Color", OBJECTCOLOR, BACKGROUND, 3);

		red = drawSlider(lcd, 60, red, red, 0,0);

		green = drawSlider(lcd, 100, green , 0 , green, 0);
		
		blue = drawSlider(lcd, 140, blue, 0, 0 , blue);
		
		//draw a car
		lcd.drawRect(100, 180, 40, 64, RGB(red,green,blue));
		lcd.drawLine(100+1,180+16,100+10, 180+26, RGB(red,green,blue));
		lcd.drawLine(100+39,180+16,100+30, 180+26, RGB(red,green,blue));
		lcd.drawLine(100+10,180+26,100+30, 180+26, RGB(red,green,blue));
		lcd.drawLine(100+10,180+38,100+30, 180+38, RGB(red,green,blue));
		lcd.drawLine(100+1,180+48,100+10, 180+38, RGB(red,green,blue));
		lcd.drawLine(100+39,180+48,100+30, 180+38, RGB(red,green,blue));
		lcd.drawLine(100+10,180+26,100+10, 180+38, RGB(red,green,blue));
		lcd.drawLine(100+30,180+26,100+30, 180+38, RGB(red,green,blue));
		lcd.drawLine(100,180+16,100+38, 180+16, RGB(red,green,blue));
		lcd.drawLine(100,180+48,100+38, 180+48, RGB(red,green,blue));
	
		if(drawButton(lcd, "Accept", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}

//main menu with buttons for accesing sub menus 
extern void showSettingMenu(MI0283QT9 lcd){
	
	lcd.fillScreen(BACKGROUND);
	
	
	uint8_t difButtonState = 0;
	if(easy){
		difButtonState = 0;
	} else if(medium){
		difButtonState = 1;
	} else if(hard){
		difButtonState = 2;
	}
	
	
	uint8_t senButtonState = 0;
	if(sLow){
		senButtonState = 0;
	} else if(sMedium) {
		senButtonState = 1;
	} else if(sHigh){
		senButtonState = 2;
	}
	
	while(1){
		if(returnToMain){
			returnToMain=0;
			lcd.fillScreen(BACKGROUND);
			break;
		}
		
		char title[] = "Settings";
		lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		lcd.drawText(centerText("Difficulty:", 2), 50, "Difficulty:", OBJECTCOLOR, BACKGROUND, 2);
		
		char difficultyString[8] = " EASY ";
		if(difButtonState == 0){
			easy = 1;
			medium = 0;
			hard = 0;
			strcpy(difficultyString, " EASY ");
		} else if(difButtonState == 1 ){
			easy = 0;
			medium = 1;
			hard = 0;
			strcpy(difficultyString, "MEDIUM");
		} else if(difButtonState == 2){
			easy = 0;
			medium = 0;
			hard = 1;
			strcpy(difficultyString, " HARD ");
		} else {
			difButtonState = 0;
		}
		
		if(drawButton(lcd, difficultyString, 20, 70, 200, 30))
		{
			
			difButtonState++;
		}
		
		
		
		lcd.drawText(centerText("Tilt Sens:", 2), 110, "Tilt Sens:", OBJECTCOLOR, BACKGROUND, 2);
		char senseString[8] = " LOW ";
		
		
		if(senButtonState == 0){
			sLow = 1;
			sMedium = 0;
			sHigh = 0;
			strcpy(senseString, " LOW ");
		} else if(senButtonState == 1){
			sLow = 0;
			sMedium = 1;
			sHigh = 0;
			strcpy(senseString, "MEDIUM");
		} else if(senButtonState == 2 ){
			sLow = 0;
			sMedium = 0;
			sHigh = 1;
			strcpy(senseString, " HIGH ");
		} else {
			senButtonState = 0;
		}
		
		if(drawButton(lcd, senseString, 20, 130, 200, 30))
		{
			senButtonState++;
		}
		
		
		//button for opening sub menu player color
		if(drawButton(lcd, "Color", 20, 170, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showPlayerColor(lcd);
		}
		
		//button for resetting score
		if(drawButton(lcd, "Reset Score", 20, 220, 200, 40)){
			EEPROM.write(171, 0);
			EEPROM.write(174, 'A');
			EEPROM.write(175, 'A');
			EEPROM.write(176, 'A');
			
			EEPROM.write(172, 0);
			EEPROM.write(177, 'A');
			EEPROM.write(178, 'A');
			EEPROM.write(179, 'A');
			
			EEPROM.write(173, 0);
			EEPROM.write(180, 'A');
			EEPROM.write(181, 'A');
			EEPROM.write(182, 'A');
		}
		
		//button to return to main menu
		if(drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}