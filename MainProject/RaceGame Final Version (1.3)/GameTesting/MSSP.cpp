/*
 * MSSP.cpp - MASTER SLAVE SOFTWARE PROTOCOL
 *
 * Created: 10-1-2016 14:33:33
 *  Author: Eldin
 * 
 * THIS PROTOCOL IS STILL IN WORK IN PROGRESS, IT MAY BE UNRELAIBLE AT VERY HIGH SPEEDS (ACTUALLY VERY LOW SPEEDS AS WELL, BUT ON VERY, VEEERYYYY LOW SPEEDS IT WORKS RELIABLE
 *
 * This protocol is a semi local timed/sync protocol, it sends a full byte on its local clock/timing before sending/receiving a sync pulse to get the local clock in sync.
 * Advantage of this is that this works on any timer overflow!
 * 
 * MAKE SURE TO SET ISR(TIMER*_OVF_vect){ISRMSSP();} before you start main!
 * FOR NOW ONLY WORKS ON C (PORTC/DDRC/PINC)
 *
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include "MSSP.h"
#include "USART.h"




//Values that needs to be shared between interrupt and outside program
volatile uint16_t clock = 0;

volatile uint16_t clockSpeed = 1;

volatile uint8_t clockPin = 0;

volatile uint8_t dataRPin = 0;

volatile uint8_t dataTPin = 0;

volatile uint8_t bitsSend = 0;

volatile uint8_t bitSend = 0;

volatile uint8_t byteToSend = 0;

volatile uint8_t currentByte = 0;

volatile uint8_t send = 0;

volatile uint8_t receive = 0;

volatile uint8_t byteToReceive = 0;

volatile uint8_t byteReceived = 0;

volatile uint8_t bitsReceived = 0;

volatile uint8_t bitReceived = 0;

volatile uint8_t master = 0;

volatile uint8_t slave = 0;

volatile uint8_t clockState = 0;

volatile uint8_t connected = 0;

volatile uint16_t resetTpin = 0;

volatile uint16_t syncPulseReceived = 0;

volatile uint8_t enableClock = 0;

volatile uint8_t bytesSend = 0;

volatile uint8_t turnOff = 0;

//ISR CODE 
void ISRMSSP(){
	
	if(!turnOff){
		if(slave)
		{
			
			DDRC |= (0 << clockPin) | (1 << dataTPin) | (0 << dataRPin) ;
			
			if(PINC & (1 << clockPin) && !enableClock)
			{
				
				enableClock = 1;
				PORTC |= (1 << dataTPin);
				
			}
			else if(enableClock)
			{
				
				if(clock == clockSpeed){
					
					if(!resetTpin){
						
						PORTC &= ~(1 << dataTPin);
						resetTpin = 1;
						
					}
					
					if(bytesSend){
						
						enableClock = 0;
						bytesSend = 0;
						PORTC &= ~(1 << dataTPin);
					}
					
					clock = 0;
					clockState ^= 1;
					syncPulseReceived = 0;
					
				}
				
				if(send){
					
					PORTC &= ~(1 << clockPin);
					
				}
				
				clock++;
				
			}
			
		}
		
		if(master)
		{
			
			DDRC |= (1 << clockPin) | (1 << dataTPin) | (0 << dataRPin) ;
			
			if(PINC & (1 << dataRPin) && !enableClock)
			{
				
				enableClock = 1;
				PORTC &= ~(1 << clockPin);
				
			}
			else if(enableClock)
			{
				
				if(clock == clockSpeed){
					
					if(!resetTpin){
						
						PORTC &= ~(1 << clockPin);
						resetTpin = 1;
						
					}
					
					clock = 0;
					clockState ^= 1;
					syncPulseReceived = 0;
					
					if(bytesSend){
						
						enableClock = 0;
						bytesSend = 0;
						
					}
					
				}
				
				clock++;
				
			}
			else
			{
				
				PORTC |= (1 << clockPin);
				
			}
			
		}
		
		if(clockState)
		{
			
			if(!bitSend)
			{
				send = 1;
				
				if(bitsSend == 8)
				{
					
					send = 0;
					bitsSend = 0;
					bitSend = 0;
					bytesSend = 1;
					currentByte = byteToSend;
					PORTC &= ~(1 << dataTPin);
					
				}
				
				if(slave)
				{
					
					if((currentByte >> (bitsSend)) & 1 )
					{
						PORTC |= (1 << dataTPin);
					}
					else
					{
						PORTC &= ~(1 << dataTPin);
					}
					
					bitSend = 1;
					
					
				}
				else
				{
					
					if((currentByte >> (bitsSend + 1)) & 1 )
					{
						PORTC |= (1 << dataTPin);
					}
					else
					{
						PORTC &= ~(1 << dataTPin);
					}
					
					
					bitSend = 1;
					
				}
				
				bitsSend++;
				
			}
			
			
			
			if(!bitReceived){
				
				receive = 1;
				
				if(bitsReceived == 8)
				{
					
					bitsReceived = 0;
					bitReceived = 0;
					receive = 0;
					byteReceived = byteToReceive;
					byteToReceive = 0;
					
				}
				
				if(PINC & (1 << dataRPin))
				{
					
					byteToReceive |= (1 << bitsReceived);
					bitsReceived++;
					bitReceived = 1;
					
				}
				else
				{
					
					bitsReceived++;
					bitReceived = 1;
					
				}
				
			}
			
		}
		else
		{
			
			bitReceived = 0;
			bitSend = 0;
			
		}
	}
	
}

//global values
uint8_t isMaster = 0;
uint8_t isSlave = 0;

//setup the pins for communication
void initMSSP(uint8_t clockPinIn, uint8_t dataRPinIn, uint8_t dataTPinIn, uint16_t clockSpeedIn){
	DDRC = 0;
	PORTC = 0;
	
	clockPin = clockPinIn;
	dataRPin = dataRPinIn;
	dataTPin = dataTPinIn;
	clockSpeed = clockSpeedIn;
	
	turnOff = 0;
	//use timer 2 without changing it (for security reasons)
	cli();         
	TIMSK2 |= (1 << TOIE2);
	sei();
	
}

//set master
void setMaster(){
	master = 1;
	slave = 0;
	isSlave = 0;
	isMaster = 1;
}

//set slave
void setSlave(){
	slave = 1;
	master = 0;
	isSlave = 1;
	isMaster = 0;
}

//stop MSSP when needed
void stopMSSP(){
	turnOff = 1;
}

//send a byte
void sendByte(uint8_t byteje){
	byteToSend = byteje;
}

//receive/get a byte
uint8_t getByte(){
	return byteReceived;
}

