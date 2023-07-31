#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {

	//displaying student and course info:
	cout << endl;
	cout << "Course Title: Scripting & Programming Applications (C867)" << endl;
	cout << "Language:     C++" << endl;
	cout << "Student ID:   010102183" << endl;
	cout << "Name:         Garrett Yokley" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << endl << endl;

	//student data table:
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Garrett,Yokley,gyokle1@wgu.edu,22,45,25,49,SOFTWARE"
	};

	//creating the instance classRoster of type Roster:
	Roster classRoster;

	//populating classRoster:
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	//displaying all students:
	classRoster.printAll();

	//displaying invalid emails:
	classRoster.printInvalidEmails();

	//displaying avg days in course for all students:
	classRoster.printAverageDaysInCourse();

	//displaying students in degree program: SOFTWARE:
	classRoster.printByDegreeProgram(SOFTWARE);

	//removing student A3:
	//	cout << "Removing a student:\n-------------------\n";
	classRoster.remove("A3");

	//displaying all students again:
	classRoster.printAll();

	//removing A3 again:
	//	cout << "Removing the same student again:\n--------------------------------\n";
	classRoster.remove("A3");

	// The destructor function is called automatically.
	return 0;
}