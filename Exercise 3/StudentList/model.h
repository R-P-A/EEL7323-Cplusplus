#ifndef MODEL
#define MODEL

#include <iostream>

using namespace std;

class Model {
    protected:
        int id;

    public:
        int getId();
        void setId(int value);
};

#endif          // MODEL
