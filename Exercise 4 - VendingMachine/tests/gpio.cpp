#include "gpio.h"

volatile unsigned int *gpioBits = (volatile unsigned int *)0x80000A04;

void setPinIO(int pin, int value) {
	if (value) {
		int pinBinary = 1;
		pinBinary = pinBinary << pin;
		*gpioBits = *gpioBits | pinBinary;
	} else {
		int pinBinary = 1;
		pinBinary = ~(pinBinary << pin);
		*gpioBits = *gpioBits & pinBinary;
	}
}

bool getPinIO(int pin) {
	unsigned int pinBinary = *gpioBits;
	bool result = (pinBinary >> pin) & 1;
	cout << result << endl;
	return result;
}