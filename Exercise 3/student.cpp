#include <iostream>
#include <exception>
#include "student.h"

using namespace std;

#define maximumAbsence 10

Student::Student() {
    id = 0;
    name = "";
    grade1 = 0;
    grade2 = 0;
}

Student::Student(int id) {
	Model::setId(id);
}

Student::~Student() { }

string Student::getName() {
	return name;
}

void Student::setName(string value) {
	name = value;
}

float Student::getGrade1() {
	return grade1; 
}

void Student::setGrade1(float value) {
	grade1 = value; 
}

float Student::getGrade2() {
	return grade2; 
}

void Student::setGrade2(float value) {
	grade2 = value; 
}

float Student::getFinalGrade() {
	float finalGrade = (grade1 + grade2)/2;
	return finalGrade;
}

string Student::toString() {
	string result;
	result = "Name:\t\t" + name + "\n";
    result.append("Matricula:\t" + to_string(id) + "\n");
	result.append("Nota P1:\t" + to_string(grade1) + "\n");
	result.append("Nota P2:\t" + to_string(grade2) + "\n");
    result.append("Nota Final:\t" + to_string(getFinalGrade()) + "\n");
	return result;
}
