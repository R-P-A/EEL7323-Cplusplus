#include "vendingMachine.h"

VendingMachine::VendingMachine() {
	totalValue = 0;	
}

VendingMachine::VendingMachine(vector<Product> listOfProducts) {
	totalValue = 0;
	products = listOfProducts;
}

int VendingMachine::getTotalValue() {
	return totalValue;
}

void VendingMachine::insertValue(int value) {
	totalValue += value;
}

vector<Product> VendingMachine::getProducts() {
	return products;
}

int VendingMachine::getValueBack(int value) {
	if (value > totalValue) {
		value = totalValue;
		totalValue = 0;
		return value;
	}
	totalValue -= value;
	return value;
}

bool VendingMachine::buyProduct(int productIndex) {
	if (totalValue >= products[productIndex].getValue()) {
		totalValue -= products[productIndex].getValue();
		return true;
	}
	return false;
}

string VendingMachine::toString() {
	string result;
	result = "Total Value: " + to_string(totalValue) + "\n";
	result += "Products list: \n";
	for (unsigned int i = 0; i < products.size(); i++) {
		result += to_string(i) + " - " + products[i].getName() + "\tValue: " + to_string(products[i].getValue()) + "\n";
	}
	return result;
}
