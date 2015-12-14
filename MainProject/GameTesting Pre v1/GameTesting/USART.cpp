/*
 * USART.cpp
 *
 * Created: 28-9-2015 19:08:53
 *  Author: Eldin
 */ 

/*
  Quick and dirty functions that make serial communications work.

  Note that receiveByte() blocks -- it sits and waits _forever_ for
   a byte to come in.  If you're doing anything that's more interesting,
   you'll want to implement this with interrupts.

   initUSART requires BAUDRATE to be defined in order to calculate
     the bit-rate multiplier.  9600 is a reasonable default.
*/

#include <avr/io.h>
#include "USART.h"

void MY_USART::initUSART(void) {                                /* requires BAUD */
  UBRR0H = UBRRH_VALUE;                        /* defined in setbaud.h */
  UBRR0L = UBRRL_VALUE;
#if USE_2X
  UCSR0A |= (1 << U2X0);
#else
  UCSR0A &= ~(1 << U2X0);
#endif
                                  /* Enable USART transmitter/receiver */
  UCSR0B = (1 << TXEN0) | (1 << RXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   /* 8 data bits, 1 stop bit */
}


void MY_USART::transmitByte(uint8_t data) {
                                     /* Wait for empty transmit buffer */
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = data;                                            /* send data */
}

uint8_t MY_USART::receiveByte(void) {
  loop_until_bit_is_set(UCSR0A, RXC0);       /* Wait for incoming data */
  return UDR0;                                /* return register value */
}

void MY_USART::sendString(char string[]){
	int index = 0;
	while(1){
		if(string[index] > 0){
			loop_until_bit_is_set(UCSR0A, UDRE0);
			UDR0 = string[index];
		} else {
			break;
		}
		index++;
	}
}

void MY_USART::sendInt(uint16_t input){
	
		sendString("INT: ");
		uint8_t pos = 4;
		
		
		
		
		float calculator = (float)input / 1000;
		uint8_t residingDec = 0;
	

		for (uint8_t i = 0; i != pos; i++) {
			
			residingDec = calculator;
			char integer = residingDec +'0';
			transmitByte(integer);
			calculator = calculator - residingDec;
			//apparantly 0.3x10 has as result 2.999997, so adding 0.01 makes sure that it comes above that, using 8 bit int restricts numbers above 255 so it wont affect the result
			calculator = calculator * 10 + 0.0001;
		}
		
		sendString("\n");
}