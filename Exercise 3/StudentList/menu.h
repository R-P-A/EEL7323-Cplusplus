#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "student.h"
#include "sortedList.h"

class Menu {
    private:
        Student* createStudent();

    public:
        Menu();
        ~Menu();

        bool mainMenu(SortedList* studentList);
        void insertStudent(SortedList* studentList);
        void removeStudent(SortedList* studentList);
        void editStudent(SortedList* studentList);
        void printStudent(SortedList* studentList);
        void listAll(SortedList* studentList);
};

#endif      // MENU_H
