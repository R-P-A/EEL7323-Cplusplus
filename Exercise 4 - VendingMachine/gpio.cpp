#include "gpio.h"

// Global variables to read the pins
// Sets if the pin is input or output
volatile unsigned int *direction = (volatile unsigned int *)0x80000A08;
// Set the ouput pins
volatile unsigned int *output = (volatile unsigned int *)0x80000A04;
// Get the input pins
volatile unsigned int *input = (volatile unsigned int *)0x80000A00;

void setPinIO(int pin, bool value) {
	if (value) {
		int pinBinary = 1;
		pinBinary = pinBinary << pin;
		*direction = *direction  | pinBinary;
		*output = *output | pinBinary;
	} else {
		int pinBinary = 1;
		pinBinary = ~(pinBinary << pin);
		*output = *output & pinBinary;
	}
}

bool getPinIO(int pin) {
	unsigned int pinBinary = *input;
	bool result = (pinBinary >> pin) & 1;
	return result;
}