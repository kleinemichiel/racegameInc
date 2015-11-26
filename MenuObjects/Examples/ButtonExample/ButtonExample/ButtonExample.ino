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
	lcd.fillScreen(RGB(255,0,0));
	while(1){
		
		//creates test buttons
		//drawButton(lcd, string, x, y, width, height)
		uint8_t test = obj.drawButton(lcd, "test", 15, 15, 150, 40);
		uint8_t itworks = obj.drawButton(lcd, "it works :D", 15, 90, 200, 40);
		uint8_t centering = obj.drawButton(lcd, "centering TM", 15, 150, 200, 40);
		uint8_t touching = obj.drawButton(lcd, "a", 15, 220, 200, 40);
		
		//testing if buttons work by printing them
		if(test){
			serial.sendString("test button pressed \n");
		} else if(itworks){
			serial.sendString("it works :D button pressed \n");
		} else if(centering){
			serial.sendString("centering TM button pressed \n");
		} else if(touching){
			serial.sendString("touchingstory button pressed \n");
		}
	}
	
}
