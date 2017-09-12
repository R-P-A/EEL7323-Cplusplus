#include "../node.cpp"
#include <iostream>

using namespace std;

int main () {
	Node<int>* node1 = new Node<int>();
	Node<int>* node2 = new Node<int>(2);
	Node<int>* node3 = new Node<int>(3);
	node1->setData(1);
	node1->setNext(node2);
	node2->setPrev(node1);
	node2->setNext(node3);
	node3->setPrev(node2);
	cout << node2->getData() << endl;
	cout << node2->getPrev()->getData() << endl;
	cout << node2->getNext()->getData() << endl;
	getchar();
	delete node1;
	delete node2;
	return 0;
}