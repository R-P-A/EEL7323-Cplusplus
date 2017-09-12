#ifndef NODE
#define NODE

#include <iostream>

using namespace std;

template <class T>
class Node {
	private:
		T data;
		Node<T>* next;
		Node<T>* prev;

	public:
		Node():Node(0) { }
		
		Node(T data) {
			this->data = data;
			next = NULL;
			prev = NULL;
		}
		
		~Node () { }
		
		T getData() {
			return data;
		}
		
		void setData(T data) {
			this->data = data;
		}
		
		Node<T>* getNext() {
			return next;
		}
		
		void setNext(Node<T>* next) {
			this->next = next;
			if (next != NULL) {
				next->prev = this;
			}
		}
		
		Node<T>* getPrev() {
			return prev;
		}
		
		void setPrev(Node<T>* prev) {
			this->prev = prev;
			if (prev != NULL) {
				prev->next = this;
			}
		}
		
};

#endif          // NODE
