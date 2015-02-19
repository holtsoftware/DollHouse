/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: RFduino, Platform=RFduino, Package=arduino
*/

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __RFduino__
#define ARDUINO 160
#define ARDUINO_MAIN
#define printf iprintf
#define __RFDUINO__
#define __RFduino__
#define F_CPU 16000000
#define __cplusplus
#define GCC_VERSION 40803
#define ARDUINO_ARCH_RFDUINO
#define ARDUINO_RFDUINO_RFDUINO

#include <arduino.h>
#include <libRFduino.h> 
#include <libRFduinoBLE.h> 
#include <libRFduinoGZLL.h> 
#include <pins_arduino.h> 
#include <variant.h> 
#undef F
#define F(string_literal) ((const PROGMEM char *)(string_literal))
#undef cli
#define cli()
#define pgm_read_byte(address_short)
#define pgm_read_word(address_short)
#define pgm_read_word2(address_short)
#define digitalPinToPort(P)
#define digitalPinToBitMask(P) 
#define digitalPinToTimer(P)
#define analogInPinToBit(P)
#define portOutputRegister(P)
#define portInputRegister(P)
#define portModeRegister(P)
#include <RFDollHouse.ino>
#include <DollHouse.h>
#include <Message.h>
#endif
