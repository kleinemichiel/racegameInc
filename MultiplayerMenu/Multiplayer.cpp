/*
 * Multiplayer.cpp
 *
 * Created: 21-12-2015 14:08:27
 *  Author: Eldin
 */ 

#include "Multiplayer.h"




uint8_t timeOutCounter = 0;
uint8_t setTimeOut = 5;

extern uint8_t hostFound = 0;
extern uint8_t clientFound = 0;

uint8_t clientIsReady = 0;
uint8_t hostIsReady = 0;
uint8_t isReady = 0;





void checkForClientReady(){
	Wire.beginTransmission(ADDRESS);
	Wire.requestFrom(ADDRESS, 1);
	clientIsReady = Wire.read();
}

void sendReadyToClient(){
	Wire.beginTransmission(ADDRESS);
	Wire.write(isReady);
	Wire.endTransmission();
}

void getReadyFromHost(int numBytes){
	if(numBytes == 1){
		hostIsReady = Wire.read();
	} else {
		hostIsReady = 0;
	}
}

void sendReadyToHost(){
	Wire.write(isReady);
}

void checkForHostReady(){
	Wire.begin(ADDRESS);
	Wire.onRequest(sendReadyToHost);
	Wire.onReceive(getReadyFromHost);
}



void connected(MI0283QT9 lcd){
	lcd.fillScreen(BACKGROUND);
	
	while(1){
		char title[] = "Connected!";
		
		lcd.drawText(centerText(title, 2), 15, title, OBJECTCOLOR, BACKGROUND, 2);
		
		if(hostFound){
			lcd.drawText(20, 35, "Connected as Client", OBJECTCOLOR, BACKGROUND, 1);
		} else if(clientFound){
			lcd.drawText(20, 50, "Connected as Host", OBJECTCOLOR, BACKGROUND, 1);
		}
		
		
		lcd.drawText(15, 150, "READY UP: ", OBJECTCOLOR, BACKGROUND, 2);
		drawCheckbox(lcd, 177, (157 - 24), 48, &isReady);
	
		
		checkForHostReady();
		checkForClientReady();
		sendReadyToClient();
			
		if((isReady && hostIsReady) || (isReady && clientIsReady)){
			showGame(lcd);
		}
		
		
		
		if(drawButton(lcd, "Back", 20, 270, 200, 40)){
			clientFound = 0;
			hostFound = 0;
			lcd.fillScreen(BACKGROUND);
			returnToMain = 1;
			break;
		}
		
	}
		
	
	
}



void connectToClient(MI0283QT9 lcd){

	Wire.begin();
	Wire.beginTransmission(ADDRESS);
	Wire.write(0x01);
	Wire.endTransmission();
	
	while(!clientFound || !returnToMain){
			Wire.beginTransmission(ADDRESS);
			uint8_t availableData = Wire.requestFrom(ADDRESS, 1);
			
			
			if(availableData){
				lcd.drawText(10, 160, "found data from client", OBJECTCOLOR, BACKGROUND,1);
				uint8_t dataReceived = Wire.read();
				timeOutCounter = 0;
				hostFound = 0;
				clientFound = 1;
				break;
			} else if(timeOutCounter > setTimeOut){
				timeOutCounter = 0;
				clientFound = 0;
				break;
			} else {
				timeOutCounter++;
			}
			
			_delay_ms(15);
			
	}
	
	

}




void receiveHostEvent(int numBytes){
	hostFound = Wire.read();
}


void requestCallBack(){
	Wire.write(hostFound);
}


void connectToHost(MI0283QT9 lcd){
	
	Wire.begin(ADDRESS);
	Wire.onRequest(requestCallBack);
	Wire.onReceive(receiveHostEvent);
	
	
	while(!hostFound || !returnToMain){
		if(timeOutCounter > setTimeOut){
			timeOutCounter = 0;
			break;
		}
		timeOutCounter++;
		
		_delay_ms(10);
	}	
	
}


void showMpMenu(MI0283QT9 lcd){
	

	lcd.fillScreen(BACKGROUND);
	
	
	
	while(!returnToMain){
		
		
		
		if((hostFound || clientFound) && !returnToMain){
			connected(lcd);
		} else {
			
			char title[] = "MultiPlay";
			lcd.drawText(centerText(title, 3), 15, title, OBJECTCOLOR, BACKGROUND, 3);
			
			char title2[] = "Connecting";
			lcd.drawText(centerText(title2, 2), 45, title2, OBJECTCOLOR, BACKGROUND, 2);
			
			if(drawButton(lcd, "Back", 20, 270, 200, 40)){
				returnToMain = 1;
				break;
			}
			
			
			if(!clientFound){
				connectToHost(lcd);
				_delay_ms(10);
				connectToHost(lcd);
			} else {
				connected(lcd);
			}
			
			if(!hostFound){
				connectToClient(lcd);
			} else {
				connected(lcd);
			}
		}
		
		
	}
	
}




/*


uint8_t getClientPosition();
uint8_t getClientScore();

void sendHostScore();
void sendHostPosition();

*/
