#include "sortedList.h"

SortedList::SortedList() {
    head = NULL;
}

SortedList::~SortedList() {
    Node<Model>* cursor = head;
    while (head != NULL) {
        cursor = cursor->getNext();
        delete head;
        head = cursor;
    }
    head = NULL; // Officially empty
}

bool SortedList::insert(Model newModel) {
    // Use only if Model*
    // if (newModel == NULL) {
    //     return false;
    // }

    if (head == NULL) {
        head = new Node<Model>(newModel);
        return true;
    }
    
    Node<Model>* currentNode = head;
    int targetId = newModel.getId();

    while (currentNode != NULL) {

        int currentId = currentNode->getData().getId();
        
        if (currentId == targetId) {
            return false;
        }

        if (currentId > targetId) {
            Node<Model>* newNode = new Node<Model>(newModel);
            Node<Model>* prevNode = currentNode->getPrev();
            if (prevNode != NULL) {
                prevNode->setNext(newNode);
            } else {
                head = newNode;
            }
            currentNode->setPrev(newNode);
            return true;
        }
        if (currentNode->getNext() == NULL) {
            currentNode->setNext(new Node<Model>(newModel));
            return true;
        }
        currentNode = currentNode->getNext();        
    }
     return false;           //Sanity check
}

void SortedList::remove(int id) {
    
}

void SortedList::edit(Node<Model>* node){}

Model SortedList::find(int id){}

void SortedList::listAll() {
    Node<Model>* cursor = head;
    while (cursor != NULL) {
        cout << cursor->getData().getId() << endl;
        cursor = cursor->getNext();
    }
}
