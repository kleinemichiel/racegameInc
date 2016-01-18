/*
 * Multiplayer.h
 *
 * Created: 21-12-2015 14:08:17
 *  Author: Eldin
 */ 

#pragma once
#ifndef MULTIPLAYER_H_
#define MULTIPLAYER_H_
#include "includeMe.h"





extern uint8_t isConnected;
extern void showMpMenu(MI0283QT9 lcd);

extern void sendHostPosition(uint8_t x);
extern uint8_t getClientPosition();

extern void sendGameOver();
extern uint8_t getGameOver();
extern void exitMultiplayer();






#endif /* MULTIPLAYER_H_ */