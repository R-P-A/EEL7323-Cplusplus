#include <iostream>

using namespace std;

class Node {
	private:

		type data;
		Node* next;
		Node* prev;

	public:

		Node(type tempData, Node* tempPrev, Node* tempNext);
		~Node();

		type getData();
		void setData(type tempData);

		Node* getNext();
		void setNext(Node* tempNext);

		Node* getPrev();
		void setPrev(Node* tempPrev);
};