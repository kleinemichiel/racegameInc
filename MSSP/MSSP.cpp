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

//Includes needed
#include <avr/interrupt.h>
#include <stdint.h>

//Values that needs to be shared between interrupt and outside program
volatile uint16_t clock = 0;

volatile uint16_t clockSpeed = 1;

volatile uint8_t syncPin = 0;

volatile uint8_t receivePin = 0;

volatile uint8_t transmitPin = 0;

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
			
			DDRC |= (0 << syncPin) | (1 << transmitPin) | (0 << receivePin) ;
			
			if(PINC & (1 << syncPin) && !enableClock)
			{
				
				enableClock = 1;
				PORTC |= (1 << transmitPin);
				
			}
			else if(enableClock)
			{
				
				if(clock == clockSpeed){
					
					if(!resetTpin){
						
						PORTC &= ~(1 << transmitPin);
						resetTpin = 1;
						
					}
					
					if(bytesSend){
						
						enableClock = 0;
						bytesSend = 0;
						PORTC &= ~(1 << transmitPin);
					}
					
					clock = 0;
					clockState ^= 1;
					syncPulseReceived = 0;
					
				}
				
				if(send){
					
					PORTC &= ~(1 << syncPin);
					
				}
				
				clock++;
				
			}
			
		}
		
		if(master)
		{
			
			DDRC |= (1 << syncPin) | (1 << transmitPin) | (0 << receivePin) ;
			
			if(PINC & (1 << receivePin) && !enableClock)
			{
				
				enableClock = 1;
				PORTC &= ~(1 << syncPin);
				
			}
			else if(enableClock)
			{
				
				if(clock == clockSpeed){
					
					if(!resetTpin){
						
						PORTC &= ~(1 << syncPin);
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
				
				PORTC |= (1 << syncPin);
				
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
					PORTC &= ~(1 << transmitPin);
					
				}
				
				if(slave)
				{
					
					if((currentByte >> (bitsSend)) & 1 )
					{
						PORTC |= (1 << transmitPin);
					}
					else
					{
						PORTC &= ~(1 << transmitPin);
					}
					
					bitSend = 1;
					
					
				}
				else
				{
					
					if((currentByte >> (bitsSend + 1)) & 1 )
					{
						PORTC |= (1 << transmitPin);
					}
					else
					{
						PORTC &= ~(1 << transmitPin);
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
				
				if(PINC & (1 << receivePin))
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
void initMSSP(uint8_t syncPinIn, uint8_t receivePinIn, uint8_t transmitPinIn, uint16_t clockSpeedIn){
	DDRC = 0;
	PORTC = 0;
	
	syncPin = syncPinIn;
	receivePin = receivePinIn;
	transmitPin = transmitPinIn;
	clockSpeed = clockSpeedIn;
	
	turnOff = 0;
	//use timer 2 without changing it 
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

//send a byte
void sendByte(uint8_t byteje){
	byteToSend = byteje;
}

//receive/get a byte
uint8_t getByte(){
	return byteReceived;
}

//stop MSSP when needed
void stopMSSP(){
	turnOff = 1;
}
