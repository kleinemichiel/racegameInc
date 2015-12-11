// game.h

#ifndef _GAME_h
#define _GAME_h


#include "MI0283QT9.h"
#include "USART.h"
#include "Default_Layout.h"
#include "GameObjects.h"
#include "NunChuck.h"
#include "SettingsMenu.h"
#include "MainMenuSP.h"
#include "PauseMenu.h"

extern void showGame(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial);


#endif

