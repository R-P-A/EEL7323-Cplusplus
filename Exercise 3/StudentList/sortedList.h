#include <iostream>
#include "model.h"
#include "node.h"

using namespace std;

class SortedList {
    private:
        Node<Model>* head;

    public:
        SortedList();
        ~SortedList();

        void insert(Node<Model>* node);

        void remove(int id);

        void edit(Node<Model>* node);

        Model find(int id);

        void listAll();
};
