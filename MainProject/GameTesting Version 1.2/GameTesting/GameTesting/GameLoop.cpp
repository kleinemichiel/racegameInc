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
 objects preGenObjects[128];

 uint8_t posYobj1 = 0;
 uint8_t posYobj2 = 0;
 uint8_t posYobj3 = 0;

 uint8_t prevposYobj1 = 0;
 uint8_t prevposYobj2 = 0;
 uint8_t prevposYobj3 = 0;

 uint8_t prevposXobj1 = 0;
 uint8_t prevposXobj2 = 0;
 uint8_t prevposXobj3 = 0;

 uint8_t keepObj1Alive = 0;
 uint8_t keepObj2Alive = 0;
 uint8_t keepObj3Alive = 0;

 
 //generates objects, parameter: position of object in array
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
 
 

 void preGeninit(){
	 
	 uint8_t counterPre =1;
	 for(uint16_t i=0; i<128; i++){
		 if(counterPre == 4){
			 counterPre =1;
		 }
		 int RandomX = rand() % 5;
		 int RandomType = rand() % 2+1;
		 preGenObjects[i].posX = RandomX;
		 preGenObjects[i].posY = 0;
		 
			uint8_t r = rand() % 105 + 150;
			uint8_t g = rand() % 105 + 150;
			uint8_t b = rand() % 105 + 150;
			preGenObjects[i].rgb[0] = r;
			preGenObjects[i].rgb[1] = g;
			preGenObjects[i].rgb[2] = b;
		 
		 if(easy){
			 preGenObjects[i].posX = RandomX;
			 preGenObjects[i].type = 1;
		 }else if(medium){
		 	 preGenObjects[i].posX = RandomX;
			 preGenObjects[i].type = RandomType;
		 }else if(hard){
			 preGenObjects[i].posX = RandomX;
			 if(counterPre == 1){
				 preGenObjects[i].type = 2;
				 }else if(counterPre == 2){
				 preGenObjects[i].type = 1;
				 }else if(counterPre == 3){
				 preGenObjects[i].type = 2;
				 
			 }
			 counterPre++;
			 
		 }
		 
	 }
	 
	 object[0] = preGenObjects[0];
	 object[1] = preGenObjects[1];
	 object[2] = preGenObjects[2];

 }


 
 uint8_t object1PreGen = 0;
 uint8_t object2PreGen = 0;
 uint8_t object3PreGen = 0;
 
 void arrayShifter(uint8_t posOfObject){
	 
	 if((posOfObject * object1PreGen + 2) > 118){
		  preGeninit();
		  uint8_t object1PreGen = 0;
		  uint8_t object2PreGen = 0;
		  uint8_t object3PreGen = 0;
	 } else {
		  if(posOfObject == 0){
			  object1PreGen++;
			  object[posOfObject] = preGenObjects[1 * object1PreGen + 3];
		  } else if(posOfObject == 1){
			  object2PreGen++;
			  object[posOfObject] = preGenObjects[2 * object2PreGen + 2];
		  } else if(posOfObject == 2){
			  object3PreGen++;
			  object[posOfObject] = preGenObjects[3 * object3PreGen + 5];
		  }
	 }
	
 }



 uint8_t onBeginB = 0;
 uint8_t counter = 0;
 //shows the objects on screen - this loop is a example loop on how to print the objects!
 void showGenObjects(MI0283QT9 lcd){
	
	 if(!onBeginB && !preTime && realTime){
		 initGenObjects();
		 onBeginB = 1;
	 }
	 //_delay_ms(150);
	 if(hard == 1 && counter == 8){
		 counter = 0;
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
	 
	 uint8_t yCompare = GRIDYLENGTH + 7;
	 uint8_t rgbcolor[] = {255,255,255};
	 if(posYobj1 == yCompare){
		 posYobj1 = 0;
		 if(preTime){
			 
			arrayShifter(0);
		 } else {
			genNewObjects(0); 
		 }
		 
	 } else if(posYobj2 == yCompare){
		 posYobj2 = 0;
		 keepObj2Alive = 0;
		  if(preTime){
			 
			  arrayShifter(1);
		  } else {
			  genNewObjects(1);
		  }
		 
	 } else if(posYobj3 == yCompare){
		 posYobj3 = 0;
		 keepObj3Alive = 0;
		 
		  if(preTime){
			  
			  arrayShifter(2);
		
			  
	      } else {
			  genNewObjects(2);
		  }
		 
	 }
	 
	 
	 if(object[0].type == 1){
		 removeCar(lcd, prevposXobj1, prevposYobj1);
		 drawCar(lcd, object[0].posX, posYobj1, object[0].rgb);
		 //drawCar(lcd, serial, object[0].posX, posYobj1, rgbcolor);
		 object[0].posY = posYobj2;
		} else {
		 removeTruck(lcd, prevposXobj1, prevposYobj1);
		 drawTruck(lcd, object[0].posX, posYobj1, object[0].rgb);
		 object[0].posY = posYobj2;
	 }
	 
	 if(object[1].type == 1){
		 if(posYobj2 < 128){
			 removeCar(lcd, prevposXobj2, prevposYobj2);
			 drawCar(lcd, object[1].posX, posYobj2, object[1].rgb);
			 //drawCar(lcd, serial, object[1].posX, posYobj2, rgbcolor);
			 object[1].posY = posYobj2;
		 }
		 } else {
		 if(posYobj2 < 128){
			 removeTruck(lcd, prevposXobj2, prevposYobj2);
			 drawTruck(lcd, object[1].posX, posYobj2, rgbcolor);
			 object[1].posY = posYobj2;
		 }
	 }
	 
	 if(object[2].type == 1){
		 if(posYobj3 < 128){
			 removeCar(lcd, prevposXobj3, prevposYobj3);
			 drawCar(lcd, object[2].posX, posYobj3, object[2].rgb);
			// drawCar(lcd, serial, object[2].posX, posYobj3, rgbcolor);
			 object[2].posY = posYobj2;
		 }
		 } else {
		 if(posYobj3 < 128){
			 removeTruck(lcd, prevposXobj3, prevposYobj3);
			 drawTruck(lcd, object[2].posX, posYobj3, object[2].rgb);
			 object[2].posY = posYobj2;
		 }
	 }
	 
	 
	 prevposYobj1 = posYobj1;
	 prevposYobj2 = posYobj2;
	 prevposYobj3 = posYobj3;
	 prevposXobj1 = object[0].posX;
	 prevposXobj2 = object[1].posX;
	 prevposXobj3 = object[2].posX;
	 
	 
	 posYobj1++;
	 
	 if(posYobj1 > 6 || keepObj2Alive){
		 
		 posYobj2++;
		 keepObj2Alive = 1;
		 
	 }
	 
	 if(posYobj1 > 12 || keepObj3Alive){
		 
		 
		 posYobj3++;
		 keepObj3Alive = 1;
	 }
	 counter++;
 }
 
 


//main game loop 
extern void showGame(MI0283QT9 lcd){
	
	
	uint8_t x = 2;
	uint8_t movCounter = 0;
	uint8_t colored[] = {red,green,blue};
	uint16_t score = 0;
	uint16_t prevScore1 = 0;
	uint16_t prevScore2 = 0;
	uint16_t prevScore3 = 0;
	uint8_t pSensitivity = 0;
	
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
	object[2];
	objects preGenObjects[128];


	posYobj1 = 0;
	posYobj2 = 0;
	posYobj3 = 0;

	prevposYobj1 = 0;
	prevposYobj2 = 0;
	prevposYobj3 = 0;

	prevposXobj1 = 0;
	prevposXobj2 = 0;
	prevposXobj3 = 0;

	keepObj1Alive = 0;
	keepObj2Alive = 0;
	keepObj3Alive = 0;
	
	if(preTime){
		preGeninit();
	}
	
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

			prevposYobj1 = 0;
			prevposYobj2 = 0;
			prevposYobj3 = 0;

			prevposXobj1 = 0;
			prevposXobj2 = 0;
			prevposXobj3 = 0;

			keepObj1Alive = 0;
			keepObj2Alive = 0;
			keepObj3Alive = 0;
			
			
			//Draw game road
			object[2];
			objects preGenObjects[128];
			
			x = 2;
			
			movCounter = 0;
			colored[0] = red;
			colored[1] = green;
			colored[2] = blue;
			score = 0;
			prevScore1 = 0;
			prevScore2 = 0;
			prevScore3 = 0;
			pSensitivity = 0;
			
			if (sLow == 1)
			{
				pSensitivity = 5;
			} else if (sMedium == 1)
			{
				pSensitivity = 4;
				} else if (sHigh == 1){
				pSensitivity = 3;
			}
			
			showDefaultLayout(lcd);
			
			restartGame = 0;
		}
		//shows the enemy cars
		showGenObjects(lcd);
		
		//Draw player car at start location
		drawCar(lcd, x, 12,colored);
		
		//If obj1 is at you y location, check if objectx = playerx
		if((object[0].type == 1 && posYobj1 >= 12 && posYobj1<17) || (object[0].type == 2 && posYobj1>= 12 && posYobj1<23)){
			if (object[0].posX == x ) {
				showGameOverMenu(lcd, score);
				}else{
				if (object[0].type == 1){
					if (prevScore1 == 0)
					{
						score++;
						prevScore1++;
					}
					}else if(object[0].type == 2){
					if (prevScore1 == 0)
					{
						score = score + 2;
						prevScore1++;
					}
				}
			}
		}
		
		//If obj2 is at player y location, check if objectx = playerx
		if((object[1].type == 1 && posYobj2 >= 12 && posYobj2<17) || (object[1].type == 2 && posYobj2>= 12 && posYobj2<22)){
			if (object[1].posX == x) {
				showGameOverMenu(lcd,score);
				}else{
				if (object[0].type == 1){
					if (prevScore2 == 0)
					{
						score++;
						prevScore2++;
					}
					}else if(object[0].type == 2){
					if (prevScore2 == 0)
					{
						score = score + 2;
						prevScore2++;
					}
				}
			}
		}
		
		//If obj3 is at player y location, check if objectx = playerx
		if((object[2].type == 1 && posYobj3 >= 12 && posYobj3<17) || (object[2].type == 2 && posYobj3>= 12 && posYobj3<22)){
			if (object[2].posX == x) {
				showGameOverMenu(lcd,score);
				}else{
				if (object[0].type == 1){
					if (prevScore3 == 0)
					{
						score++;
						prevScore3++;
					}
					}else if(object[0].type == 2){
					if (prevScore3 == 0)
					{
						score = score + 2;
						prevScore3++;
					}
				}
			}
		}
		
		if (posYobj1 == 1)
		{
			prevScore1 = 0;
		}else if (posYobj2 == 1)
		{
			prevScore2 = 0;
		}else if (posYobj3 == 1)
		{
			prevScore3 = 0;
		}
		
		//draws car at x depending on tilt, and y = 12 (front of car), y = 15 end of car
		if(nun.retreive_data()){
			if (nun.getC() ==1) {
				showPauseMenu(lcd);
			}
			//if nunchuck is tilted right, increment x
			if(nun.getAccX() > 148){
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
			else if(nun.getAccX() > 70 && nun.getAccX() < 108){
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
