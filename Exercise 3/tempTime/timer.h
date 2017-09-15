#ifndef TIMER
#define TIMER

#include <iostream>
#include <time.h>

using namespace std;

class Timer {
	private:
		clock_t start, now;

	public:
		Timer();
		~Timer();

		unsigned long int getStart();

		unsigned long int getNow();
};

#endif		// TIMER