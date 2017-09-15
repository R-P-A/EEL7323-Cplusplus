#include <iostream>
#include <chrono>
#include "clockCalendar.h"
#include "timer.h"

using namespace std;

bool timeOneSecond (time_t* timeStart, time_t* timeNow, double* oldElapsed);

int main()
{
    ClockCalendar cc (2017, 8, 29, 07, 15, 30, true);

    Timer timer;
    unsigned long int secondsSinceStart;

    cout << "Starting time:\n";
    cout << timer.getStart() << endl;

    while (true) {
        cout << "\ntype anything to print current time:\n";
        getchar();
        getchar();
        secondsSinceStart = timer.getNow();
        cout << secondsSinceStart << endl;
        for (unsigned long int i = 0; i < secondsSinceStart; i++) {
            cc.advance();
        }
        cout << cc.toString();
    }
    return 0;
}