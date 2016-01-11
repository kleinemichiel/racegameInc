#include <avr/io.h>
#include "USART.h"

extern void initCom();
extern void sendPlayerX(uint8_t X);//will send information of the player positon
extern uint8_t retrievePlayerX(void);





