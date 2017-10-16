#include "product.h"

Product::Product(string inputName, int inputValue) {
	name = inputName;
	value = inputValue;
}

string Product::getName() {
	return name;
}

void Product::setName(string inputName) {
	name = inputName;
}

int Product::getValue() {
	return value;
}

void Product::setValue(int inputValue) {
	value = inputValue;
}