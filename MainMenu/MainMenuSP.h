/*
 * SettingsMenu.h
 *
 * Created: 27-11-2015 12:30:52
 *  Author: Eldin
 */ 


#ifndef MAINMENUSP_H_
#define MAINMENUSP_H_

#include "MI0283QT9.h"
#include "USART.h"
#include "menuObjects.h"

extern void showMainMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial);

#endif /* MAINMENUSP_H_ */