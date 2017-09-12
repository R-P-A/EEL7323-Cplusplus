#include <iostream>
#include "node.h"

using namespace std;

template <class T>
Node<T>::Node():Node(0) { }

template <class T>
Node<T>::Node(T data) {
	cout << "Constructing Node..." << endl;
	Node<T>::data = data;
	next = NULL;
	prev = NULL;
}

template <class T>
Node<T>::~Node () {
	cout << "Deleting Node..." << endl;
}

template <class T>
T Node<T>::getData() {
	return data;
}
template <class T>
void Node<T>::setData(T data) {
	Node<T>::data = data;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return next;
}
template <class T>
void Node<T>::setNext(Node* next) {
	Node<T>::next = next;
}

template <class T>
Node<T>* Node<T>::getPrev() {
	return prev;
}
template <class T>
void Node<T>::setPrev(Node* prev) {
	Node<T>::prev = prev;
}