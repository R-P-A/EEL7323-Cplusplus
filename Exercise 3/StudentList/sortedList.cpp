#include "sortedList.h"

SortedList::SortedList() {
    head = NULL;
}

SortedList::~SortedList() {
    Node<Model*>* currentNode = head;
    while (head != NULL) {
        currentNode = currentNode->getNext();
        delete head;
        head = currentNode;
    }
    head = NULL; // Officially empty
}

bool SortedList::insert(Model* newModel) {
    if (newModel == NULL) {
        return false;
    }

    if (head == NULL) {
        head = new Node<Model*>(newModel);
        return true;
    }
    
    Node<Model*>* currentNode = head;
    int targetId = newModel->getId();

    while (currentNode != NULL) {

        int currentId = currentNode->getData()->getId();
        
        if (currentId == targetId) {
            return false;
        }

        if (currentId > targetId) {
            Node<Model*>* newNode = new Node<Model*>(newModel);
            Node<Model*>* prevNode = currentNode->getPrev();
            if (prevNode != NULL) {
                prevNode->setNext(newNode);
            } else {
                head = newNode;
            }
            currentNode->setPrev(newNode);
            return true;
        }
        if (currentNode->getNext() == NULL) {
            currentNode->setNext(new Node<Model*>(newModel));
            return true;
        }
        currentNode = currentNode->getNext();        
    }
     return false;           //Sanity check
}

bool SortedList::remove(int id) {
    Node<Model*>* trashNode = findNode(id);
    if (trashNode != NULL) {
        Node<Model*>* nextNode = trashNode->getNext();
        Node<Model*>* prevNode = trashNode->getPrev();
        if (nextNode != NULL) {
            nextNode->setPrev(prevNode);
            if (prevNode == NULL) {
                head = nextNode;
            }
        }
        if (prevNode != NULL) {
            prevNode->setNext(nextNode);
        }
        if (trashNode == head) {
            head = NULL;
        }
        delete trashNode;
        return true;
    }
    return false;
}

bool SortedList::edit(int id, Model* modifiedModel) {
    Node<Model*>* nodeToModify = findNode(id);
    if (nodeToModify == NULL) {
        return false;
    }
    nodeToModify->setData(modifiedModel);
    return true;
}

Node<Model*>* SortedList::findNode(int id) {
    Node<Model*>* currentNode = head;
    while (currentNode != NULL) {
        int currentId = currentNode->getData()->getId();
        if (currentId == id) {
            return currentNode;
        }
        if (currentId > id) {
            return NULL;
        }
        currentNode = currentNode->getNext();
    }
    return NULL;
}

Model* SortedList::find(int id) {
    Node<Model*>* node = findNode(id);
    if (node != NULL) {
        return node->getData();
    }
    return NULL;
}

void SortedList::listAll() {
    Node<Model*>* currentNode = head;
    while (currentNode != NULL) {
        cout << currentNode->getData()->getId() << endl;
        currentNode = currentNode->getNext();
    }
    cout << endl;
}
