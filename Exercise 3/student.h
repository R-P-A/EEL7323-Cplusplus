#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <exception>
#include "model.h"

using namespace std;

class Student : public Model {
	private:
		string name;
		float grade1;
		float grade2;
		string creationTime;
		string modificationTime;
		
	public:
		Student();
		Student(int id);
		~Student();

		string getName();
		void setName(string value);

		float getGrade1();
		bool setGrade1(float value);

		float getGrade2();
		bool setGrade2(float value);

		string getCreationTime();
		void setCreationTime(string value);

		string getModificationTime();
		void setModificationTime(string value);

		float getFinalGrade();

		string toString();
};

#endif		  // STUDENT
