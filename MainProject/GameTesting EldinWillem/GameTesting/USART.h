/* Functions to initialize, send, receive over USART

initUSART requires BAUD to be defined in order to calculate
the bit-rate multiplier.
*/



#ifndef USART_H
#define USART_H

#define F_CPU 16000000UL

#ifndef BAUD                          /* if not defined in Makefile... */
#define BAUD  115200                    /* set a safe default baud rate */
#endif
#include <util/setbaud.h>
#include <stdint.h>

class MY_USART
{
	public:
	/* Takes the defined BAUD and F_CPU,
	calculates the bit-clock multiplier,
	and configures the hardware USART                   */
	void initUSART(void);

	/* Blocking transmit and receive functions.
	When you call receiveByte() your program will hang until
	data comes through.  We'll improve on this later. */
	void transmitByte(uint8_t data);
	uint8_t receiveByte(void);
	void sendString(char string[]);
	void sendInt(uint16_t input);

};

#endif