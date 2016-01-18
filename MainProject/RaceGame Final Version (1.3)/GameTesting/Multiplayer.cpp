/*
 * Multiplayer.cpp
 *
 * Created: 21-8-2015 14:08:27
 *  Author: Eldin
 */ 

#include "Multiplayer.h"

//global value
uint8_t isConnected = 0;

//local values
uint8_t confirmConnection = 0;
uint16_t timeOut = 60000;
uint8_t trys = 0;

//WIP - automaticly figures out if it should act as a master or slave without the need for the user to define it
void autoConnect(MI0283QT9 lcd){
	while(1){
		trys++;
		char title[] = "Connecting";
		
		lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
		
		if((trys % (rand() % 3 + 1)) == 0){
			lcd.drawText(15, 60, "SLAVE ", OBJECTCOLOR, BACKGROUND, 1);
			setSlave();
		} else {
			lcd.drawText(15, 60, "MASTER", OBJECTCOLOR, BACKGROUND, 1);
			setMaster();
		}
		
		
		uint16_t timeOutCounter = 0;
		
		
		sendByte(36);
		while(timeOutCounter < timeOut){
			uint8_t confirmByte = getByte();
			sendByte(36);
			if(confirmByte == 36){
				confirmConnection = 1;
				
				break;
			} else {
				timeOutCounter++;
			}
		}
		
		if(confirmConnection){
			break;
		}
		
		
	}
}


//starts the communication between arduinos and lets users ready up
void startConnecting(MI0283QT9 lcd, uint8_t player){
	uint8_t readyUP = 0;
	
	lcd.fillScreen(BACKGROUND);
	initMSSP(PINC3, PINC0, PINC1, 4);
	
	if(player == 1){
		setMaster();
		//sendByte(66);
	} else if(player == 2){
		setSlave();
		//sendByte(66);
	} else {
		autoConnect(lcd);
	}
	
	//autoConnect(lcd);
	while(!returnToMain){
		
			if(returnToMain){
				break;
			}
			
			uint8_t received = getByte();
			
			char title[] = "Connected!";
			
			lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			lcd.drawText(centerText("READY UP:", 2), 65, "READY UP:", OBJECTCOLOR, BACKGROUND, 2);
			
			lcd.drawInteger(20, 85, received, DEC, OBJECTCOLOR, BACKGROUND, 2);
			
			while(readyUP){
				sendByte(66);
				received = getByte();
				lcd.drawInteger(20, 85, received, DEC, OBJECTCOLOR, BACKGROUND, 2);
				
				if(received == 66){
					isConnected = 1;
					if(isMaster){
						_delay_ms(100);
					}
					showGame(lcd);
					break;
				}
				if(!readyUP){
					if(drawButton(lcd, "Not Ready", 20, 140, 200, 40)){
						readyUP = 1;
					}
					} else {
					if(drawButton(lcd, "  Ready  ", 20, 140, 200, 40)){
						readyUP  = 0;
					}
				}
				
				if(drawButton(lcd, "Back", 20, 255, 200, 40)){
					lcd.fillScreen(BACKGROUND);
					returnToMain = 1;
					break;
				}
			}
			
			if(!readyUP){
				if(drawButton(lcd, "Not Ready", 20, 140, 200, 40)){
					readyUP = 1;
				}
				} else {
				if(drawButton(lcd, "  Ready  ", 20, 140, 200, 40)){
					readyUP  = 0;
				}
			}
		
		
		if(drawButton(lcd, "Back", 20, 255, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			break;
		}
		
		
	}
	
}

//Slave/Master select menu, or autoconnect function
void showMpMenu(MI0283QT9 lcd){
	lcd.fillScreen(BACKGROUND);
	
	while(!returnToMain){
		
		if(returnToMain){
			break;
		}
		
		char title[] = "Master/Slave";
		
		lcd.drawText(centerText(title, 2), 15, title, OBJECTCOLOR, BACKGROUND, 2);
		
		if(drawButton(lcd, "Master", 20, 55, 200, 40)){
			startConnecting(lcd, 1);
		} else if(drawButton(lcd, "Slave", 20, 105, 200, 40)){
			startConnecting(lcd, 2);
		} else if(drawButton(lcd, "AUTO (WIP)", 20, 155, 200, 40)){
			startConnecting(lcd, 0);
		} 
		
		
		if(drawButton(lcd, "Back", 20, 255, 200, 40)){
			lcd.fillScreen(BACKGROUND);
			returnToMain = 1;
			break;
		}
	}
	lcd.fillScreen(BACKGROUND);
}

//gets the position from the other player
uint8_t getClientPosition(){
	
	if(isConnected){
		return (((getByte() / 2) - 10) / 2);
	} else {
		return 196;
	}
	
}

//sends x position from this player to the other player
void sendHostPosition(uint8_t x){
	if(isConnected){
		sendByte(((x * 2) + 10) * 2);
	}
}

//send game over from this player to the other player
void sendGameOver(){
	if(isConnected){
		sendByte(88);
	}
}

//gets game over from other player
uint8_t getGameOver(){
	if(isConnected){
		if(getByte() == 88){
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

//ends communication between arduino's
void exitMultiplayer(){
	if(isConnected){
		stopMSSP();
	}
}
/*



uint8_t getClientScore();

void sendHostScore();


*/
