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
		/*
		 *	Send data through the SPI
		 *	@param data The data to be sent
		 */
		void sendData(char data);
		/*
		 *	Send a command through the SPI
		 *	@param command The command to be sent
		 */
		void sendCommand(unsigned command);
	public:
		/*
		 *	Constructor that power on and initiate the oled display
		 */
		Oled();
		/*
		 *	Destructor that turns off the oled display
		 */
		~Oled();

		/*
		 *	Select the line where the data transmitted through the SPI will be written
		 *	@param line The line to be written (range from 0 to 3)
		 */
		void setLine(unsigned line);
		/*
		 *	Fill the entire display with white
		 */
		void fillScreen();
		/*
		 *	Fill the entire display with black
		 */
		void clearScreen();
		/*
		 *	Clear the content of one line of the OLED
		 *	@param line The line to be cleared (range from 0 to 3)
		 */
		void clearLine(int line);
		/*
		 *	Print one character on the current position (line x column)
		 *	@param aux The character to be printed
		 */
		void printChar(char aux);
		/*
		 *	Print a string on the current position (line x column)
		 *	@param stringToPrint The string to be printed
		 */
		void printString(string stringToPrint);
};

#endif