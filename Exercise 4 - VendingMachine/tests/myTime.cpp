#include "myTime.h"

void delayms(clock_t time) {
	clock_t start_time = clock()/CLOCKS_PER_MS;
	clock_t end_time = time + start_time;
	while (clock()/CLOCKS_PER_MS <= end_time);
}

void delayus(clock_t time) {
	clock_t start_time = clock();
	clock_t end_time = time + start_time;
	while (clock() <= end_time);
}