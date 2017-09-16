#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <exception>
#include "sortedList.h"
#include "student.h"
#include "readInput.h"
#include "clockCalendar.h"
#include "timer.h"

using namespace std;

class Menu {
	private:
		Student* createStudent();

	public:
		Menu();
		~Menu();

		bool mainMenu(SortedList* studentList, ClockCalendar* timeDate, Timer* timer);
		void insertStudent(SortedList* studentList, ClockCalendar* timeDate, Timer* timer);
		void removeStudent(SortedList* studentList);
		void editStudent(SortedList* studentList, ClockCalendar* timeDate, Timer* timer);
		void printStudent(SortedList* studentList);
		void listAll(SortedList* studentList);
};

#endif	  // MENU_H
