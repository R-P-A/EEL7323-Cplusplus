#include <iostream>
#include <time.h>
#include "oled.h"

using namespace std;

int main(void) {
	char helloWorld[20] = "Hello";
	cout << clock() << endl;
	delay(100000);
	cout << clock() << endl;
	oledInit();
	delay(100000);
	oledFill();
	delay(100000);
	oledClear();
	printString(helloWorld);
	return 0;
}