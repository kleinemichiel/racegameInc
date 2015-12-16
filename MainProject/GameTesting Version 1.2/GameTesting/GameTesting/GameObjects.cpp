#include "GameObjects.h"

//draws car
extern void drawCar (MI0283QT9 lcd, uint8_t x, uint8_t y, uint8_t rgb[2]){
	lcd.drawRect(pixelPosX(x), pixelPosY(y), 40, 64, RGB(rgb[0],rgb[1],rgb[2]));
	
	
	lcd.drawLine(pixelPosX(x)+1,pixelPosY(y)+16,pixelPosX(x)+10, pixelPosY(y)+26, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x)+39,pixelPosY(y)+16,pixelPosX(x)+30, pixelPosY(y)+26, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x)+10,pixelPosY(y)+26,pixelPosX(x)+30, pixelPosY(y)+26, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x)+10,pixelPosY(y)+38,pixelPosX(x)+30, pixelPosY(y)+38, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x)+1,pixelPosY(y)+48,pixelPosX(x)+10, pixelPosY(y)+38, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x)+39,pixelPosY(y)+48,pixelPosX(x)+30, pixelPosY(y)+38, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x)+10,pixelPosY(y)+26,pixelPosX(x)+10, pixelPosY(y)+38, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x)+30,pixelPosY(y)+26,pixelPosX(x)+30, pixelPosY(y)+38, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x),pixelPosY(y)+16,pixelPosX(x)+38, pixelPosY(y)+16, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x),pixelPosY(y)+48,pixelPosX(x)+38, pixelPosY(y)+48, RGB(rgb[0],rgb[1],rgb[2]));
	
	
}
//removes car
extern void removeCar(MI0283QT9 lcd, uint8_t x, uint8_t y){
	
	lcd.drawLine(pixelPosX(x)+1,pixelPosY(y)+16,pixelPosX(x)+10, pixelPosY(y)+26, BACKGROUND);
	lcd.drawLine(pixelPosX(x)+39,pixelPosY(y)+16,pixelPosX(x)+30, pixelPosY(y)+26, BACKGROUND);
	lcd.drawLine(pixelPosX(x)+10,pixelPosY(y)+26,pixelPosX(x)+30, pixelPosY(y)+26, BACKGROUND);
	lcd.drawLine(pixelPosX(x)+10,pixelPosY(y)+38,pixelPosX(x)+30, pixelPosY(y)+38, BACKGROUND);
	lcd.drawLine(pixelPosX(x)+1,pixelPosY(y)+48,pixelPosX(x)+10, pixelPosY(y)+38, BACKGROUND);
	lcd.drawLine(pixelPosX(x)+39,pixelPosY(y)+48,pixelPosX(x)+30, pixelPosY(y)+38, BACKGROUND);
	lcd.drawLine(pixelPosX(x)+10,pixelPosY(y)+26,pixelPosX(x)+10, pixelPosY(y)+38, BACKGROUND);
	lcd.drawLine(pixelPosX(x)+30,pixelPosY(y)+26,pixelPosX(x)+30, pixelPosY(y)+38, BACKGROUND);
	lcd.drawLine(pixelPosX(x),pixelPosY(y)+16,pixelPosX(x)+40, pixelPosY(y)+16, BACKGROUND);
	lcd.drawLine(pixelPosX(x),pixelPosY(y)+48,pixelPosX(x)+40, pixelPosY(y)+48, BACKGROUND);

	lcd.drawRect(pixelPosX(x), pixelPosY(y), 40, 64, BACKGROUND);
}

//draws truck
extern void drawTruck(MI0283QT9 lcd, uint8_t x, uint8_t y, uint8_t rgb[2]){
	lcd.drawLine(pixelPosX(x),pixelPosY(y) + 50, pixelPosX(x)+39, pixelPosY(y) + 50, RGB(rgb[0],rgb[1],rgb[2]));
	
	lcd.drawLine(pixelPosX(x) + 5,pixelPosY(y) + 50, pixelPosX(x) + 5, pixelPosY(y) + 63, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x) + 35, pixelPosY(y) + 50, pixelPosX(x) + 35, pixelPosY(y) + 63, RGB(rgb[0],rgb[1],rgb[2]));
	
	lcd.drawLine(pixelPosX(x) + 10 ,pixelPosY(y) + 35, pixelPosX(x) + 30, pixelPosY(y) + 35, RGB(rgb[0],rgb[1],rgb[2]));
	
	lcd.drawLine(pixelPosX(x) + 10 ,pixelPosY(y) + 35, pixelPosX(x) + 5,pixelPosY(y) + 50, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x) + 30, pixelPosY(y) + 35,pixelPosX(x)+35, pixelPosY(y) + 50, RGB(rgb[0],rgb[1],rgb[2]));

	lcd.drawLine(pixelPosX(x) + 10 ,pixelPosY(y) + 25, pixelPosX(x) + 10, pixelPosY(y) + 35, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawLine(pixelPosX(x) + 30, pixelPosY(y) + 25, pixelPosX(x) + 30, pixelPosY(y) + 35, RGB(rgb[0],rgb[1],rgb[2]));

	lcd.drawRect(pixelPosX(x), pixelPosY(y - 3), 40, 90, RGB(rgb[0],rgb[1],rgb[2]));
	lcd.drawRect(pixelPosX(x), pixelPosY(y)+27, 40, 37, RGB(rgb[0],rgb[1],rgb[2]));
}
//removes truck
extern void removeTruck(MI0283QT9 lcd, uint8_t x, uint8_t y){
	lcd.drawLine(pixelPosX(x),pixelPosY(y) + 50, pixelPosX(x)+39, pixelPosY(y) + 50, BACKGROUND);
	
	lcd.drawLine(pixelPosX(x) + 5,pixelPosY(y) + 50, pixelPosX(x) + 5, pixelPosY(y) + 63, BACKGROUND);
	lcd.drawLine(pixelPosX(x) + 35, pixelPosY(y) + 50, pixelPosX(x) + 35, pixelPosY(y) + 63, BACKGROUND);
	
	lcd.drawLine(pixelPosX(x) + 10 ,pixelPosY(y) + 35, pixelPosX(x) + 30, pixelPosY(y) + 35, BACKGROUND);
	
	lcd.drawLine(pixelPosX(x) + 10 ,pixelPosY(y) + 35, pixelPosX(x) + 5,pixelPosY(y) + 50, BACKGROUND);
	lcd.drawLine(pixelPosX(x) + 30, pixelPosY(y) + 35,pixelPosX(x)+35, pixelPosY(y) + 50, BACKGROUND);

	lcd.drawLine(pixelPosX(x) + 10 ,pixelPosY(y) + 25, pixelPosX(x) + 10, pixelPosY(y) + 35, BACKGROUND);
	lcd.drawLine(pixelPosX(x) + 30, pixelPosY(y) + 25, pixelPosX(x) + 30, pixelPosY(y) + 35, BACKGROUND);

	lcd.drawRect(pixelPosX(x), pixelPosY(y - 3), 40, 90, BACKGROUND);
	lcd.drawRect(pixelPosX(x), pixelPosY(y)+27, 40, 37, BACKGROUND);
}