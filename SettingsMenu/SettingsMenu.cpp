/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "SettingsMenu.h"

//these are values which are being set in the setting menu
extern uint8_t realTime = 0;
extern uint8_t preTime = 0;

extern uint8_t easy = 0;
extern uint8_t medium = 0;
extern uint8_t hard = 0;



//sub menu which contains checkboxes for setting difficulty (easy, medium, hard) including logics to allow only one button to be set
void showDifficulty(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial){
	
	//used to manage one check per set
	uint8_t up = 0;
	uint8_t down = 0;
	uint8_t start = 0;
	
	while(1){
		//drawing checkboxes and text on screen
		lcd.drawText(5, 5, "difficulty", OBJECTCOLOR, BACKGROUND, 3);
		
		lcd.drawText(15, 80 , "EASY  :", OBJECTCOLOR, BACKGROUND, 2);
		obj.drawCheckbox(lcd, 177, (87 - 24), 48, &easy);
		
		lcd.drawText(15, 150, "MEDIUM:", OBJECTCOLOR, BACKGROUND, 2);
		obj.drawCheckbox(lcd, 177, (157 - 24), 48, &medium);
		
		lcd.drawText(15, 220, "HARD  :", OBJECTCOLOR, BACKGROUND, 2);
		obj.drawCheckbox(lcd, 177, (227 - 24), 48, &hard);
		
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
			//serial.sendString("easy\n");
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
			//serial.sendString("medium\n");
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
			//serial.sendString("hard\n");
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
		
		// if(!easy && !medium && !hard){
		// 	serial.sendString("nothing");
		// }
		
		
		if(obj.drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}

//sub menu which contains checkboxes for setting generator options (realtime, pretime) including logics to allow only one button to be set
void showGenerator(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial){
	
	uint8_t up = 0;
	uint8_t down = 0;
	uint8_t start = 0;
	while(1){
		
		char title[] = "Generator";
		uint8_t lengthOfString = (strlen(title) * 26);
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		lcd.drawText(15, 90 , "Real-Time:", OBJECTCOLOR, BACKGROUND, 2);
		obj.drawCheckbox(lcd, 177, (97 - 24), 48, &realTime);
		
		lcd.drawText(15, 180, "Pre-Time :", OBJECTCOLOR, BACKGROUND, 2);
		obj.drawCheckbox(lcd, 177, (187 - 24), 48, &preTime);
		
		
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
			//serial.sendString("preTime selected \n");
			
			if(realTime){
				preTime = 0;
				up = 0;
				down = 1;
			}
			
		} 
		
		if(realTime && down){
			//serial.sendString("realTime selected\n");
			if(preTime){
				realTime = 0;
				up = 1;
				down = 0;
			}
		} 
		
		
		
		if(obj.drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}

//main menu with buttons for accesing sub menus 
extern void showSettingMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial){
	
	
	while(1){
		
		char title[] = "Settings";
		uint8_t lengthOfString = (strlen(title) * 26); 
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		//button for opening sub menu difficulty
		if(obj.drawButton(lcd, "Difficulty", 20, 75, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showDifficulty(lcd, obj, serial);
		}
		
		//button for opening sub menu generator
		if(obj.drawButton(lcd, "Generator", 20, 135, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			showGenerator(lcd, obj, serial);
		}
		
		//button for resetting score
		obj.drawButton(lcd, "Reset Score", 20, 195, 200, 40);
		
		//button to return to main menu
		if(obj.drawButton(lcd, "Back", 20, 270, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
	}
}