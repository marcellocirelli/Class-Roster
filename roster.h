#ifndef ROSTER_H  
#define ROSTER_H  

#include "student.h"  
#include "degree.h"  
#include <iostream>  
#include <string>  
using namespace std;  

class Roster {  
private:  
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr }; // Initializes array elements to nullptr  
	int rosterIndex = 0;  
public:  
	void parse(string studentDataRow);  
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);  
	void remove(string studentID);  
	void printAll() const;  
	void printAverageDaysInCourse(string studentID) const;  
	void printInvalidEmails() const;  
	void printByDegreeProgram(DegreeProgram degreeProgram) const;  
	~Roster();  
};  

#endif // ROSTER_H