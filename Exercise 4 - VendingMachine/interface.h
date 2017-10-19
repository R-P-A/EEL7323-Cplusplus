#ifndef INTERFACE
#define INTERFACE

#include <iostream>
#include <vector>
#include "vendingMachine.h"
#include "product.h"
#include "readInput.h"

using namespace std;

class Interface {
	private:
		void insertMoney(VendingMachine& vm);
		void giveMoneyBack(VendingMachine& vm);
		void buyCoke(VendingMachine& vm);
		void buySprite(VendingMachine& vm);
	public:
		Interface();
};

#endif