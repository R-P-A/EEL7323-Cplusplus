#include <iostream>
#include <chrono>
#include "timer.h"

using namespace std;

Timer::Timer() {
	start = chrono::steady_clock();
}

Timer::~Timer() { }

unsigned long int Timer::getStart() {
	return (unsigned long int) start / CLOCKS_PER_SEC;
}

unsigned long int Timer::getNow() {
	now = chrono::steady_clock();
	cout << now << endl;
	cout << start << endl;
	cout << CLOCKS_PER_SEC << endl;
	return (unsigned long int) (now - start) / CLOCKS_PER_SEC;
}