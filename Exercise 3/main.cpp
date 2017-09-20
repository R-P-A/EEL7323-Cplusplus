#include <iostream>
#include <exception>
#include "sortedList.h"
#include "student.h"
#include "model.h"
#include "node.h"
#include "menu.h"
#include "clockCalendar.h"
#include "timer.h"
#include "myString.h"
#include "readInput.h"

#define brazilTime 3*60*60;

using namespace std;

int main() {
	SortedList* studentList = new SortedList();
	ClockCalendar* timeDate = new ClockCalendar(1970, 1, 1, 0, 0, 0, false);	// Epoch date
	Timer* timer = new Timer();
	bool cont = true;
	Menu* menu = new Menu();

	unsigned long int secs;

	cout << "\nPlease wait... Calculating currente time and date.\n";
	secs = timer->getSecsSince1970() - brazilTime;
	for (unsigned long int i = 0; i < secs; i++) {
		timeDate->advance();
	}
	// Correction due to long iterations above
	secs = timer->getSecsSinceLastCall();
	for (unsigned long int i = 0; i < secs; i++) {
		timeDate->advance();
	}
	cout << "Currente time and date is: " << timeDate->toString() << endl;

	while (cont) {
		cont = menu->mainMenu(studentList, timeDate, timer);
	}

	delete timeDate;
	delete timer;
	delete menu;
	delete studentList;
	return 0;
}