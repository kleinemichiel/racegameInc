/*
 * NunChuck.cpp
 *
 * Created: 21-11-2015 11:10:22
 *  Author: Eldin
 * Make sure Arduino.h & Wire.h is included in your main program and you ran the init() method before initialising the nunchuck!!!
 */ 




#include <stdint.h>
#include <Wire.h>
#include "NunChuck.h"

//data container
char NUNCHUCK::nunDataArr[5];

//starts handshake with nunchuck
uint8_t NUNCHUCK::nunchuck_init(){
	Wire.begin();
	Wire.beginTransmission(NUNADDRESS);
	Wire.write(0x40);
	Wire.write(DATARQ);
	Wire.flush();
	if(Wire.endTransmission() == 0){
		return 1;
	} else {
		return 0;
	}
	
}

//requests data from the nunchuck
uint8_t NUNCHUCK::request_data(){
	Wire.beginTransmission(NUNADDRESS);
	Wire.write(DATARQ);
	Wire.flush();
	if(Wire.endTransmission() == 0){
		return 1;
	} else {
		return 0;
	}
}

//converts data to useable values
uint16_t NUNCHUCK::decode_data(uint16_t data){
	
	return (data ^ 0x17) + 0x17;
}

//receives / retreives the data and puts it in the container
uint8_t NUNCHUCK::retreive_data(){
	
	Wire.requestFrom(NUNADDRESS, 6);
	
	uint8_t index = 0;
	
	while(Wire.available()){
		nunDataArr[index] = decode_data(Wire.read());
		index++;
	}
	
	
	
	request_data();
	
	if(nunDataArr[4] != NULL){
		return 1;
	} else {
		return 0;
	}
	
	
}

//returns the position of the joy stick on the x axle
uint8_t NUNCHUCK::getJoyX(){
	if(nunDataArr[0] != NULL){
		return nunDataArr[0];
	} else {
		return 0;
	}
}

//returns the position of the joy stick on the y axle
uint8_t NUNCHUCK::getJoyY(){
	if(nunDataArr[1] != NULL){
		return nunDataArr[1];
		} else {
		return 0;
	}
}

//returns the position of the accellerometer on the x axle as a 10 bit value
uint8_t NUNCHUCK::getAccX(){
	if(nunDataArr[2] != NULL){
		uint8_t first8bitsX = (nunDataArr[2]);
		return first8bitsX;
	} else {
		return 0;
	}
}

//returns the position of the accellerometer on the y axle as a 10 bit value
uint8_t NUNCHUCK::getAccY(){
	if(nunDataArr[3] != NULL){
		uint8_t first8bitsY = (nunDataArr[3]);
		return first8bitsY;
	} else {
		return 0;
	}
}

//returns the position of the accellerometer on the z axle as a 10 bit value
uint8_t NUNCHUCK::getAccZ(){
	if(nunDataArr[4] != NULL){
		uint8_t first8bitsZ = (nunDataArr[4]);
		return first8bitsZ;
	} else {
		return 0;
	}
}

//returns true or false where true is button c pressed
uint8_t NUNCHUCK::getC(){
	if(nunDataArr[1] != NULL){
		return (((nunDataArr[5] & 0x02) >> 1) ^ 0x01) ;
	} else {
		return 0;
	}
}

//returns true or false where true is button z pressed
uint8_t NUNCHUCK::getZ(){
	if(nunDataArr[1] != NULL){
		return ((nunDataArr[5] & 0x01) ^ 0x01);
	} else {
		return 0;
	}
}




