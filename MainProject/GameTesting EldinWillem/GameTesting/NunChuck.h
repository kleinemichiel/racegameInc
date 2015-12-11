/*
 * NunChuck.h
 *
 * Created: 21-11-2015 11:19:30
 *  Author: Eldin
 * Make sure Arduino.h & Wire.h is included in your main program and you ran the init() method before initialising the nunchuck!!!
 */ 

#define NUNADDRESS 0x52
#define DATARQ 0x00

#ifndef NUNCHUCK_H_
#define NUNCHUCK_H_


#include <stdint.h>
#include <Wire.h>

class NUNCHUCK
{
	public:
	//communication with nunchuck
	uint8_t nunchuck_init(void);
	uint8_t request_data(void);
	uint8_t retreive_data(void);
	
	//storing data
	static char nunDataArr[6];	
	
	//parsing data
	uint8_t getJoyX(void);
	uint8_t getJoyY(void);
	uint8_t getAccX(void);
	uint8_t getAccY(void);
	uint8_t getAccZ(void);
	uint8_t getC(void);
	uint8_t getZ(void);
	
	
	private:
	//internal data decoder, no use for outside use
	uint16_t decode_data(uint16_t data);
		
};




#endif /* NUNCHUCK_H_ */