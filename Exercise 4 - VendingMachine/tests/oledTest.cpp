#include <iostream>
#include "oled.h"
#include "gpio.h"

using namespace std;

volatile unsigned int *direction = (volatile unsigned int *)0x80000A08;
volatile unsigned int *data = (volatile unsigned int *)0x80000A00;

int main(void) {
	*direction = 0xFF000000;
	*data = 0xFF000000;
	cout << "testing 3 seconds delay" << endl;
	setPinIO(LED0, 1);
	getPinIO(LED0);
	while (getPinIO(BTNC));
	delayms(3000);
	cout << "delay testing done" << endl;
	Oled oledTest;
	oledTest.clearScreen();
	oledTest.setLine(1);
	oledTest.printString("Hello World!");
	delayms(3000);
	oledTest.clearLine(1);
	oledTest.setLine(2);
	oledTest.printString("Hello");
	delayms(3000);
	oledTest.clearScreen();
	delayms(3000);
	oledTest.fillScreen();
	delayms(3000);
	setPinIO(LED0, 0);
	getPinIO(LED0);
	return 0;
}