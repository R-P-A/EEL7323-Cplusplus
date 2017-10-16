#include "clockCalendar.h"
#include <iostream>
#include <time.h>

using namespace std;

bool timeOneSecond (time_t* timeStart, time_t* timeNow, double* oldElapsed);

int main()
{
	bool secondAdvanced = false;
	ClockCalendar cc (2017, 8, 29, 07, 15, 30, true);
	double oldElapsed = 0;
	time_t timeStart, timeNow;

	time(&timeStart);

	while (true) {
		secondAdvanced = timeOneSecond(&timeStart, &timeNow, &oldElapsed);
		if (secondAdvanced) {
			secondAdvanced = false;
			cc.advance();
			cout << cc.toString() << endl;
		}
	}
	return 0;
}

bool timeOneSecond (time_t* timeStart, time_t* timeNow, double* oldElapsed) {
	bool secondAdvanced = false;
	double elapsed;
	while (!secondAdvanced) {
		time(timeNow);
		elapsed = difftime(*timeNow, *timeStart);
		if (elapsed > *oldElapsed) {
			secondAdvanced = true;
		}
	}
	*oldElapsed = elapsed;
	return secondAdvanced;
}
