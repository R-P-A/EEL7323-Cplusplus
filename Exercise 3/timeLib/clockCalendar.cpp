#include <iostream>
#include "clockCalendar.h"

using namespace std;

ClockCalendar::ClockCalendar (unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM)
	: Clock (hour, min, sec, isPM), Calendar (year, month, day) {

}

ClockCalendar::~ClockCalendar () { }

void ClockCalendar::advance () {
	bool wasPm = Clock::isPM; // save current pm.
	Clock::advance();
	if ((wasPm == true) && (Clock::isPM == false))
		Calendar::advance();
}

string ClockCalendar::toString() {
	unsigned int year, month, day, hour, min, sec;
	bool isPM;
	string result;

	Calendar::readCalendar(year, month, day);
	Clock::readClock(hour, min, sec, isPM);

	result = to_string(year) + "/" + to_string(month) + "/" + to_string(day) + " - ";
	result.append(to_string(hour) + ":" + to_string(min) + ":" + to_string(sec));
	if (isPM)
		result.append(" pm");
	else
		result.append(" am");
	return result;

}
