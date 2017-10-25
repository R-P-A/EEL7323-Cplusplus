#ifndef GPIO
#define GPIO

#include <iostream>

using namespace std;

// Pin list
// LEDS
#define LED0 0		// led 0
#define LED1 1		// led 1
#define LED2 2		// led 2
#define LED3 3		// led 3
#define LED4 4		// led 4
#define LED5 5		// led 5
// Switches
#define SW0 8		// switch 0
#define SW1 9		// switch 1
#define SW2 10		// switch 2
#define SW3 11		// switch 3
#define SW4 12		// switch 4
#define SW5 13		// switch 5
// Buttons
#define BTNU 16		// upper button
#define BTNL 17		// left button
#define BTND 18		// lower button
#define BTNR 19		// right button
#define BTNC 20		// center button
// PMOD IO (OLED)
#define CS 24 		// pmod pin 1
#define SDIN 25 	// pmod pin 2
#define SCLK 27 	// pmod pin 4 
#define DC 28 		// pmod pin 7
#define RES 29 		// pmod pin 8
#define VBATC 30	// pmod pin 9
#define VDDC 31		// pmod pin 10

/*
 *	Set an output pin of LEON3 in Atlys Spartan-6 Board
 *	@param pin Pin number
 *	@param value 1 (set) or 0 (clear)
 */
void setPinIO(int pin, bool value);

/*
 *	Get an input pin of LEON3 in Atlys Spartan-6 Board
 *	@param pin Pin number
 *	@return	Wheter it is set (1) or not (0)
 */
bool getPinIO(int pin);

#endif	// GPIO