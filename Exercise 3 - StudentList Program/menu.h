/** 
 *	@author  Rafael Pintar Alevato
 *	@date    17/09/2017
 *	@version 1.0 
 *	
 *	@brief Prints out a menu for the studentList exercise
 *
 *	@section DESCRIPTION
 *	
 *	From main menu, it calls other functions that do the basics of a program
 *	that manages students saving the id, name, grades, final grade and time
 *	of creation and of modification.
 */

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
		/**
		 *	Used by inside functions insertStudent and editStudent.
		 *	It creates a new student taking the user input.
		 *	@return	The pointer to the new student created
		 */
		Student* createStudent();

	public:
		Menu();
		~Menu();

		/**
		 *	Prints out the main menu which calls other functions that make the program.
		 *	Use while(mainMenu) to use this function that run the program correctly.
		 *	@param studentList	A sorted list that contains the students
		 *	@param timeDate		Used for saving the students creation and modification time
		 *	@param timer 		Used for calculating the current time
		 *	@return	Wheter the program has ended.
		 */
		bool mainMenu(SortedList* studentList, ClockCalendar* timeDate, Timer* timer);

		void insertStudent(SortedList* studentList, ClockCalendar* timeDate, Timer* timer);

		void removeStudent(SortedList* studentList);

		void editStudent(SortedList* studentList, ClockCalendar* timeDate, Timer* timer);

		/**
		 *	Print all the parameters of a student from the studentList
		 *	@param studentList	A sorted list that contains the students
		 */
		void printStudent(SortedList* studentList);

		/**
		 *	List all students ids
		 *	@param studentList	A sorted list that contains the students
		 */
		void listAll(SortedList* studentList);
};

#endif	  // MENU_H
