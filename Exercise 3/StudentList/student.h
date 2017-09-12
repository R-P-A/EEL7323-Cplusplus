#ifndef STUDENT
#define STUDENT

#include <iostream>
#include "model.h"

using namespace std;

class Student : public Model {
    private:
        string name;
        float grade1;
        float grade2;
        
    public:
        Student();
        Student(int id);
        ~Student();

        string getName();
        void setName(string value);

        float getGrade1();
        void setGrade1(float value);

        float getGrade2();
        void setGrade2(float value);

        float getFinalGrade();

        string toString();
};

#endif          // STUDENT
