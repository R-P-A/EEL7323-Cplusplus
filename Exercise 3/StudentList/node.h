#include <iostream>

using namespace std;

template <class T>
class Node {
	private:

		T data;
		Node<T>* next;
		Node<T>* prev;

	public:

		Node();
		Node(T data);
		~Node();

		T getData();
		void setData(T data);

		Node* getNext();
		void setNext(Node* next);

		Node* getPrev();
		void setPrev(Node* prev);
};