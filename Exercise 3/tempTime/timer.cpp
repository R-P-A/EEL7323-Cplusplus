#include <iostream>
#include <time.h>
#include "timer.h"

using namespace std;

Timer::Timer() {
	start = clock();
}

Timer::~Timer() { }

unsigned long int Timer::getStart() {
	return (unsigned long int) start / CLOCKS_PER_SEC;
}

unsigned long int Timer::getNow() {
	now = clock();
	return (unsigned long int) (now - start) / CLOCKS_PER_SEC;
}