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

volatile long timercounter = 0;

//timer overflowed 62745 times per second with 0 prescale
ISR(TIMER2_OVF_vect){
	
	if(timercounter >= 62745){
		secondcounter++;
		timercounter = 0;
	} 
	
	timercounter++;

}


int main(){

	init();
		
	//starts lcd
	lcd.begin();
	lcd.fillScreen(RGB(255,255,255));
	
	//starts serial communication
	serial.initUSART();
	serial.sendString("Succesfully initialised USART \n");
	
	//starts communication with nunchuck
	nun.nunchuck_init();
	
	//timer 2 without prescaler, used for timing seconds
	TCCR2A = 0;
	TCCR2B = 0;
	TIMSK2 |= (1 << TOIE2);
	TCCR2B = (0 << CS22) | (0 << CS21) | (1 << CS20);
	sei();
	
	//refreshing dot by deleting old dot
	uint16_t oldX = 0;
	uint16_t oldY = 0;
	
	uint16_t dataPosIntegers = 260;
	
	
	while(1){
		
		//second timer on screen
		lcd.drawText(0, 10, "SEC ", RGB(0,0,0), RGB(255,255,255), 1);
		lcd.drawInteger(30,10, secondcounter, DEC, RGB(0,0,0), RGB(255,255,255), 1);
		
		//gets the data from the nunchuck and parses and prints it on the lcd screen
		if(nun.retreive_data()){
			uint8_t x = nun.getJoyX();
			uint8_t y = nun.getJoyY();
			
			lcd.drawLine(dataPosIntegers - 45, 0, dataPosIntegers - 45 , 240, RGB(0,0,0));
			
			lcd.drawText(dataPosIntegers - 40, 10, "DATA", RGB(0,0,0), RGB(255,255,255), 1);
			
			lcd.drawText(dataPosIntegers - 40, 20, "JoyX:", RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 20, x, DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			lcd.drawText(dataPosIntegers - 40, 30, "JoyY:", RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 30, y, DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			lcd.drawText(dataPosIntegers - 40, 40, "AccX:", RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 40, nun.getAccX(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			lcd.drawText(dataPosIntegers - 40, 50, "AccY:", RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 50, nun.getAccY(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			lcd.drawText(dataPosIntegers - 40, 60, "AccZ:", RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 60, nun.getAccZ(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			lcd.drawText(dataPosIntegers - 40, 70, "ButC:", RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 70, nun.getC(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			lcd.drawText(dataPosIntegers - 40, 80, "ButZ:", RGB(0,0,0), RGB(255,255,255), 1);
			lcd.drawInteger(dataPosIntegers, 80, nun.getZ(), DEC, RGB(0,0,0), RGB(255,255,255), 1);
			
			if(nun.getAccMovementLR() == 1){
				lcd.drawText(dataPosIntegers - 40, 90, "LRMov:", RGB(0,0,0), RGB(255,255,255), 1);
				lcd.drawText(dataPosIntegers, 90, "Right", RGB(0,0,0), RGB(255,255,255), 1);
			} else if(nun.getAccMovementLR() == 2){
				lcd.drawText(dataPosIntegers - 40, 90, "LRMov:", RGB(0,0,0), RGB(255,255,255), 1);
				lcd.drawText(dataPosIntegers, 90, "Left", RGB(0,0,0), RGB(255,255,255), 1);
			} else {
				lcd.drawText(dataPosIntegers - 40, 90, "LRMov:", RGB(0,0,0), RGB(255,255,255), 1);
				lcd.drawText(dataPosIntegers, 90, "MID", RGB(0,0,0), RGB(255,255,255), 1);
			}
			
			//dot
			lcd.fillCircle(oldX, oldY, 4, RGB(255,255,255));
			lcd.fillCircle(x, y, 4, RGB(255, 0, 0));
			
			serial.sendInt(nun.getAccX());
			
			oldX = x;
			oldY = y;		
		}
		
		
	}
	
}



