#ifndef CLOCKCALENDAR
#define CLOCKCALENDAR

#include <iostream>
#include "clock.h"
#include "calendar.h"

using namespace std;

class ClockCalendar : public Clock, public Calendar {
	public:
		ClockCalendar (unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM);
		~ClockCalendar ();
		void advance ();
		string toString();
};

#endif		// CLOCKCALENDAR