#include "interface.h"

Interface::Interface() {
	// Variables
	Oled oledScreen;
	string tempString;
	int tempInt;

	// Initialization
	oledScreen.setLine(0);
	oledScreen.printString("Constructing...");
	Product coke("Coke", 150);
	Product sprite("Sprite", 150);
	vector<Product> products = {coke, sprite};
	VendingMachine vm(products);

	while(!getPinIO(BTNC)) {
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
		// Wait loop
		while (!getPinIO(BTNC) && !getPinIO(BTNU) && !getPinIO(BTNL) && !getPinIO(BTND) && !getPinIO(BTNR));
		if (getPinIO(BTNU)) {
			insertMoney(vm, oledScreen);
		} else if (getPinIO(BTND)) {
			giveMoneyBack(vm, oledScreen);
		} else if (getPinIO(BTNL)) {
			buyCoke(vm, oledScreen);
		} else if (getPinIO(BTNR)) {
			buySprite(vm, oledScreen);
		}
		// Delay to stabilize BTNC
		delayms(100);
	}
}

void Interface::insertMoney(VendingMachine& vm, Oled& oledScreen) {
	// Variables
	int money = 0;
	string tempString;
	int tempInt;
	bool switch0, switch1, switch2, switch3, switch4;

	switch0 = getPinIO(SW0);
	switch1 = getPinIO(SW1);
	switch2 = getPinIO(SW2);
	switch3 = getPinIO(SW3);
	switch4 = getPinIO(SW4);

	if (switch0)
		money += 5;
	if (switch1)
		money += 10;
	if (switch2)
		money += 25;
	if (switch3)
		money += 50;
	if (switch4)
		money += 100;

	delayms(200);

	if ((switch0 && !switch1 && !switch2 && !switch3 && !switch4) ||
		(!switch0 && switch1 && !switch2 && !switch3 && !switch4) ||
		(!switch0 && !switch1 && switch2 && !switch3 && !switch4) ||
		(!switch0 && !switch1 && !switch2 && switch3 && !switch4) ||
		(!switch0 && !switch1 && !switch2 && !switch3 && switch4)) {
		vm.insertValue(money);		
	} else {
		oledScreen.clearScreen();oledScreen.setLine(1);
		oledScreen.clearLine(1);
		oledScreen.printString("Given back: ");
		tempString = numberToString(money);
		oledScreen.printString(tempString);
		giveBackMachine(vm, oledScreen, money);
		delayms(2000);
	}
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
		giveBackMachine(vm, oledScreen, tempInt);
		delayms(2000);
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
	giveBackMachine(vm, oledScreen, tempInt);
	delayms(2000);
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

void Interface::giveBackMachine(VendingMachine& vm, Oled& oledScreen, int moneyReturned) {
	int coins;

	// Return coins of 100
	coins = moneyReturned / 100;
	for (int i = 0; i < coins; i++) {
		setPinIO(LED4, 1);
		delayms(500);
		setPinIO(LED4, 0);
		delayms(50);
	}
	moneyReturned = moneyReturned % 100;

	// Return coins of 50
	coins = moneyReturned / 50;
	for (int i = 0; i < coins; i++) {
		setPinIO(LED3, 1);
		delayms(500);
		setPinIO(LED3, 0);
		delayms(50);
	}
	moneyReturned = moneyReturned % 50;

	// Return coins of 25
	coins = moneyReturned / 25;
	for (int i = 0; i < coins; i++) {
		setPinIO(LED2, 1);
		delayms(500);
		setPinIO(LED2, 0);
		delayms(50);
	}
	moneyReturned = moneyReturned % 25;

	// Return coins of 10
	coins = moneyReturned / 10;
	for (int i = 0; i < coins; i++) {
		setPinIO(LED1, 1);
		delayms(500);
		setPinIO(LED1, 0);
		delayms(50);
	}
	moneyReturned = moneyReturned % 10;

	// Return coins of 5
	coins = moneyReturned / 5;
	for (int i = 0; i < coins; i++) {
		setPinIO(LED0, 1);
		delayms(500);
		setPinIO(LED0, 0);
		delayms(50);
	}
	moneyReturned = moneyReturned % 5;
}