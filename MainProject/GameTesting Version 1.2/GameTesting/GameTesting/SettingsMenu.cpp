/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "SettingsMenu.h"

//these are values which are being set in the setting menu
extern uint8_t realTime = 1;
extern uint8_t preTime = 0;

extern uint8_t easy = 1;
extern uint8_t medium = 0;
extern uint8_t hard = 0;

extern uint8_t sLow = 1;
extern uint8_t sMedium = 0;
extern uint8_t sHigh = 0;

extern uint8_t red = 255;
extern uint8_t blue = 255;
extern uint8_t green = 255;

void showSensitivity(MI0283QT9 lcd){
	
	uint8_t sUp = 0;
	uint8_t sDown = 0;
	uint8_t sStart = 0;
	
	while(1){
		lcd.drawText(0, 15, "Sensitivity", OBJECTCOLOR, BACKGROUND, 3);
	
		//drawing checkboxes and text on screen
		
		lcd.drawText(15, 80 , "LOW  :", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (87 - 24), 48, &sLow);
		
		lcd.drawText(15, 150, "MEDIUM:", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (157 - 24), 48, &sMedium);
		
		lcd.drawText(15, 220, "HIGH  :", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (227 - 24), 48, &sHigh);
		
		//logics for only 1 checked per click
		if(sLow && !sStart)
		{
			sStart = 1;
			sUp = 1;
		}
		else if(sMedium && !sStart)
		{
			sStart = 1;
			sUp = 0;
			sDown = 0;
		}
		else if(sHigh && !sStart)
		{
			sStart = 1;
			sDown = 1;
		}
		
		
		if(sLow && sUp){
			if(sMedium){
				sLow = 0;
				sUp = 0;
				sDown = 0;
			}
			
			if(sHigh){
				sLow = 0;
				sUp = 0;
				sDown = 1;
			}
		}
		
		if(sMedium && !sUp && !sDown){
			if(sLow){
				sMedium = 0;
				sUp = 1;
				sDown = 0;
			}
			
			if(sHigh){
				sMedium = 0;
				sUp = 0;
				sDown = 1;
			}
		}
		
		if(sHigh && sDown){
			if(sMedium){
				sHigh = 0;
				sUp = 0;
				sDown = 0;
			}
			
			if(sLow){
				sHigh = 0;
				sUp = 1;
				sDown = 0;
			}
		}
	
		if(drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}

void showPlayerColor(MI0283QT9 lcd){
	
	while(1){
	
		lcd.drawText(0, 15, "Color", OBJECTCOLOR, BACKGROUND, 3);

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



//sub menu which contains checkboxes for setting difficulty (easy, medium, hard) including logics to allow only one button to be set
void showDifficulty(MI0283QT9 lcd){
	
	//used to manage one check per set
	uint8_t up = 0;
	uint8_t down = 0;
	uint8_t start = 0;
	
	while(1){
		//drawing checkboxes and text on screen
		lcd.drawText(0, 15, "Difficulty", OBJECTCOLOR, BACKGROUND, 3);
		
		lcd.drawText(15, 80 , "EASY  :", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (87 - 24), 48, &easy);
		
		lcd.drawText(15, 150, "MEDIUM:", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (157 - 24), 48, &medium);
		
		lcd.drawText(15, 220, "HARD  :", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (227 - 24), 48, &hard);
		
		//logics for only 1 checked per click
		if(easy && !start)
		{
			start = 1;
			up = 1;
		}
		else if(medium && !start)
		{
			start = 1;
			up = 0;
			down = 0;
		}
		else if(hard && !start)
		{
			start = 1;
			down = 1;
		}
		
		
		if(easy && up){
			if(medium){
				easy = 0;
				up = 0;
				down = 0;
			}
			
			if(hard){
				easy = 0;
				up = 0;
				down = 1;
			}
		}
		
		if(medium && !up && !down){
			if(easy){
				medium = 0;
				up = 1;
				down = 0;
			}
			
			if(hard){
				medium = 0;
				up = 0;
				down = 1;
			}
		}
		
		if(hard && down){
			if(medium){
				hard = 0;
				up = 0;
				down = 0;
			}
			
			if(easy){
				hard = 0;
				up = 1;
				down = 0;
			}
		}
		
		
		if(drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}


void ShowPlayerSettings(MI0283QT9 lcd){
	while(1){
		lcd.drawText(0, 15, "Player", OBJECTCOLOR, BACKGROUND, 3);
		
		if(drawButton(lcd, "Difficulty", 20, 75, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showDifficulty(lcd);
		}
		
		if(drawButton(lcd, "Color", 20, 135, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showPlayerColor(lcd);
		}
		
		if(drawButton(lcd, "Sensitivity", 20, 195, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showSensitivity(lcd);
		}
		if(drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
		
	}
}

//sub menu which contains checkboxes for setting generator options (realtime, pretime) including logics to allow only one button to be set
void showGenerator(MI0283QT9 lcd){
	
	uint8_t up = 0;
	uint8_t down = 0;
	uint8_t start = 0;
	while(1){
		
		char title[] = "Generator";
		uint8_t lengthOfString = (strlen(title) * 26);
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		lcd.drawText(15, 90 , "Real-Time:", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (97 - 24), 48, &realTime);
		
		lcd.drawText(15, 180, "Pre-Time :", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (187 - 24), 48, &preTime);
		
		
		if(preTime && !start){
			up = 1;
			down = 0;
			start = 1;
		} else if(realTime && !start){
			up = 0;
			down = 1;
			start = 1;
		}
		
		if(preTime && up){
			
			if(realTime){
				preTime = 0;
				up = 0;
				down = 1;
			}
			
		} 
		
		if(realTime && down){
			if(preTime){
				realTime = 0;
				up = 1;
				down = 0;
			}
		} 
		
		
		
		if(drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}

//main menu with buttons for accesing sub menus 
extern void showSettingMenu(MI0283QT9 lcd){
	
	lcd.fillScreen(BACKGROUND);
	
	while(1){
		
		char title[] = "Settings";
		uint8_t lengthOfString = (strlen(title) * 26); 
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		//button for opening sub menu difficulty
		if(drawButton(lcd, "Player", 20, 75, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			ShowPlayerSettings(lcd);
		}
		
		//button for opening sub menu generator
		if(drawButton(lcd, "Generator", 20, 135, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showGenerator(lcd);
		}
		
		//button for resetting score
		if(drawButton(lcd, "Reset Score", 20, 195, 200, 40)){
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