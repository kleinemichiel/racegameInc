// 
// 
// 

#include "GameLoop.h"

 NUNCHUCK nun;
 //objects
 //-posX
 //-posY
 //type (1 = car, 2 = truck) same goes for points

objects object[2];
/*objects preGenObjects[128];*/
 // generates objects, parameter: position of object in array
 void genNewObjects(uint8_t objectReGen)
 {
	 uint8_t rPosX = rand() % 5;
	 
	 uint8_t r = rand() % 105 + 150;
	 uint8_t g = rand() % 105 + 150;
	 uint8_t b = rand() % 105 + 150;
	 
	 
	 object[objectReGen].posX = rPosX;
	 object[objectReGen].posY = 0;
	 object[objectReGen].rgb[0] = r;
	 object[objectReGen].rgb[1] = g;
	 object[objectReGen].rgb[2] = b;
	 

	 if(easy){
		 object[objectReGen].type = 1;
		 } else if (medium){
		 uint8_t rObjType = rand() % 2 + 1;
		 object[objectReGen].type = rObjType;
		 } else if (hard){
		 if(objectReGen == 0){
			 object[objectReGen].type = 2;
			 } else if(objectReGen == 1){
			 object[objectReGen].type = 1;
			 } else if (objectReGen == 2){
			 object[objectReGen].type = 2;
		 }
	 }
	 
 }

 //generates objects for first "wave"
 void initGenObjects(){
	 for(uint8_t i = 0; i < 3; i++){
		 genNewObjects(i);
	 }
 }


 uint8_t posYobj1 = 0;
 uint8_t posYobj2 = 0;
 uint8_t posYobj3 = 0;

 uint8_t prevposXobj1 = 0;
 uint8_t prevposXobj2 = 0;
 uint8_t prevposXobj3 = 0;

 uint8_t keepObj2Alive = 0;
 uint8_t keepObj3Alive = 0;
 
 uint8_t onBeginB = 0;
 //shows the objects on screen - this loop is a example loop on how to print the objects!
 void showGenObjects(MI0283QT9 lcd){
	
	 if(!onBeginB){
		 initGenObjects();
		 onBeginB = 1;
	 }
	 //_delay_ms(150);
	 if(hard == 1 && (posYobj1 % 12) == 0){
		 uint8_t operatordefine;
		 
		 if(object[0].posX == 4){
			 object[0].posX--;
			 }else if(object[0].posX == 0){
			 object[0].posX++;
			 }else if(object[0].posX != 0 && object[0].posX != 4){
			 operatordefine = rand() % 2 + 1;
			 if(operatordefine == 1){
				 object[0].posX++;
				 }else{
				 object[0].posX--;
			 }
			 
		 }
		 
		 if(object[1].posX == 4){
			 object[1].posX--;
			 }else if(object[1].posX == 0){
			 object[1].posX++;
			 }else if(object[1].posX != 0 && object[1].posX != 4){
			 operatordefine = rand() % 2 + 1;
			 if(operatordefine == 1){
				 object[1].posX++;
				 }else{
				 object[1].posX--;
			 }
		 }
		 
		 
		 if(object[2].posX == 4){
			 object[2].posX--;
			 }else if(object[2].posX == 0){
			 object[2].posX++;
			 }else if(object[2].posX != 0 && object[1].posX != 4){
			 operatordefine = rand() % 2 + 1;
			 if(operatordefine == 1){
				 object[2].posX++;
				 }else{
				 object[2].posX--;
			 }
		 }
		 
	 }
	 
	 uint8_t yCompare = GRIDYLENGTH + 9;
	 uint8_t rgbcolor[] = {255,255,255};
	 if(posYobj1 == yCompare){
		 posYobj1 = 0;
		 removeTruck(lcd, prevposXobj1, object[0].posY);
		 genNewObjects(0);
		 
	 } else if(posYobj2 == yCompare){
		 posYobj2 = 0;
		 keepObj2Alive = 0;
		 removeTruck(lcd, prevposXobj2, object[1].posY);
		 genNewObjects(1);
		 
	 } else if(posYobj3 == yCompare){
		 posYobj3 = 0;
		 keepObj3Alive = 0;
		 removeTruck(lcd, prevposXobj3, object[2].posY);
		 genNewObjects(2);
		 
	 }
	 
	 
	 if(object[0].type == 1){
		 removeCar(lcd, prevposXobj1, object[0].posY);
		 drawCar(lcd, object[0].posX, posYobj1, object[0].rgb);
		 object[0].posY = posYobj1;
	 } else {
		 removeTruck(lcd, prevposXobj1, object[0].posY);
		 drawTruck(lcd, object[0].posX, posYobj1, object[0].rgb);
		 object[0].posY = posYobj1;
	 }
	
	 posYobj1++;
	 
	 if(posYobj1 > 6 || keepObj2Alive){
		 
		 posYobj2++;
		 keepObj2Alive = 1;
		 
		  
		  if(object[1].type == 1){
			  if(posYobj2 < 128){
				  removeCar(lcd, prevposXobj2, object[1].posY);
				  drawCar(lcd, object[1].posX, posYobj2, object[1].rgb);
				  object[1].posY = posYobj2;
			  }
			  } else {
			  if(posYobj2 < 128){
				  removeTruck(lcd, prevposXobj2, object[1].posY);
				  drawTruck(lcd, object[1].posX, posYobj2, rgbcolor);
				  object[1].posY = posYobj2;
			  }
		  }
	 }
	 
	 if(posYobj1 > 12 || keepObj3Alive){
		 
		 posYobj3++;
		 keepObj3Alive = 1;
		 
		 if(object[2].type == 1){
			 if(posYobj3 < 128){
				 removeCar(lcd, prevposXobj3, object[2].posY);
				 drawCar(lcd, object[2].posX, posYobj3, object[2].rgb);
				 object[2].posY = posYobj3;
			 }
			 } else {
			 if(posYobj3 < 128){
				 removeTruck(lcd, prevposXobj3, object[2].posY);
				 drawTruck(lcd, object[2].posX, posYobj3, object[2].rgb);
				 object[2].posY = posYobj3;
			 }
		 }
		 
		 
	 }
	 
	 
	 
	 prevposXobj1 = object[0].posX;
	 prevposXobj2 = object[1].posX;
	 prevposXobj3 = object[2].posX;
	 
 }
 
//main game loop 
extern void showGame(MI0283QT9 lcd){
	//setup seed
	
	uint16_t seed = (rand() % 65534) + 1;
	srand(seed);
	
	//setup car
	uint8_t x = 2;
	uint8_t movCounter = 0;
	uint8_t colored[] = {red,green,blue};
	uint16_t score = 0;
	uint8_t pSensitivity = 0;
	
	object[2];
	//objects preGenObjects[128];

	
	if (sLow == 1)
	{
		pSensitivity = 5;
	} else if (sMedium == 1)
	{
		pSensitivity = 4;
	} else if (sHigh == 1){
		pSensitivity = 3;
	}
	
	//Draw game road
	showDefaultLayout(lcd);
	
	nun.nunchuck_init();

	posYobj1 = 0;
	posYobj2 = 0;
	posYobj3 = 0;

	prevposXobj1 = 0;
	prevposXobj2 = 0;
	prevposXobj3 = 0;

	keepObj2Alive = 0;
	keepObj3Alive = 0;
	
	uint8_t carHitMax = 15;
	uint8_t truckHitmax = 18;
	
	
	uint8_t countDown = 3;
	
	//start game loop
	while(1){
		
		
		
		if(returnToMain){
			returnToMain = 0;
			lcd.fillScreen(BACKGROUND);
			break;
		}
		
		if(restartGame){
			posYobj1 = 0;
			posYobj2 = 0;
			posYobj3 = 0;

			prevposXobj1 = 0;
			prevposXobj2 = 0;
			prevposXobj3 = 0;

			keepObj2Alive = 0;
			keepObj3Alive = 0;
			
			
			//Draw game road
			objects object[2];
			objects preGenObjects[128];
			
			x = 2;
			
			movCounter = 0;
			colored[0] = red;
			colored[1] = green;
			colored[2] = blue;
			score = 0;
			
			pSensitivity = 0;
			
			if (sLow == 1)
			{
				pSensitivity = 5;
			} 
			else if (sMedium == 1)
			{
				pSensitivity = 4;
			}
			else if (sHigh == 1)
			{
				pSensitivity = 3;
			}
			
			showDefaultLayout(lcd);
			
			onBeginB = 0;
			restartGame = 0;
			countDown = 3;
		}
		
		//countdown before game start
		while(countDown != 0){
			lcd.drawInteger(centerText(" ", 3), 150, countDown, DEC, OBJECTCOLOR, BACKGROUND, 3);
			_delay_ms(1000);
			lcd.drawInteger(centerText(" ", 3), 150, countDown, DEC, BACKGROUND, BACKGROUND, 3);
			if(countDown == 1){
				lcd.drawText(centerText("START" , 3), 150, "START", OBJECTCOLOR, BACKGROUND, 3);
				_delay_ms(1000);
				lcd.drawText(centerText("START" , 3), 150, "START", BACKGROUND, BACKGROUND, 3);
			}
			countDown--;
		}
		//shows the enemy cars
		showGenObjects(lcd);
		
		//Draw player car at start location
		drawCar(lcd, x, 12,colored);
		
		
		
		
		//If obj1 is at you y location, check if objectx = playerx
		if((object[0].type == 1 && object[0].posY >= 12  && object[0].posY <= carHitMax ) || (object[0].type == 2 && object[0].posY >= 12 && object[0].posY <= truckHitmax)){
			if (object[0].posX == x ) {
				showGameOverMenu(lcd, score);
			}else{
				
				if(object[0].posY == carHitMax  || object[0].posY == truckHitmax){
					score = object[0].type + score;
				}
				
				
			}
		}else if((object[1].type == 1 && object[1].posY >= 12 && object[1].posY <= carHitMax ) || (object[1].type == 2 && object[1].posY >= 12 && object[1].posY <= truckHitmax)){
			//If obj2 is at player y location, check if objectx = playerx
			if (object[1].posX == x) {				
				showGameOverMenu(lcd,score);
			}else{
				
				if(object[1].posY == carHitMax  || object[1].posY == truckHitmax){
					score = object[1].type + score;
				}
			}
		} else if((object[2].type == 1 && object[2].posY >= 12 && object[2].posY <= carHitMax ) || (object[2].type == 2 && object[2].posY >= 12 && object[2].posY <= truckHitmax)){
			
			//If obj3 is at player y location, check if objectx = playerx
			if (object[2].posX == x) {
				showGameOverMenu(lcd,score);
			}else{
				
				if(object[2].posY == carHitMax || object[2].posY == truckHitmax){
					score = object[2].type + score;
				}
			}
		}
		
		
		
		//draws car at x depending on tilt, and y = 12 (front of car), y = 15 end of car
		if(nun.retreive_data()){
			
			
			if (nun.getC() ==1) {
				showPauseMenu(lcd);
			}
			
			
			//if nunchuck is tilted right, increment x
			if(nun.getAccX() > 148 || nun.getJoyX() > 150){
				if(movCounter == 0){
					removeCar(lcd, x, 12);
					if(x<4){
						x++;
					}
					movCounter++;
					}else{
					movCounter++;
					if(movCounter>=pSensitivity){
						movCounter = 0;
					}
				}
				drawCar(lcd, x, 12, colored);
			}
			//draw car at x location
			//if nunchuck is tilted left, substract 1 from x
			else if((nun.getAccX() > 70 && nun.getAccX() < 108) || nun.getJoyX() < 90){
				if(movCounter==0){
					removeCar(lcd, x, 12);
					if(x>0){
						x--;
					}
					movCounter++;
					}else{
					movCounter++;
					if(movCounter>=pSensitivity){
						movCounter = 0;
					}
				}
				//draw car at x location
				drawCar(lcd, x, 12, colored);
				//if nunchuck is in middle, movCounter = 0
			}else if(nun.getAccX() > 120 && nun.getAccX() < 136){
				movCounter = 0;
			}
			
			lcd.drawInteger(22, 2, score, DEC, GRASSCOLOR, BACKGROUND, 1);
			
		}
	}
}
