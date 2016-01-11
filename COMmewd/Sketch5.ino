/*
 Name:		Sketch5.ino
 Created:	1/4/2016 12:03:34 PM
 Author:	michiel
*/

// the setup function runs once when you press reset or power the board

#include "com.h"

#define PIND7

int main() {
	initCom();
	uint8_t player = 3;
	while (1) {
		//sendPlayerX(player);
		if (retrievePlayerX() == 3) {
			PIND7  1;
		}

	}


}