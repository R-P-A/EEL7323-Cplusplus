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

		/** Advances the clock in one second and if needed (with isPM variable) advances the calendar in one day */
		void advance ();

		/** Print in a string the date and time */
		string toString();
};

#endif		// CLOCKCALENDAR