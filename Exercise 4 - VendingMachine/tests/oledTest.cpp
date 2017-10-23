#include <iostream>
#include "oled.h"
#include "gpio.h"

using namespace std;

int main(void) {
	cout << "testing 3 seconds delay" << endl;
	delayms(3000);
	cout << "delay testing done" << endl;
	cout << "testing LEDS" << endl;
	setPinIO(LED0, 1);
	setPinIO(LED1, 1);
	setPinIO(LED2, 1);
	setPinIO(LED3, 1);
	setPinIO(LED4, 1);
	setPinIO(LED5, 1);
	cout << "testing switches and buttons" << endl;
	while (!getPinIO(SW0));
	cout << "done SW0\n";
	while (!getPinIO(SW1));
	cout << "done SW1\n";
	while (!getPinIO(SW2));
	cout << "done SW2\n";
	while (!getPinIO(SW3));
	cout << "done SW3\n";
	while (!getPinIO(SW4));
	cout << "done SW4\n";
	while (!getPinIO(SW5));
	cout << "done SW5\n";
	while (!getPinIO(BTNU));
	cout << "done BTNU\n";
	while (!getPinIO(BTNL));
	cout << "done BTNL\n";
	while (!getPinIO(BTND));
	cout << "done BTND\n";
	while (!getPinIO(BTNR));
	cout << "done BTNR\n";
	while (!getPinIO(BTNC));
	cout << "done BTNC\n";
	cout << "testing OLED" << endl;
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