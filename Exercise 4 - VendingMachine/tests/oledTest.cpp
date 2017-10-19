#include <iostream>
#include <time.h>
#include "oled.h"

using namespace std;

int main(void) {
	string helloWorld = "Hi Test2";
	oledInit();
	oledClear();
	setLine(1);
	printString(helloWorld);
	helloWorld = "Hi 123";
	delay(5000000);
	clearLine(1);
	setLine(2);
	printString(helloWorld);
	delay(5000000);
	oledClear();
	delay(5000000);
	oledFill();
	delay(5000000);
	oledOff();
	return 0;
}