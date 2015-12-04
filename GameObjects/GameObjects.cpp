#include "GameObjects.h"

//draws car
extern void drawCar (MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y, uint8_t rgb[2]){
	lcd.fillRect(pixelPosX(x), pixelPosY(y), 40, 64, RGB(rgb[0],rgb[1],rgb[2]));
}
//removes car
extern void removeCar(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y){
	lcd.fillRect(pixelPosX(x), pixelPosY(y), 40, 64, BACKGROUND);
}

//draws truck
extern void drawTruck(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y, uint8_t rgb[2]){
	lcd.fillRect(pixelPosX(x), pixelPosY(y - 1), 40, 64, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.fillRect(pixelPosX(x), pixelPosY(y), 40, 64, RGB(rgb[0],rgb[1],rgb[2]));
}
//removes truck
extern void removeTruck(MI0283QT9 lcd, MY_USART serial, uint8_t x, uint8_t y){
	lcd.fillRect(pixelPosX(x), pixelPosY(y - 1), 40, 64, BACKGROUND);
	lcd.fillRect(pixelPosX(x), pixelPosY(y), 40, 64, BACKGROUND);
}