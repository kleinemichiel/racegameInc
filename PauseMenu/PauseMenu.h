
/*
 * PauseMenu.h
 *
 * Created: 30-11-2015 14:58:18
 *  Author: michiel
 */ 


#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_

#include "SettingsMenu.h"
#include "MainMenuSP.h"
#include "PauseMenu.h"
#include "StateAndActions.h"
#include "MI0283QT9.h"
#include "USART.h"
#include "menuObjects.h"


extern void showPauseMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial);

#endif /* PAUSEMENU_H_ */