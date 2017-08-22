class Clock {
    protected:
        unsigned int hr, min, sec;
        bool is_pm;
    public:
        Clock (unsigned int h, unsigned int s, unsigned int m, bool pm);
        ~Clock();
        void setClock (unsigned int h, unsigned int m, unsigned int s, bool pm);
        void readClock (unsigned int& h, unsigned int& m, unsigned int& s, bool& pm);
        void advance ();
};

Clock::Clock(unsigned int h, unsigned int m, unsigned int s, bool pm) {
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

Clock::~Clock() { }

void Clock::setClock (unsigned int h, unsigned int m, unsigned int s, bool pm) {
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

void Clock::readClock (unsigned int& h, unsigned int& m, unsigned int& s, bool& pm) {
    h = hr;
    m = min;
    s = sec;
    pm = is_pm;
}

void Clock::advance () {
    sec++;
    if (sec >= 60) {
        sec = 0;
        min++;
        if (min >= 60) {
            min = 0;
            hr++;
            if (hr > 12) {
                hr = 1;
                is_pm = !is_pm;
            }
        }
    }
}
