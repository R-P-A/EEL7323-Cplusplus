#include <iostream>

using namespace std;

class Student {
    private:
        int id;
        string name;
        float grade1;
        float grade2;
        int absence;
        Student* next;
        Student* prev;
        
    public:
        Student();
        ~Student();

        int getId();
        void setId(int value);

        string getName();
        void setName(string value);

        float getGrade1();
        void setGrade1(float value);

        float getGrade2();
        void setGrade2(float value);

        float getFinalGrade();

        int getAbsence();
        void setAbsence(int value);

        bool isInsufficientFrequency();

        string toString();
};
