/*
 * A2CP.h
 *
 * Created: 10-1-2016 14:34:57
 *  Author: Eldin
 */ 


#ifndef MSSP_H_
#define MSSP_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>



extern void ISRMSSP();
extern void initMSSP(uint8_t clockPinIn, uint8_t dataRPinIn, uint8_t dataTPinIn, uint16_t clockSpeedIn);
extern void setSlave();
extern void setMaster();
extern void sendByte(uint8_t byteje);
extern void stopMSSP();
extern uint8_t getByte();

extern uint8_t isMaster;
extern uint8_t isSlave;

#endif /* MSSP_H_ */