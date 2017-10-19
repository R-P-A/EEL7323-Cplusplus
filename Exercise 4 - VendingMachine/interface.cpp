#include "interface.h"

Interface::Interface() {
	Oled oledScreen;
	string tempString;
	int tempInt;
	oledScreen.setLine(0);
	oledScreen.printString("Constructing...");
	Product coke("Coke", 150);
	Product sprite("Sprite", 150);
	vector<Product> products = {coke, sprite};
	VendingMachine vm(products);
	int input = 1;
	while(input) {
		oledScreen.clearScreen();
		oledScreen.setLine(0);
		oledScreen.printString("Balance: ");
		tempInt = vm.getTotalValue();
		tempString = numberToString(tempInt);
		oledScreen.printString(tempString);
		oledScreen.clearLine(1);
		oledScreen.setLine(1);
		oledScreen.printString("Choose option:");
		cout << "\n0 - Exit\n1 - Insert Money\n2 - Give Money Back\n3 - Buy a Coke\n4 - Buy a Pepsi\n";
		cin >> input;
		cin.clear();
		if (input == 1) {
			insertMoney(vm, oledScreen);
		} else if (input == 2) {
			giveMoneyBack(vm, oledScreen);
		} else if (input == 3) {
			buyCoke(vm, oledScreen);
		} else if (input == 4) {
			buySprite(vm, oledScreen);
		} else {
			input = 0;
		}
	}
}

void Interface::insertMoney(VendingMachine& vm, Oled& oledScreen) {
	int input;
	string tempString;
	int tempInt;
	oledScreen.clearScreen();
	oledScreen.setLine(0);
	oledScreen.printString("Insert money");
	cout << "\nType the ammount of money\n";
	cin >> input;
	cin.clear();
	vm.insertValue(input);
	if (vm.getTotalValue() > vm.getProducts()[0].getValue()) {
		oledScreen.clearScreen();
		oledScreen.setLine(0);
		oledScreen.printString("Balance: ");
		tempInt = vm.getTotalValue();
		tempString = numberToString(tempInt);
		oledScreen.printString(tempString);
		oledScreen.setLine(1);
		oledScreen.clearLine(1);
		oledScreen.printString("Given back: ");
		tempInt = vm.getValueBack(vm.getTotalValue() - vm.getProducts()[0].getValue());
		tempString = numberToString(tempInt);
		oledScreen.printString(tempString);
		delayms(3000);
	}
}

void Interface::giveMoneyBack(VendingMachine& vm, Oled& oledScreen) {
	string tempString;
	int tempInt;
	oledScreen.clearScreen();
	oledScreen.setLine(0);
	oledScreen.printString("Balance: ");
	tempInt = vm.getTotalValue();
	tempString = numberToString(tempInt);
	oledScreen.printString(tempString);
	oledScreen.setLine(1);
	oledScreen.clearLine(1);
	oledScreen.printString("Given back: ");
	tempInt = vm.getValueBack(20000);
	tempString = numberToString(tempInt);
	oledScreen.printString(tempString);
	delayms(3000);
}

void Interface::buyCoke(VendingMachine& vm, Oled& oledScreen) {
	if (vm.buyProduct(0)) {
		oledScreen.clearScreen();
		oledScreen.setLine(0);
		oledScreen.printString("Coke Bought!");
		delayms(3000);
	} else {
		oledScreen.clearScreen();
		oledScreen.setLine(0);
		oledScreen.printString("Insufficient");
		oledScreen.setLine(1);
		oledScreen.printString("        funds");
		delayms(3000);
	}
}

void Interface::buySprite(VendingMachine& vm, Oled& oledScreen) {
	if (vm.buyProduct(1)) {
		oledScreen.clearScreen();
		oledScreen.setLine(0);
		oledScreen.printString("Sprite Bought!");
		delayms(3000);
	} else {
		oledScreen.clearScreen();
		oledScreen.setLine(0);
		oledScreen.printString("Insufficient");
		oledScreen.setLine(1);
		oledScreen.printString("        funds");
		delayms(3000);
	}
}