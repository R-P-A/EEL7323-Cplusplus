#include <iostream>

using namespace std;

class Student {
	private:
		string name;
		string id;
		float grade1;
		float grade2;
		int absence;
		
	public:
		Student();
		~Student();

		string getName();
		void setName(string value);

		string getId();
		void setId(string value);

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