#ifndef VENDINGMACHINE
#define VENDINGMACHINE

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

class VendingMachine {
	private:
		int totalValue;
		vector<Product> products;
	public:
		VendingMachine();
		VendingMachine(vector<Product> listOfProducts);
		int getTotalValue();
		void insertValue(int value);
		vector<Product> getProducts();
		int getValueBack(int value);
		bool buyProduct(int productIndex);
		string toString();
};

#endif //VENDINGMACHINE