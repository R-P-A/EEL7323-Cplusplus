#include <iostream>
#include "Model.h"
#include "node.h"

using namespace std;

class SortedList {
    private:
        Node<Model*>* head;
        Node<Model*>* findNode(int id);

    public:
        SortedList();
        ~SortedList();

        bool insert(Model* newModel);

        bool remove(int id);

        void edit(Node<Model*>* node);

        Model* find(int id);

        void listAll();
};
