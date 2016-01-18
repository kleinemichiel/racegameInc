/*
 * GameOverMenu.cpp
 *
 * Created: 7-12-2015 12:31:14
 *  Author: Eldin
 */ 

#include "GameOverMenu.h"


/*Menu for the Multiplayer mode. If you are the winner you wil get the you won screen and else you will get the you lost screen.
Beside of that you can see your score and the restart button will direct you to the multiplayer menu.
 */

void showGameOverMenuMP(MI0283QT9 lcd, uint16_t score, uint8_t won){
	lcd.fillScreen(BACKGROUND);
	exitMultiplayer();
	while(1){
		if(won){
			char title[] = "You Won!";
			
			lcd.drawText(centerText(title,3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			
			lcd.drawText(centerText("Your Score:", 2), 60, "Your Score:", OBJECTCOLOR, BACKGROUND, 2);
			
			lcd.drawInteger(70, 100, score, DEC, OBJECTCOLOR, BACKGROUND, 3);
			
			
			if(drawButton(lcd, "Restart", 20, 220, 200, 40))
			{
				showMpMenu(lcd);
			}
			
			//return to main menu. You will first break to the game loop. In the game loop is an if statement. If return to main = 1 then you will break to the main menu.
			if(drawButton(lcd, "Main Menu", 20, 270, 200, 40))
			{
				lcd.fillScreen(BACKGROUND);
				returnToMain = 1;
				break;
			}
			
		}else if(!won){
			char title[] = "You Lost!";
			
			lcd.drawText(centerText(title,3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			
			lcd.drawText(centerText("Your Score:", 2), 60, "Your Score:", OBJECTCOLOR, BACKGROUND, 2);
			
			lcd.drawInteger(70, 100, score, DEC, OBJECTCOLOR, BACKGROUND, 3);
			
			
			if(drawButton(lcd, "Restart", 20, 220, 200, 40))
			{
				showMpMenu(lcd);
			}
			
			//return to main menu. You will first break to the game loop. In the game loop is an if statement. If return to main = 1 then you will break to the main menu.
			if(drawButton(lcd, "Main Menu", 20, 270, 200, 40))
			{
				lcd.fillScreen(BACKGROUND);
				returnToMain = 1;
				break;
			}
		}
	}
}

/*You will get this menu if you don't get a highscore, you will also get this screen if you press accept in the highscore menu.
In this menu you will only see your score if you didn't got a highscore, you also see the 3rd best score ever made.
*/


void showNoHighScore(MI0283QT9 lcd, uint16_t score,  uint8_t isHighscore){
	while(1){
		
		char title[] = "You DIED!";
		
		lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
		if(!isHighscore){
			
			
			
			lcd.drawText(centerText("Your Score:", 2), 50, "Your Score:", OBJECTCOLOR, BACKGROUND, 2);
			if(hard){
				lcd.drawText(centerText("Hard Bonus Score ( x 2)!", 1), 75, "Hard Bonus Score ( x 2)!", OBJECTCOLOR, BACKGROUND, 1);
			}
			
			lcd.drawInteger(70, 100, score, DEC, OBJECTCOLOR, BACKGROUND, 3);
			
			
			lcd.drawText(centerText("Your Need:", 2), 140, "You Need:", OBJECTCOLOR, BACKGROUND, 2);
			//read in the eeprom the score of the 3rd best score and draw it on the screen.
			lcd.drawInteger(70, 170, EEPROM.read(173), DEC, OBJECTCOLOR, BACKGROUND, 3);
		} 
		
		
		
		//restart game. You will first break to the game loop. In the game loop is an if statement. If restart game = 1 then all values of variables will be set to 0. 
		if(drawButton(lcd, "Restart", 20, 220, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			restartGame = 1;
			break;
		}
		
		//return to main menu. You will first break to the game loop. In the game loop is an if statement. If return to main = 1 then you will break to the main menu.
		if(drawButton(lcd, "Main Menu", 20, 270, 200, 40))
		{
			lcd.fillScreen(BACKGROUND);
			returnToMain = 1;
			break;
		}
	}
	
}
	
/*You will see this screen if you made it in the top 3*/	
void showGameOverMenu(MI0283QT9 lcd, uint16_t score){
	char char1 = 'A';
	char char2 = 'A';
	char char3 = 'A';
	
	int EEPROMfilled = 0;
	
	//checks if address 174 is not 0. If you already played the game once it is set to A, so you won't write unnecessary values to eeprom.
	if(EEPROM.read(174) != 0 ){
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
	
	if(hard){
		score = score * 2;
	}
	
	
	while(1){
		
		//we had to check in this menu on restart game and return to main, because if you got an highscore and press accept you will be directed to shownohighscore menu. If you press back to menu or restart game you will be directed to this menu. Now you break again and reach the gameloop.
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
			showNoHighScore(lcd, score, 0);
		}else if(EEPROM.read(173) < score) {
			
			char title[] = "You DIED!";
			
			lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			lcd.drawText(centerText("Highscore!!!", 2), 40, "Highscore!!!", OBJECTCOLOR, BACKGROUND, 2);
			if(hard){
				lcd.drawText(centerText("Hard Bonus Score ( x 2)!", 1), 65, "Hard Bonus Score ( x 2)!", OBJECTCOLOR, BACKGROUND, 1);
			}
			
			
			lcd.drawInteger(70, 80, score, DEC, OBJECTCOLOR, BACKGROUND, 3);
			
			//you can fill in 3 characters, which will  be your name in the highscore menu.
			char name[] = "Your Name?";
			lcd.drawText(centerText(name, 2), 140, name, OBJECTCOLOR, BACKGROUND, 2);
			
			char1 =	drawCharSelector(lcd, 35, 160, char1);
			char2 =	drawCharSelector(lcd, 95, 160, char2);
			char3 =	drawCharSelector(lcd, 155, 160, char3);
			
			//if you press accept you will write your score to the eeprom ad then you will be directed to the show No highscore menu.
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
				showNoHighScore(lcd, score, 1);
			}

			}
		}
		
	
}