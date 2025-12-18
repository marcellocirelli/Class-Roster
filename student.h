#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	// Constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	// Accessors
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	const int* getDaysInCourse() const;
	DegreeProgram getDegreeProgram() const;
	// Mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int day1, int day2, int day3);
	void setDegreeProgram(DegreeProgram degreeProgram);
	// Print function
	void print() const;
};


#endif // !STUDENT_H
