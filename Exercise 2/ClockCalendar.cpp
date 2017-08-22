#include "Clock.cpp"
#include "Calendar.cpp"

class ClockCalendar : public Clock, public Calendar {
    public:
        ClockCalendar (unsigned int y, unsigned int mt, unsigned int d, unsigned int h, unsigned int m, unsigned int s, bool pm);
        ~ClockCalendar ();
        void advance ();
};

ClockCalendar::ClockCalendar (unsigned int y, unsigned int mt, unsigned int d, unsigned int h, unsigned int m, unsigned int s, bool pm)
    : Clock (h, m, s, pm), Calendar (y, mt, d) {

}

ClockCalendar::~ClockCalendar () { }

void ClockCalendar::advance () {
    bool wasPm = Clock::is_pm; // save current pm.
    Clock::advance();
    if ((wasPm == true) && (Clock::is_pm == false))
        Calendar::advance();
}
