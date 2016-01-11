
#include <avr/io.h>
#include "com.h"
#include "SoftwareSerial\SoftwareSerial.h"



SoftwareSerial serial(0, 1, false);


extern void initCom(void) {
	serial.begin(115200);
}

extern void sendPlayerX(uint8_t X) {
	serial.write(X);
}

extern uint8_t retrievePlayerX(void)//will retrieve information of the other player his player possiton
{
	return  serial.read();
}
