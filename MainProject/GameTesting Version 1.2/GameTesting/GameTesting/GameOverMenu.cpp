/*
 * GameOverMenu.cpp
 *
 * Created: 7-12-2015 12:31:14
 *  Author: Eldin
 */ 

#include "GameOverMenu.h"



void showNoHighScore(MI0283QT9 lcd){
	while(1){
		char title[] = "You DIED!";
		uint8_t lengthOfString = (strlen(title) * 26);
		uint8_t x = (240 - lengthOfString);
		
		lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		if(drawButton(lcd, "Restart", 20, 75, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			restartGame = 1;
			break;
		}
		
		//button for opening sub menu generator
		if(drawButton(lcd, "Main Menu", 20, 135, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			returnToMain = 1;
			break;
		}
	}
	
}
	
	
void showGameOverMenu(MI0283QT9 lcd, uint16_t score){
	char char1 = 'A';
	char char2 = 'A';
	char char3 = 'A';
	
	int EEPROMfilled = 0;
	
	if(EEPROM.read(171) != 0 ){
		EEPROMfilled = 1;
	}
	
	lcd.fillScreen(BACKGROUND);
	if(EEPROMfilled == 0){
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

	while(1){
		
		
		if(restartGame){
			restartGame = 1;
			break;
		}
		
		if(returnToMain){
			returnToMain = 1;
			break;
		}
		
		if(EEPROM.read(173) >= score){
			lcd.fillScreen(BACKGROUND);
			showNoHighScore(lcd);
		}else if(EEPROM.read(173) < score) {
			
			char title[] = "Highscore";
			uint8_t lengthOfString = (strlen(title) * 26);
			uint8_t x = (240 - lengthOfString);
			
			lcd.drawText(x, 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			
			lcd.drawInteger(70, 80, score, DEC, OBJECTCOLOR, BACKGROUND, 3);
			
			
			char name[] = "Your Name?";
			uint8_t lengthOfString2 = (strlen(name) * 20);
			uint8_t x2 = (240 - lengthOfString2);
			lcd.drawText(x2, 140, name, OBJECTCOLOR, BACKGROUND, 2);
			
			char1 =	drawCharSelector(lcd, 35, 160, char1);
			char2 =	drawCharSelector(lcd, 95, 160, char2);
			char3 =	drawCharSelector(lcd, 155, 160, char3);
			
			if(drawButton(lcd, "Accept", 20, 240, 200, 40)){
				if(EEPROM.read(171) < score){
					uint8_t scoreaddress1 = EEPROM.read(171);
					char char1Address1 = EEPROM.read(174);
					char char2Address1 = EEPROM.read(175);
					char char3Address1 = EEPROM.read(176);
					uint8_t scoreaddress2 = EEPROM.read(172);
					char char1Address2 = EEPROM.read(177);
					char char2Address2 = EEPROM.read(178);
					char char3Address2 = EEPROM.read(179);
					
					
					EEPROM.write(171, score);
					EEPROM.write(174, char1);
					EEPROM.write(175, char2);
					EEPROM.write(176, char3);
					
					EEPROM.write(172, scoreaddress1);
					EEPROM.write(177, char1Address1);
					EEPROM.write(178, char2Address1);
					EEPROM.write(179, char3Address1);
					
					EEPROM.write(173, scoreaddress2);
					EEPROM.write(180,char1Address2);
					EEPROM.write(181, char2Address2);
					EEPROM.write(182, char3Address2);
					
				}else if(EEPROM.read(172) < score){
					uint8_t scoreaddress2 = EEPROM.read(172);
					char char1Address2 = EEPROM.read(177);
					char char2Address2 = EEPROM.read(178);
					char char3Address2 = EEPROM.read(179);
					
					EEPROM.write(172, score);
					EEPROM.write(177, char1);
					EEPROM.write(178, char2);
					EEPROM.write(179, char3);
					
					EEPROM.write(173, scoreaddress2);
					EEPROM.write(180, char1Address2);
					EEPROM.write(181, char2Address2);
					EEPROM.write(182, char3Address2);
					
				}else if(EEPROM.read(173) < score){
					EEPROM.write(173, score);
					EEPROM.write(180, char1);
					EEPROM.write(181, char2);
					EEPROM.write(182, char3);
				}
				lcd.fillScreen(BACKGROUND);
				showNoHighScore(lcd);
			}

			}
		}
		
		
		
	
	
}