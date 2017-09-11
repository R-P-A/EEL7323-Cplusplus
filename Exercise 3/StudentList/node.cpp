#include <iostream>
#include "node.h"

using namespace std;

Node::Node(type tempData, Node* tempPrev, Node* tempNext) {
	cout << "Constructing Node...";
	data = tempData;
	next = tempNext;
	prev = tempPrev;
}

Node::~Node () {
	delete prev;
	delete next;
	cout << "Deleting Node...";
}

Node::getData() {
	return data;
}
void Node::setData(type tempData) {
	data = tempData;
}

Node* Node::getNext() {
	return next;
}
void Node::setNext(Node* tempNext) {
	next = tempNext;
}

Node* Node::getPrev() {
	return prev;
}
void Node::setPrev(Node* tempPrev) {
	prev = tempPrev;
}