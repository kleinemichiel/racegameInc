/*
 * Default_Layout.h
 *
 * Created: 30-11-2015 12:58:30
 *  Author: michiel
 */ 


#ifndef DEFAULT_LAYOUT_H_
#define DEFAULT_LAYOUT_H_
#include "MI0283QT9.h"
#include "USART.h"
extern void showDefaultLayout(MI0283QT9 lcd, MY_USART serial);

#endif /* DEFAULT_LAYOUT_H_ */
//colors of default layout
//green grass
#define GRASSCOLOR RGB(0,162,9)
//black road
#define ROADCOLOR RGB(0,0,0)
