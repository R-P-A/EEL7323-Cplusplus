#include "calendar.h"

Calendar::Calendar (unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Calendar::~Calendar() { }

void Calendar::setCalendar (unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

void Calendar::readCalendar (unsigned int& year, unsigned int& month, unsigned int& day){
    year = this->year;
    month = this->month;
    day = this->day;
}

void Calendar::advance () {
    day++;
    if (day > 30) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}
