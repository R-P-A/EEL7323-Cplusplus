#include "node.cpp"
#include <iostream>

using namespace std;

int main () {
	int a = 1;
	int b = 2;
	Node node1 = new Node(a, 0, 0);
	Node node2 = new Node(b, node1, 0);
	cout << to_string(Node.getData(node1)) << endl;
	getchar();
	return 0;
}