#include <iostream>
#include <time.h>
#include "oled.h"
#include "readInput.h"

using namespace std;

int main(void) {
	cout << "testing delay 3 seconds" << endl;
	delayms(3000);
	cout << "delay testing done" << endl;
	Oled oledTest;
	oledTest.clearScreen();
	oledTest.setLine(1);
	oledTest.printString("Hello World!");
	delayms(3000);
	oledTest.clearLine(1);
	oledTest.setLine(2);
	oledTest.printString("Type something");
	string tempString;
	cin >> tempString;
	oledTest.setLine(3);
	oledTest.printString(tempString);
	delayms(3000);
	oledTest.clearScreen();
	delayms(3000);
	oledTest.fillScreen();
	delayms(3000);
	return 0;
}