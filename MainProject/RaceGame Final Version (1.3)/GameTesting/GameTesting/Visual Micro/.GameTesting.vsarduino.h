/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino/Genuino Uno, Platform=avr, Package=arduino
*/

#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 165
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define F_CPU 16000000L
#define ARDUINO 165
#define ARDUINO_AVR_UNO
#define ARDUINO_ARCH_AVR
extern "C" void __cxa_pure_virtual() {;}

void writeCalData(void);
uint8_t readCalData(void);
int main();

#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\standard\pins_arduino.h" 
#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include <GameTesting.ino>
#include <ADS7846.h>
#include <BMPheader.h>
#include <Default_Layout.cpp>
#include <Default_Layout.h>
#include <DisplayI2C.cpp>
#include <DisplayI2C.h>
#include <DisplaySPI.cpp>
#include <DisplaySPI.h>
#include <GameLoop.cpp>
#include <GameLoop.h>
#include <GameObjects.cpp>
#include <GameObjects.h>
#include <GameOverMenu.cpp>
#include <GameOverMenu.h>
#include <GraphicsLib.cpp>
#include <GraphicsLib.h>
#include <GridLayout.cpp>
#include <GridLayout.h>
#include <MI0283QT9.cpp>
#include <MI0283QT9.h>
#include <MSSP.cpp>
#include <MSSP.h>
#include <MainMenuSP.cpp>
#include <MainMenuSP.h>
#include <Multiplayer.cpp>
#include <Multiplayer.h>
#include <NunChuck.cpp>
#include <NunChuck.h>
#include <PauseMenu.cpp>
#include <PauseMenu.h>
#include <RealGen.cpp>
#include <RealGen.h>
#include <SettingsMenu.cpp>
#include <SettingsMenu.h>
#include <StateAndActions.cpp>
#include <StateAndActions.h>
#include <USART.cpp>
#include <USART.h>
#include <cmd.h>
#include <digitalWriteFast.h>
#include <font_8x8.c>
#include <fonts.h>
#include <glcdfont.c>
#include <highscoreMenu.cpp>
#include <highscoreMenu.h>
#include <includeMe.h>
#include <menuObjects.cpp>
#include <menuObjects.h>
