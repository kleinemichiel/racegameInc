/*
 * RealGen.h
 *
 * Created: 3-12-2015 12:41:55
 *  Author: Eldin
 */ 


#ifndef REALGEN_H_
#define REALGEN_H_

#include "GameObjects.h"
#include "MI0283QT9.h"
#include "USART.h"
#include "math.h"
#include "SettingsMenu.h"

//for testing the generator

//stores objects with their position
extern objects object[2];

extern void showGenObjects(MI0283QT9 lcd, MY_USART serial);


#endif /* REALGEN_H_ */