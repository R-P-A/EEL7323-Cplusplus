#ifndef CALENDAR
#define CALENDAR

class Calendar {
	protected:
		int year, month, day;
	public:
		Calendar (unsigned int year, unsigned int month, unsigned int day);
		~Calendar();
		
		void setCalendar (unsigned int year, unsigned int month, unsigned int day);
		/** Get the 3 parameters */
		void readCalendar (unsigned int& year, unsigned int& month, unsigned int& day);

		/** Advances the calendar in one day */
		void advance ();
};

#endif		// CALENDAR