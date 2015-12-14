/*
 * GameOverMenu.h
 *
 * Created: 7-12-2015 12:31:41
 *  Author: Eldin
 */ 


#ifndef GAMEOVERMENU_H_
#define GAMEOVERMENU_H_

#include "MI0283QT9.h"
#include "USART.h"
#include "menuObjects.h"
#include "MainMenuSP.h"


extern void showGameOverMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial, uint16_t score);



#endif /* GAMEOVERMENU_H_ */