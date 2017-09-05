#include "studentsList.h"

StudentsList::StudentsList(Student* list) {
    head = value;
}

~StudentsList() { }

Student* getHead() {
    return head;
}

void insert(Student* student){
    bool finished = false;
    Student* previousStudent = head->prev;
    Student* currentStudent = *head;
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

void remove(Student* students, int id);

void edit(Student* students, Student* student);

void search(Student* students, Student* student);

void listAll(Student* students);
