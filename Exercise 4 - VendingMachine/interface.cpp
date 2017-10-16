#include "interface.h"

Interface::Interface() {
	cout << "Constructing the interface...\n\n";
	Product coke("Coke", 150);
	Product sprite("Sprite", 150);
	vector<Product> products = {coke, sprite};
	VendingMachine vm(products);
	cout << "Vending machine started...\n\n";
	int input;
	while(input) {
		cout << "\nCurrent configurations: \n" << vm.toString() << endl;
		cout << "Choose a new option:\n";
		cout << "0 - Exit\n1 - Insert Money\n2 - Give Money Back\n3 - Buy a Coke\n4 - Buy a Pepsi\n";
		cin >> input;
		if (input == 1) {
			insertMoney(vm);
		} else if (input == 2) {
			giveMoneyBack(vm);
		} else if (input == 3) {
			buyCoke(vm);
		} else if (input == 4) {
			buySprite(vm);
		} else {
			input = 0;
		}
	}
}

void Interface::insertMoney(VendingMachine& vm) {
	int input;
	cout << "Type the ammount of money\n";
	cin >> input;
	vm.insertValue(input);
	if (vm.getTotalValue() > vm.getProducts()[0].getValue()) {
		cout << "Amount of money given back: " << vm.getValueBack(vm.getTotalValue() - vm.getProducts()[0].getValue()) << endl;
	}
}

void Interface::giveMoneyBack(VendingMachine& vm) {
	cout << "Amount of money given back: " << vm.getValueBack(20000) << endl;
}

void Interface::buyCoke(VendingMachine& vm) {
	if (vm.buyProduct(0)) {
		cout << "Coke bought with sucess!\n";
	} else {
		cout << "Insufficient funds\n";
	}
}

void Interface::buySprite(VendingMachine& vm) {
	if (vm.buyProduct(1)) {
		cout << "Sprite bought with sucess!\n";
	} else {
		cout << "Insufficient funds\n";
	}
}