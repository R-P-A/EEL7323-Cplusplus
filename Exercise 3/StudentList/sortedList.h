#ifndef SORTEDLIST
#define SORTEDLIST

#include <iostream>
#include "model.h"
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

        bool edit(int id, Model* modifiedModel);

        Model* find(int id);

        void listAll();
};

#endif          // SORTEDLIST
