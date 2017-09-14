#ifndef MODEL
#define MODEL

#include <iostream>
#include <exception>

using namespace std;

class Model {
    protected:
        int id;

    public:
        int getId();
        void setId(int value);
};

#endif          // MODEL
