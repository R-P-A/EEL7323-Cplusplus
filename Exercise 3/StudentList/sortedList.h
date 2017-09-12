#include <iostream>
#include "model.h"
#include "node.h"

using namespace std;

template <class T>
class SortedList {
    private:
        Node<T>* head;

    public:
        SortedList();
        ~SortedList();

        void insert(Node<T>* node);

        void remove(int id);

        void edit(Node<T>* node);

        T find(int id);

        void listAll();
};
