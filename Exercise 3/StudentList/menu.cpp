#include "menu.h"

using namespace std;

Menu::Menu() {
    cout << "Hi!\n";
    cout << "Welcome to our Student List App\n\n";
}

Menu::~Menu() {
    cout << "\n\nGodspeed my friend!\n";
    cout << "We shall see you again! >:-|\n\n";
}

bool Menu::mainMenu(SortedList* studentList) {
    int menuOption = 0;
    bool cont = true;
    cout << "\n\nChoose one option below to edit the Student List:\n";
    cout << "1. Insert a student\n";
    cout << "2. Remove a student\n";
    cout << "3. Edit a existing student\n";
    cout << "4. Print a student on the screen\n";
    cout << "5. List all student's IDs\n";
    cout << "6. Exit!\n\n";
    cin >> menuOption;

    switch (menuOption) {
        case 1:
            this->insertStudent(studentList);
            break;
        case 2:
            this->removeStudent(studentList);
            break;
        case 3:
            this->editStudent(studentList);
            break;
        case 4:
            this->printStudent(studentList);
            break;
        case 5:
            this->listAll(studentList);
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
    float tempFloat;
    string tempString;

    cout << "\nInsert the student's ID:\n";
    cin >> tempInt;
    newStudent->setId(tempInt);

    cout << "\nInsert the student's name:\n";
    getchar();
    getline(cin, tempString);
    newStudent->setName(tempString);

    cout << "\nInsert the student's first grade:\n";
    cin >> tempFloat;
    newStudent->setGrade1(tempFloat);

    cout << "\nInsert the student's second grade:\n\n";
    cin >> tempFloat;
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
    int newID;
    cout << "Insert the student ID to remove:\n";
    cin >> newID;

    if (studentList->remove(newID)) {
        cout << "Student removed with success!\n";
    } else {
        cout << "Student don't exist\n";
    }
}

void Menu::editStudent(SortedList* studentList) {
    int newID;
    cout << "Insert the student ID to remove:\n";
    cin >> newID;

    Student* newStudent = new Student();
    newStudent = createStudent();

    if (studentList->edit(newID, newStudent)) {
        cout << "Success!\n";
    } else {
        cout << "Student don't exist\n";
    }
    delete newStudent;
}

void Menu::printStudent(SortedList* studentList) {
    int newID;
    cout << "Insert the student ID to remove:\n";
    cin >> newID;

    Student* newStudent = new Student();
    newStudent = (Student*) studentList->find(newID);

    if (newStudent == NULL) {
        cout << "Student don't exist\n";
    } else {
        cout << newStudent->toString();
    }
    delete newStudent;
}

void Menu::listAll(SortedList* studentList) {
    cout << "Listing all students IDs:\n";
    studentList->listAll();
}
