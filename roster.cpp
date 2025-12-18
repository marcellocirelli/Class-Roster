#include "roster.h"
#include "student.h"
#include "degree.h"

#include <regex>
#include <sstream>
using namespace std;

void Roster::parse(string studentDataRow) {
	stringstream ss(studentDataRow);
	string studentID, firstName, lastName, email, ageStr, day1Str, day2Str, day3Str, degreeStr;

	// Parse the student data from the stringstream
	getline(ss, studentID, ',');
	getline(ss, firstName, ',');
	getline(ss, lastName, ',');
	getline(ss, email, ',');
	getline(ss, ageStr, ',');
	getline(ss, day1Str, ',');
	getline(ss, day2Str, ',');
	getline(ss, day3Str, ',');
	getline(ss, degreeStr, ',');

	// Convert strings to ints where necessary
	int ageInt = stoi(ageStr);
	int day1Int = stoi(day1Str);
	int day2Int = stoi(day2Str);
	int day3Int = stoi(day3Str);

	// Determine the degree program and convert it to the enum type
	DegreeProgram degreeProgram{};
	if (degreeStr == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (degreeStr == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (degreeStr == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}
	add(studentID, firstName, lastName, email, ageInt, day1Int, day2Int, day3Int, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	classRosterArray[rosterIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse[0], daysInCourse[1], daysInCourse[2], degreeProgram);
	rosterIndex++;
}

void Roster::remove(string studentID) {
	for (int i = 0; i < rosterIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			// shifts remaining students down
			for (int j = i; j < rosterIndex - 1; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			// Set the last element to nullptr and decrement rosterIndex
			classRosterArray[rosterIndex - 1] = nullptr;
			rosterIndex--;
			return;
		}
	}
	cout << "Error: Student ID " << studentID << " not found." << endl;
}

void Roster::printAll() const {
	for (int i = 0; i < rosterIndex; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) const {
	for (int i = 0; i < rosterIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			const int* daysInCourse = classRosterArray[i]->getDaysInCourse();
			int averageDays = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
			cout << "Average days in course for student ID " << studentID << ": " << averageDays << endl;
			return;
		}
	}
	cout << "Error: Student ID " << studentID << " not found." << endl;
}

void Roster::printInvalidEmails() const {
	regex emailPattern(R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)");

	for (int i = 0; i < rosterIndex; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if (!regex_match(email, emailPattern)) {
			cout << "Invalid email: " << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
	for (int i = 0; i < rosterIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < rosterIndex; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}