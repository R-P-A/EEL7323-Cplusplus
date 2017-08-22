class Calendar {
    protected:
        int yr, mo, day;
    public:
        Calendar (unsigned int y, unsigned int m, unsigned int d);
        ~Calendar();
        void setCalendar (unsigned int y, unsigned int m, unsigned int d);
        void readCalendar (unsigned int& y, unsigned int& m, unsigned int& d);
        void advance ();
};

Calendar::Calendar (unsigned int y, unsigned int m, unsigned int d) {
    yr = y;
    mo = m;
    day = d;
}

Calendar::~Calendar() { }

void Calendar::setCalendar (unsigned int y, unsigned int m, unsigned int d) {
    yr = y;
    mo = m;
    day = d;
}

void Calendar::readCalendar (unsigned int& y, unsigned int& m, unsigned int& d){
    y = yr;
    m = mo;
    d = day;
}

void Calendar::advance () {
    day++;
    if (day > 30) {
        day = 1;
        mo++;
        if (mo > 12) {
            mo = 1;
            yr++;
        }
    }
}
