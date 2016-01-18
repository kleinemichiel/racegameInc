#ifndef fonts_h
#define fonts_h

#if defined(__AVR__)
# include <avr/pgmspace.h>
#endif

// All font data from Benedikt K.
// http://www.mikrocontroller.net/topic/54860

//Font selection (select only one font)
//#define FONT_4X6
//#define FONT_5X8
//#define FONT_5X12
//#define FONT_6X8
//#define FONT_6X10
//#define FONT_7X12
#define FONT_8X8
//#define FONT_8X12
//#define FONT_8X14
//#define FONT_10X16
//#define FONT_12X16
//#define FONT_12X20
//#define FONT_16X26

//if defined char range 0x20-0x7F otherwise 0x20-0xFF
#define FONT_END7F

#define FONT_START (0x20) //first character

#if defined(FONT_8X8)
# define FONT_WIDTH   (8)
# define FONT_HEIGHT  (8)
#else
# warning No font defined
#endif

#if defined(__AVR__)
extern const PROGMEM uint8_t font_PGM[];
#else
extern const uint8_t font_PGM[];
#endif

#endif //fonts_h
