/*
 * GridLayout.cpp
 *
 * Created: 2-12-2015 13:42:06
 *  Author: Willem
 */ 
#include "GridLayout.h"

extern void showGridLayout(MI0283QT9 lcd, MY_USART serial){
	
	for(int i=0; i<5; i++){
		for(int i2 =0; i2<5; i2++){
			lcd.drawRect(pixelPosX(i2), pixelPosY(i), 20+200/GRIDXLENGTH, 320/GRIDYLENGTH, RGB(255,255,255));
		}
	}
}

extern uint16_t pixelPosY(uint8_t y){
	uint16_t pixPosY =  320/GRIDYLENGTH*y;
	return pixPosY;
}

extern uint16_t pixelPosX(uint8_t x){
	uint16_t pixPosX =  20+200/GRIDXLENGTH*x;
	return pixPosX;
}