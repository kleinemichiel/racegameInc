/*
 * GridLayout.h
 *
 * Created: 2-12-2015 13:42:19
 *  Author: Willem
 */ 


#ifndef GRIDLAYOUT_H_
#define GRIDLAYOUT_H_
#include "MI0283QT9.h"
#include "USART.h"
#include "GraphicsLib.h"

extern void showGridLayout(MI0283QT9 lcd, MY_USART serial);

extern uint16_t pixelPosY(uint8_t y);
extern uint16_t pixelPosX(uint8_t x);

#define GRIDYLENGTH (uint8_t)20
#define GRIDXLENGTH (uint8_t)5

#endif /* GRIDLAYOUT_H_ */