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
	delay(500000);
	oledOff();
	return 0;
}