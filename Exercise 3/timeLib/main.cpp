#include <iostream>
#include <chrono>
#include "clockCalendar.h"
#include "timer.h"

#define brazilTime 3*60*60

using namespace std;

bool timeOneSecond (time_t* timeStart, time_t* timeNow, double* oldElapsed);

int main()
{
	ClockCalendar cc (1970, 1, 1, 0, 0, 0, false);
	cout << cc.toString() << endl;
	cout << "Please wait... Calculating time since Epoch!\n";

	Timer timer;
	unsigned long int secs;

	secs = timer.getSecsSince1970() - brazilTime;
	for (unsigned long int i = 0; i < secs; i++) {
		cc.advance();
	}
	cout << cc.toString() << endl;

	while (true) {
		cout << "\nType anything to print current time:\n";
		getchar();
		getchar();
		secs = timer.getSecsSinceLastCall();
		for (unsigned long int i = 0; i < secs; i++) {
			cc.advance();
		}
		cout << cc.toString();
	}
	return 0;
}