#include "sortedList.h"

SortedList::SortedList(Node* value) {
    head = value;
}

~SortedList() {
    Node* cursor = head;
    while(head) {
        cursor = cursor->getNext();
        delete head;
        head = cursor;
    }
    head = 0; // Officially empty
}

void insert(Node* student){
    bool finished = false;
    Node* previousNode = head->prev;
    Node* currentNode = *head;
    if (students->next == nullptr) {
        *head = *student;
    } else {
        while (!finished) {
            if (student->id < currentStudent->id) {
                student->prev = previousStudent;
                student->next = currentStudent;
                previousStudent->next = student;
                currentStudent->prev = student;
            } else {
                if (currentStudent->next == nullptr) {
                    currentStudent->next = student;
                    student->prev = currentStudent;
                    student->next = nullptr;
                } else {
                    previousStudent = currentStudent;
                    currentStudent = currentStudent->next;
                }
            }
        }
    }
}

void remove(Node* students, int id);

void edit(Node* students, Node* student);

void search(Node* students, Node* student);

void listAll(Node* students);
