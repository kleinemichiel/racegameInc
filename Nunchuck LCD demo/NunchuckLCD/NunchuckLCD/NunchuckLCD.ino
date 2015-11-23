/*
 * NunchuckLCD.ino
 *
 * Created: 11/23/2015 11:22:49 AM
 * Author: Eldin
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "digitalWriteFast.h"
#include "GraphicsLib.h"
#include "MI0283QT9.h"
#include "USART.h"
#include "NunChuck.h"



MY_USART serial;
MI0283QT9 lcd;
NUNCHUCK nun;


volatile int secondcounter = 0;

volatile int timercounter = 0;


//timer overflow 61 hz
ISR(TIMER2_OVF_vect){
	
	
	
	if(timercounter >= 7843){
		serial.sendString("SECOND COUNTER: \n");
		serial.sendInt(secondcounter);
		secondcounter++;
		timercounter = 0;
	} 
	
	timercounter++;

}


int main(){
	

	
	init();
	
		
	
	lcd.begin();
	lcd.fillScreen(RGB(255,255,255));
	
	serial.initUSART();
	serial.sendString("Succesfully initialised USART \n");
	
	
	Wire.begin();
	serial.sendString("wire begins \n");
	nun.nunchuck_init();
	serial.sendString("nun works \n");
	
	
	uint16_t oldX = 0;
	uint16_t oldY = 0;
	
	uint16_t dataPosIntegers = 280;
	
	
	
	//reset timer configuration (in case values had changed)
		TCCR2A = 0;
		TCCR2B = 0;
		
		//enable Timer2 overflow interrupt:
		TIMSK2 |= (1 << TOIE2);
		
		//set prescaler to 1024:
		TCCR2B = (0 << CS22) | (0 << CS21) | (1 << CS20);
		sei();
	
	while(1){
		
		
		lcd.drawInteger(10,10, secondcounter / 10, DEC, RGB(0,0,0), RGB(255,255,255), 1);
		
		if(nun.retreive_data()){
			
			
			lcd.fillCircle(oldX, oldY, 4, RGB(255,255,255));
			
			uint8_t x = nun.getJoyX();
			uint8_t y = nun.getJoyY();
			
			lcd.drawInteger(dataPosIntegers, 10, x, DEC, RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 20, y, DEC, RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 30, nun.getAccX(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 40, nun.getAccY(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 50, nun.getAccZ(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 50, nun.getC(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 50, nun.getZ(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			
			lcd.fillCircle(x, y, 4, RGB(255, 0, 0));
			
			oldX = x;
			oldY = y;
			
			
		}
		
		
		
		
		
	}
	
}



