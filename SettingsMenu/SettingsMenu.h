/*
 * SettingsMenu.h
 *
 * Created: 27-11-2015 12:30:52
 *  Author: Eldin
 */ 

#pragma once
#ifndef SETTINGSMENU_H_
#define SETTINGSMENU_H_

#include "includeMe.h"

//global values accessable by any other libary included below this library
extern uint8_t realTime;
extern uint8_t preTime;

extern uint8_t easy;
extern uint8_t medium;
extern uint8_t hard;

extern uint8_t sLow;
extern uint8_t sMedium;
extern uint8_t sHigh;

extern uint8_t red;
extern uint8_t green;
extern uint8_t blue;

extern uint8_t setY;
extern uint8_t setT;
//makes it possible to use this function without defining a class, so you dont have to define a type for the class in the main program, easier and less messy
extern void showSettingMenu(MI0283QT9 lcd);

#endif /* SETTINGSMENU_H_ */