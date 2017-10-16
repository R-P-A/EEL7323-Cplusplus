#ifndef PRODUCT
#define PRODUCT

#include <iostream>

using namespace std;

class Product {
	private:
		string name;
		int value;
	public:
		Product(string inputName, int inputValue);
		string getName();
		void setName(string inputName);
		int getValue();
		void setValue(int inputValue);
};

#endif