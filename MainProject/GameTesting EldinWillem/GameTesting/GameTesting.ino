/*
 * SettingsMenuMain.ino
 *!-- this is a dummy main containing only the highly necessary libraries to get it working!!! --!
 * Created: 27-11-2015 12:31:18
 *  Author: Eldin
 */ 

#include <avr/interrupt.h>
#include <arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include "digitalWriteFast.h"
#include "GraphicsLib.h"
#include "MI0283QT9.h"
#include "USART.h"
#include "MainMenuSP.h"

#include "GameLoop.h"
#include "NunChuck.h"
//create objects
MY_USART serial;
MI0283QT9 lcd;
MENUOBJECTS obj;

//writes calibration data into eeprom
void writeCalData(void)
{
	uint16_t i, addr=0;
	uint8_t *ptr;

	EEPROM.write(addr++, 0xAA);
	
	ptr = (uint8_t*)&lcd.tp_matrix;
	for(i=0; i < sizeof(CAL_MATRIX); i++)
	{
		EEPROM.write(addr++, *ptr++);
	}

	return;
}

//reads calibration data from eeprom
uint8_t readCalData(void)
{
	uint16_t i, addr=0;
	uint8_t *ptr;
	uint8_t c;

	c = EEPROM.read(addr++);
	if(c == 0xAA)
	{
		ptr = (uint8_t*)&lcd.tp_matrix;
		for(i=0; i < sizeof(CAL_MATRIX); i++)
		{
			*ptr++ = EEPROM.read(addr++);
		}
		return 0;
	}

	return 1;
}



int main(){

	init();
	
	
	//starts lcd -> rotates it 90 degrees, portret mode -> red background
	lcd.begin();
	lcd.setOrientation(90);
	
	
	//starts serial communication
	serial.initUSART();
	serial.sendString("Succesfully initialised USART \n");
	
	//checks if touch is already calibratied, if not launch calibration app
	lcd.touchRead();
	
	if(lcd.touchZ() || readCalData()) //calibration data in EEPROM?
	{
		lcd.touchStartCal(); //calibrate touchpanel
		writeCalData(); //write data to EEPROM
	}
	
	//sets background to red
	lcd.fillScreen(BACKGROUND);
	

	
	while(1){
		showMainMenu(lcd, obj, serial);
		
		/*uint8_t color[] = {255,255,255};
		drawCar(lcd, serial, 2, 10, color);*/
	}
	
}
