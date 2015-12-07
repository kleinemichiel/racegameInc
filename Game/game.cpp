// 
// 
// 

#include "game.h"


extern void showGame(MI0283QT9 lcd, MY_USART serial, NUNCHUCK nun){
	
	uint8_t x = 2;
	uint8_t color[] = {255,255,255};
		
	nun.nunchuck_init();
	//Draw game road
	lcd.fillRect(0, 0,20,320, GRASSCOLOR);
	
	lcd.fillRect(20,0,200,320, ROADCOLOR);
	
	lcd.fillRect(220,0,20,320, GRASSCOLOR);
	//drawCar(lcd, serial, 2, 4);
	
	serial.initUSART();
	serial.sendString("Succesfully initialised USART \n");
	
	
		//start game loop
		while(1){
			
			showGenObjects(lcd, serial);
			
			if(nun.retreive_data()){
			drawCar(lcd, serial, x, 16,color);
			//if tilt is right
			if(nun.getAccX() < -120){	
				removeCar(lcd, serial, x, 16);
				if(x<4){
				x++;
				}
				drawCar(lcd, serial, x, 16, color);
			} else if(nun.getAccX() > 80 && nun.getAccX() < 100){
				removeCar(lcd, serial, x, 16);
				if(x>0){
				x--;
				}
				drawCar(lcd, serial, x, 16, color);
			} else{
				
			}
			serial.sendInt(nun.getAccX());
		}
	}
	}
