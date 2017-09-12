#include <iostream>
#include "node.h"

using namespace std;

template <class T>
Node<T>::Node():Node(0) { }

template <class T>
Node<T>::Node(T data) {
	this->data = data;
	next = NULL;
	prev = NULL;
}

template <class T>
Node<T>::~Node () { }

template <class T>
T Node<T>::getData() {
	return data;
}

template <class T>
void Node<T>::setData(T data) {
	this->data = data;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <class T>
void Node<T>::setNext(Node* next) {
	this->next = next;
	if (next != NULL) {
		next->prev = this;
	}
}

template <class T>
Node<T>* Node<T>::getPrev() {
	return prev;
}

template <class T>
void Node<T>::setPrev(Node* prev) {
	this->prev = prev;
	if (prev != NULL) {
		prev->next = this;
	}
}