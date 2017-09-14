#include <iostream>
#include <exception>
#include "sortedList.h"
#include "student.h"
#include "menu.h"
#include "readInput.h"

using namespace std;

Menu::Menu() {
    cout << "\nHi!\n";
    cout << "Welcome to our Student List App";
}

Menu::~Menu() {
    cout << "\nGodspeed my friend!\n";
    cout << "We shall see you again!\n\n";
}

bool Menu::mainMenu(SortedList* studentList) {
    int option;
    bool cont = true;
    cout << "\n\nChoose one option below to edit the Student List:\n";
    cout << "1. Insert a student\n";
    cout << "2. Remove a student\n";
    cout << "3. Edit a existing student\n";
    cout << "4. Print a student on the screen\n";
    cout << "5. List all student's Ids\n";
    cout << "6. Exit!\n";

    if (!readInt(option))
        option = -1;

    switch (option) {
        case 1:
            insertStudent(studentList);
            break;
        case 2:
            removeStudent(studentList);
            break;
        case 3:
            editStudent(studentList);
            break;
        case 4:
            printStudent(studentList);
            break;
        case 5:
            listAll(studentList);
            break;
        case 6:
            cont = false;
            break;
        default:
            cout << "Invalid operation, please try again\n";
            break;
    }
    return cont;
}

Student* Menu::createStudent() {
    Student* newStudent = new Student();
    int tempInt;
    float tempFloat;
    string tempString;

    cout << "\nInsert the student's Id:\n";
    while (!readInt(tempInt) || tempInt < 0) {
        cout << "Value not an integer or less than 0. Please try a new value.\n";
    }
    newStudent->setId(tempInt);

    cout << "\nInsert the student's name:\n";
    while (!readString(tempString)) {
        cout << "Value not a valid string. Please try a new value.\n";
    }
    newStudent->setName(tempString);

    cout << "\nInsert the student's first grade:\n";
    while (!readFloat(tempFloat) || !(newStudent->setGrade1(tempFloat))) {
        cout << "Value not a float or out of range (0-10). Please try a new value.\n";
    }

    cout << "\nInsert the student's second grade:\n";
    while (!readFloat(tempFloat) || !(newStudent->setGrade2(tempFloat))) {
        cout << "Value not a float or out of range (0-10). Please try a new value.\n";
    }

    return newStudent;
}

void Menu::insertStudent(SortedList* studentList) {
    Student* newStudent = new Student();
    newStudent = createStudent();

    if (studentList->insert(newStudent)) {
        cout << "\nStudent inserted with success! o/\n";
    } else {
        cout << "\nFailed to insert new student :(. Check if Id already exists.\n";
        delete newStudent;
    }
}

void Menu::removeStudent(SortedList* studentList) {
    int newId;
    cout << "\nInsert the student Id to remove:\n";
    if (!readInt(newId))
        newId = -1;

    if (studentList->remove(newId)) {
        cout << "\nStudent removed with success! o/\n";
    } else {
        cout << "\nFailed to remove student :(. Check if student exists\n";
    }
}

void Menu::editStudent(SortedList* studentList) {
    Student* newStudent = new Student();
    newStudent = createStudent();

    if (studentList->edit(newStudent)) {
        cout << "\nStudent edited with success! o/\n";
    } else {
        cout << "\nFailed to edit student :(. Check if student exists\n";
        delete newStudent;
    }
}

void Menu::printStudent(SortedList* studentList) {
    int newId;
    cout << "\nInsert the student Id to print:\n";
    if (!readInt(newId))
        newId = -1;

    Student* newStudent = new Student();
    newStudent = (Student*) studentList->find(newId);

    if (newStudent == NULL) {
        cout << "\nFailed to print student :(. Check if student exists\n";
        delete newStudent;
    } else {
        cout << newStudent->toString();
    }
}

void Menu::listAll(SortedList* studentList) {
    cout << "\nListing all students Ids:\n";
    studentList->listAll();
}
