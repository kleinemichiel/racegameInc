/*
 * GridLayout.cpp
 *
 * Created: 2-12-2015 13:42:06
 *  Author: Willem
 */ 
#include "GridLayout.h"


//the grid are rectangles of y= 15 and x=5
extern void showGridLayout(MI0283QT9 lcd){
	
	for(int i=0; i<GRIDYLENGTH; i++){
		for(int i2 =0; i2<GRIDXLENGTH; i2++){
			lcd.drawRect(pixelPosX(i2), pixelPosY(i), 20+200/GRIDXLENGTH, 320/GRIDYLENGTH, RGB(255,255,255));
		}
	}
}
//these are the pixel positions of the grid. The screen height is 320 pixel  and we decide the position by dividing 320 with the gridLength of Y
extern uint16_t pixelPosY(uint8_t y){
	uint16_t pixPosY =  320/GRIDYLENGTH*y;
	return pixPosY;
}

//These are the pixel positions of the grid. The screen width is 240 pixel but the road is only 200 pixels. The first 20 pixels are used by the grass, so we have to add 20 pixels every time.
extern uint16_t pixelPosX(uint8_t x){
	uint16_t pixPosX =  20+200/GRIDXLENGTH*x;
	return pixPosX;
}