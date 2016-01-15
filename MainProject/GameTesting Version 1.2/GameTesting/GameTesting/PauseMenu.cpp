/*
 * PauseMenu.cpp
 *
 * Created: 30-11-2015 14:58:04
 *  Author: michiel
 */ 

#include "PauseMenu.h"


extern void showPauseMenu(MI0283QT9 lcd){
	lcd.fillScreen(BACKGROUND);// fills background so game is not visible anymore
	
	while(1){

		lcd.drawText(centerText("Pause", 3), 15, "Pause", OBJECTCOLOR, BACKGROUND, 3);
		if(drawButton(lcd, "Resume Game", 20, 75, 200, 40)){	
			showDefaultLayout(lcd); // shows the game backround before the game starts again
			break; // breaks back into the game loop
		}
		if(drawButton(lcd, "Restart Game", 20, 135, 200, 40)){
			restartGame = 1; // sets a global value so the game will restart once back in the game loop
			break; // breaks back into the game loop
		}	
		
		if(drawButton(lcd, "Main Menu", 20, 255, 200, 40)){
			returnToMain = 1;  // sets a global value so you will go back to main menu once you are back into the game loop
			break; // breaks back into the game loop
		}
		
	}
}
