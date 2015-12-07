// game.h

#ifndef _GAME_h
#define _GAME_h

#include "MI0283QT9.h"
#include "USART.h"
#include "Default_Layout.h"
#include "GameObjects.h"
#include "NunChuck.h"
#include "RealGen.h"



extern void showGame(MI0283QT9 lcd, MY_USART serial, NUNCHUCK nun);


#endif

#define GRASSCOLOR RGB(0,142,9)
//black road
#define ROADCOLOR RGB(0,0,0)
