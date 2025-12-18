#include "student.h"
#include "roster.h"
#include "degree.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const string studentData[] = {
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Marcello,Cirelli,marcellocirelli@gmailcom,28,19,12,31,SOFTWARE",
};

int main() {
	cout << "Student Roster Program\n" << endl
		 << "C867 - Scripting and Programming - Applications\n"
		 << "Language: C++\n"
		 << "Student ID: 012615092\n"
		 << "Name: Marcello Cirelli\n" << endl;

	Roster classRoster;

	for (const string& data : studentData) {
		classRoster.parse(data);
	}

	classRoster.printAll();
	cout << endl;

	classRoster.printInvalidEmails();
	cout << endl;

	for (int i = 0; i < 5; ++i) {
		string studentId = "A" + to_string(i + 1);
		classRoster.printAverageDaysInCourse(studentId);
		cout << endl;
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();
	cout << endl;

	classRoster.remove("A3"); // Error checking

	classRoster.~Roster(); // Destructor
}