#include <iostream>
#include <exception>
#include "sortedList.h"
#include "student.h"
#include "menu.h"
#include "readInput.h"

using namespace std;

Menu::Menu() {
    cout << "Hi!\n";
    cout << "Welcome to our Student List App";
}

Menu::~Menu() {
    cout << "\n\nGodspeed my friend!\n";
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
            cout << "Invalid operation, please try again\n\n";
            break;
    }
    return cont;
}

Student* Menu::createStudent() {
    Student* newStudent = new Student();
    int tempInt;
    char tempChar;
    float tempFloat;
    string tempString;

    cout << "\nInsert the student's Id:\n";
    if (!readInt(tempInt))
        tempInt = -1;
    newStudent->setId(tempInt);

    cout << "\nInsert the student's name:\n";
    if (!readString(tempString))
        tempString = "Failed";
    newStudent->setName(tempString);

    cout << "\nInsert the student's first grade:\n";
    if (!readFloat(tempFloat))
        tempFloat = -1;
    newStudent->setGrade1(tempFloat);

    cout << "\nInsert the student's second grade:\n";
    if (!readFloat(tempFloat))
        tempFloat = -1;
    newStudent->setGrade2(tempFloat);

    cout << newStudent->toString();

    return newStudent;
}

void Menu::insertStudent(SortedList* studentList) {
    Student* newStudent = new Student();
    newStudent = createStudent();
    if (studentList->insert(newStudent)) {
        cout << "Success!\n";
    } else {
        cout << "Failure :(\n";
    }
}

void Menu::removeStudent(SortedList* studentList) {
    int newId;
    cout << "\nInsert the student Id to remove:\n";
    if (!readInt(newId))
        newId = -1;

    if (studentList->remove(newId)) {
        cout << "Student removed with success!\n";
    } else {
        cout << "Student don't exist\n";
    }
}

void Menu::editStudent(SortedList* studentList) {
    Student* newStudent = new Student();
    newStudent = createStudent();

    if (studentList->edit(newStudent)) {
        cout << "Success!\n";
    } else {
        cout << "Student don't exist\n";
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
        cout << "Student don't exist\n";
    } else {
        cout << newStudent->toString();
    }
    delete newStudent;
}

void Menu::listAll(SortedList* studentList) {
    cout << "\nListing all students Ids:\n";
    studentList->listAll();
}
