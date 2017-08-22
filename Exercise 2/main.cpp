#include "ClockCalendar.cpp"
#include <iostream>

using namespace std;

int main()
{
    bool secondAdvanced = false;
    ClockCalendar cc (2017, 12, 30, 12, 59, 58, true);
    unsigned int year, month, day, hour, minute, second;

    bool isPM;
    while (true) {
        cin >> secondAdvanced;
        if (secondAdvanced) {
            secondAdvanced = false;
            cc.advance();
            cc.readCalendar(year, month, day);
            cc.readClock(hour, minute, second, isPM);
            cout << "Year: " << year << endl;
            cout << "Month: " << month << endl;
            cout << "Day: " << day << endl;
            cout << "Hour: " << hour << endl;
            cout << "Minute: " << minute << endl;
            cout << "Second: " << second << endl;
            cout << "isPM: " << isPM << endl;
        }
    }
    return 0;
}
