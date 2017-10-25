#include "gpio.h"

volatile unsigned int *direction = (volatile unsigned int *)0x80000A08;
volatile unsigned int *output = (volatile unsigned int *)0x80000A04;
volatile unsigned int *input = (volatile unsigned int *)0x80000A00;

void setPinIO(int pin, int value) {
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