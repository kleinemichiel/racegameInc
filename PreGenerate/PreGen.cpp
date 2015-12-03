/*
 * PreGenMain.cpp
 *
 * Created: 3-12-2015 12:36:17
 *  Author: Willem
 */ 
#include "PreGen.h"

objects object[512];
uint8_t counter =1;


extern void preGeninit(MY_USART serial){
	
	for(uint16_t i=0; i<512; i++){
		if(counter == 4){
			counter =1;
		}
		int RandomX = rand() % 5;
		int RandomType = rand() % 2+1;
		object[i].posX = RandomX;
		object[i].posY = 0;
		
		
		
		if(easy){
			object[i].posX = RandomX;
			object[i].type = 1;
		}else if(medium){
			object[i].posX = RandomX;
			object[i].type = RandomType;
		}else if(hard){
			object[i].posX = RandomX;
			if(counter == 1){
				object[i].type = 2;
			}else if(counter == 2){
				object[i].type = 1;
			}else if(counter == 3){
				object[i].type = 2;
				
			}	
			counter++;
			
		}
		
	}

}
