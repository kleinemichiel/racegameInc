/*
 * highscoreMenu.h
 *
 * Created: 27-11-2015 12:30:52
 *  Author: Daniek
 */ 


#ifndef HIGHSCOREMENU_H_
#define HIGHSCOREMENU_H_

#include "MI0283QT9.h"
#include "USART.h"
#include "menuObjects.h"
#include <EEPROM.h>

extern void showHighscoreMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial);

#endif /* HIGHSCOREMENU_H_ */