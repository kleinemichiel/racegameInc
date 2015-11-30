/*
 * MainMenu.ino
 *
 * Created: 27-Nov-15 3:48:14 PM
 * Author: Willem
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include "digitalWriteFast.h"
#include "GraphicsLib.h"
#include "MI0283QT9.h"
#include "USART.h"
#include "menuObjects.h"
#include "MainMenuSP.h"
#include "SettingsMenu.h"


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
	
	//sets background to black
	lcd.fillScreen(BACKGROUND);
	
	while(1){
		
		showMainMenu(lcd, obj, serial);
	}
	
}