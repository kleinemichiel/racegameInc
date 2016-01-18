/*
 * SettingsMenu.cpp
 *
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include "highscoreMenu.h"
/*
Highscore Menu with the top 3 scores and a back button to main menu.
*/
extern void showHighscoreMenu(MI0283QT9 lcd){
	
	lcd.fillScreen(BACKGROUND);
	//read the name characters from eeprom to put them in a string.
	char char1 = EEPROM.read(174); 
	char char2 = EEPROM.read(175);
	char char3 = EEPROM.read(176);
	

	char readFromEeprom[] = {char1, char2, char3,  '\0' };
	//read the name characters from eeprom to put them in a string.	
	char char4 = EEPROM.read(177);
	char char5 = EEPROM.read(178);
	char char6 = EEPROM.read(179);
	
	char readFromEeprom2[] = {char4, char5, char6, '\0'};
	//read the name characters from eeprom to put them in a string.
	char char7 = EEPROM.read(180);
	char char8 = EEPROM.read(181);
	char char9 = EEPROM.read(182);
	
	char readFromEeprom3[] = {char7, char8, char9, '\0'};
	//drawing the title, the top 3 scores and the back button.
	while(1){
		
		char title[] = "Highscore";
		
		lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		lcd.drawText(20, 75, "1", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(70, 75, readFromEeprom, OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawInteger(130, 75, EEPROM.read(171), DEC, OBJECTCOLOR, BACKGROUND, 2);
		
		lcd.drawText(20, 135, "2", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(70, 135, readFromEeprom2, OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawInteger(130, 135, EEPROM.read(172), DEC, OBJECTCOLOR, BACKGROUND, 2);
		
		lcd.drawText(20, 195, "3", OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawText(70, 195, readFromEeprom3, OBJECTCOLOR, BACKGROUND, 2);
		lcd.drawInteger(130, 195, EEPROM.read(173), DEC, OBJECTCOLOR, BACKGROUND, 2);
		
		
		if(drawButton(lcd, "Back", 20, 255, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
		
	}
}