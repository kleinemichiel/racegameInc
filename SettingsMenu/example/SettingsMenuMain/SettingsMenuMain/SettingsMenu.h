/*
 * SettingsMenu.h
 *
 * Created: 27-11-2015 12:30:52
 *  Author: Eldin
 */ 


#ifndef SETTINGSMENU_H_
#define SETTINGSMENU_H_

#include "MI0283QT9.h"
#include "USART.h"
#include "menuObjects.h"

//makes it possible to use this function without defining a class, so you dont have to define a type for the class in the main program, easier and less messy
extern void showSettingMenu(MI0283QT9 lcd, MENUOBJECTS obj, MY_USART serial);

#endif /* SETTINGSMENU_H_ */