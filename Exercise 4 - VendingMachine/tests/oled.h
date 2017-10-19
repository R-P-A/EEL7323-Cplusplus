#ifndef OLED_H
#define OLED_H

#include <iostream>
#include <string>
#include "myTime.h"

using namespace std;

#define CLOCKS_PER_MS 1000

//Pin list
#define CS 24 //pin 1
#define SDIN 25 //pin 2
#define SCLK 27 //pin 4 
#define DC 28 //pin 7
#define RES 29 //pin 8
#define VBATC 30 //pin 9
#define VDDC 31 //pin 10

class Oled {
	private:
		/** Send data through the SPI */
		void sendData(char data);
		/** Send a command through the SPI */
		void sendCommand(unsigned command);
		/** Set a pin */
		void setPin(int pin, int value);
	public:
		Oled();
		~Oled();
		/** OLED Power-On Sequence */
		void oledInit();
		/** OLED Power-Off Sequence */
		void oledOff();
		/** Select the line where the data transmitted through the SPI will be written (range from 0 to 3) */
		void setLine(unsigned line);
		/** Fill the entire display with white */
		void fillScreen();
		/** Fill the entire display with black */
		void clearScreen();
		/** Clear the content of one line of the OLED */
		void clearLine(int line);
		/** Print one character */
		void printChar(char aux);
		/** Print a string */
		void printString(string stringToPrint);
	
};

#endif