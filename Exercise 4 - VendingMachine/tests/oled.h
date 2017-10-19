#ifndef OLED_H
#define OLED_H

#include <iostream>
#include <string>
#include "myTime.h"
#include "gpio.h"

using namespace std;

#define CLOCKS_PER_MS 1000

class Oled {
	private:
		/** Send data through the SPI */
		void sendData(char data);
		/** Send a command through the SPI */
		void sendCommand(unsigned command);
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