// 
// 
// 

#include "GameObjects.h"

extern void drawCar (MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y){
	
	lcd.fillRect(pixelPosX(x), pixelPosY(y), 40, 64, RGB(255,255,255));
}

extern void drawTruck(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y){
	lcd.fillRect(pixelPosX(x), pixelPosY(y), 40, 64, RGB(255,255,255));
	lcd.fillRect(pixelPosX(x), pixelPosY(y-1), 40, 64, RGB(255,255,255));
}