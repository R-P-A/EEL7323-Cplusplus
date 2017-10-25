#ifndef MYTIME
#define MYTIME

#include <time.h>
#include <iostream>

using namespace std;

#define CLOCKS_PER_MS 1000

/** Generate a delay of time ms */ 
void delayms(clock_t time);

/** Generate a delay of time us */ 
void delayus(clock_t time);

#endif	// MYTIME