/*
 * includeMe.h
 *
 * Created: 16-12-2015 17:33:09
 *  Author: Eldin
 */ 

#pragma once

#define ADDRESS 0x36
/*In the includeMe.h are all files include. In every other file the inlcudeMe.h is included. Now we can use every function from every file in the file you want.*/
#include <EEPROM.h>
#include "stdint.h"
#include "digitalWriteFast.h"
#include "GraphicsLib.h"
#include "MI0283QT9.h"
#include "USART.h"
#include "NunChuck.h"
#include "StateAndActions.h"
#include "menuObjects.h"
#include "MainMenuSP.h"
#include "SettingsMenu.h"
#include "highscoreMenu.h"
#include "PauseMenu.h"
#include "GameOverMenu.h"
#include "Default_Layout.h"
#include "GridLayout.h"
#include "GameObjects.h"
#include "Multiplayer.h"
#include "GameLoop.h"
#include "MSSP.h"
/*
#ifndef INCLUDEME_H_
#define INCLUDEME_H_





#endif / * INCLUDEME_H_ * /*/