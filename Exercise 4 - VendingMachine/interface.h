#ifndef INTERFACE
#define INTERFACE

#include <iostream>
#include <vector>
#include "vendingMachine.h"
#include "product.h"
#include "readInput.h"
#include "myTime.h"
#include "myString.h"
#include "oled.h"
#include "gpio.h"

using namespace std;

class Interface {
	private:
		void insertMoney(VendingMachine& vm, Oled& oledScreen);
		void giveMoneyBack(VendingMachine& vm, Oled& oledScreen);
		void buyCoke(VendingMachine& vm, Oled& oledScreen);
		void buySprite(VendingMachine& vm, Oled& oledScreen);
	public:
		Interface();
};

#endif