#include <iostream>
#include <sstream>
#include "sortedList.h"
#include "student.h"
#include "menu.h"
#include "clockCalendar.h"
#include "timer.h"
#include "myString.h"
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
	
bool Menu::mainMenu(SortedList* studentList, ClockCalendar* timeDate, Timer* timer) {
	int option;
	bool cont = true;	// False for exiting the program
	cout << "\n\nChoose one option below to edit the Student List:\n";
	cout << "1. Insert a student\n";
	cout << "2. Remove a student\n";
	cout << "3. Edit a existing student\n";
	cout << "4. Print a student on the screen\n";
	cout << "5. List all student's Ids\n";
	cout << "6. Exit!\n";

	if (!readNumber(option))
		option = -1;

	switch (option) {
		case 1:
			insertStudent(studentList, timeDate, timer);
			break;
		case 2:
			removeStudent(studentList);
			break;
		case 3:
			editStudent(studentList, timeDate, timer);
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
	while (!readNumber(tempInt) || tempInt < 0) {
		cout << "Value not an integer or less than 0. Please try a new value.\n";
	}
	newStudent->setId(tempInt);

	cout << "\nInsert the student's name:\n";
	while (!readString(tempString)) {
		cout << "Value not a valid string. Please try a new value.\n";
	}
	newStudent->setName(tempString);

	cout << "\nInsert the student's first grade:\n";
	while (!readNumber(tempFloat) || !(newStudent->setGrade1(tempFloat))) {
		cout << "Value not a float or out of range (0-10). Please try a new value.\n";
	}

	cout << "\nInsert the student's second grade:\n";
	while (!readNumber(tempFloat) || !(newStudent->setGrade2(tempFloat))) {
		cout << "Value not a float or out of range (0-10). Please try a new value.\n";
	}

	return newStudent;
}

void Menu::insertStudent(SortedList* studentList, ClockCalendar* timeDate, Timer* timer) {
	Student* newStudent = createStudent();
	unsigned long int secs;

	if (studentList->insert(newStudent)) {
		secs = timer->getSecsSinceLastCall();
		for (unsigned long int i = 0; i < secs; i++) {
			timeDate->advance();
		}
		newStudent->setCreationTime(timeDate->toString());
		newStudent->setModificationTime(timeDate->toString());
		cout << "\nStudent inserted with success! o/\n";
	} else {
		cout << "\nFailed to insert new student :(. Check if Id already exists.\n";
		delete newStudent;	// Delete if failed, because this created student won't be used anymore.
	}
}

void Menu::removeStudent(SortedList* studentList) {
	int newId;

	cout << "\nInsert the student Id to remove:\n";
	if (!readNumber(newId))
		newId = -1;

	if (studentList->remove(newId)) {
		cout << "\nStudent removed with success! o/\n";
	} else {
		cout << "\nFailed to remove student :(. Check if student exists\n";
	}
}

void Menu::editStudent(SortedList* studentList, ClockCalendar* timeDate, Timer* timer) {
	cout << "Id of the student to be edited, the other values will be substituted\n";
	Student* newStudent = createStudent();
	unsigned long int secs;

	if (studentList->edit(newStudent)) {
		newStudent->setCreationTime(((Student*) studentList->find(newStudent->getId()))->getCreationTime());
		secs = timer->getSecsSinceLastCall();
		for (unsigned long int i = 0; i < secs; i++) {
			timeDate->advance();
		}
		newStudent->setModificationTime(timeDate->toString());
		cout << "\nStudent edited with success! o/\n";
	} else {
		cout << "\nFailed to edit student :(. Check if student exists\n";
		delete newStudent;	// Delete if failed, because this created student won't be used anymore.
	}
}

void Menu::printStudent(SortedList* studentList) {
	int newId;
	cout << "\nInsert the student Id to print:\n";
	if (!readNumber(newId))
		newId = -1;

	Student* newStudent = (Student*) studentList->find(newId);

	if (newStudent == NULL) {
		cout << "\nFailed to print student :(. Check if student exists\n";
	} else {
		cout << newStudent->toString();
	}
}

void Menu::listAll(SortedList* studentList) {
	cout << "\nListing all students Ids:\n";
	string result = studentList->listAll();
	cout << result;
}
