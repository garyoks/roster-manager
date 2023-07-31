#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"

int Roster::addIndex = 0;

void Roster::parse(string row) {
	size_t rhs = row.find(","); // only one parameter here assumes starting at index 0
	string studentID = row.substr(0, rhs); // first parameter is where the substring starts, the second parameter is the amount of indicies included in the substring

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs); //adding a second parameter here to tell row.find where to start looking again(1 index to the right of the first comma)
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string degree = row.substr(lhs, rhs - lhs);
	DegreeProgram degreeProgram{};
	if (degree == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (degree == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (degree == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	addIndex++;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[addIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
}

void Roster::remove(string studentID) {
	cout << "Remvoing student '" << studentID << "':\n----------------------\n";
	bool foundID = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;								// Setting the deleted element to nullptr.
				foundID = true;												// I went through all the methods in Roster and added a nullptr checker
				cout << "Student '" << studentID << "' has been removed.\n";
				break;
			}
		}
	}
	if (foundID == false)
	{
		cout << "Student with ID '" << studentID << "' was not found.\n";
	}
	cout << endl << endl;
}

void Roster::printAll() {
	cout << "Displaying all students:\n------------------------\n";
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << endl << endl;
}

void Roster::printAverageDaysInCourse() {
	cout << "Displaying average days in course for each student:\n---------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			Student* student = classRosterArray[i];
			int* daysInCourse = student->getDaysToComplete();
			int sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += daysInCourse[j];
			}
			int average = (sum) / 3;		//this is the way the example output provided looked, just an integer rounded.
			cout << "Student ID '" << student->getStudentID() << "': Average days in course = " << average << std::endl;
		}
	}
	cout << endl << endl;
}

// valid emails include:
// an '@' symbol with text before and after it
// a '.' somewhere after the '@' symbol, with text between the '@' and the '.', and with text after the '.'
// have no spaces
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:\n--------------------------\n";
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->getEmailAddress();

			bool isValid = true;
			if (email.find(' ') != string::npos) { //npos (no position) means not found
				isValid = false;
			}
			else {
				size_t atPosition = email.find('@');
				if (atPosition == string::npos || atPosition == 0 || atPosition == email.length() - 1) {
					isValid = false;
				}
				else {
					size_t dotPosition = email.find('.', atPosition);
					if (dotPosition == string::npos || dotPosition == atPosition + 1 || dotPosition == email.length() - 1) {
						isValid = false;
					}
				}
			}

			if (isValid == false) {
				cout << email << " - is invalid." << std::endl;
			}
		}
	}
	cout << endl << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string degree = "";
	if (degreeProgram == SECURITY) {
		degree = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degree = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degree = "SOFTWARE";
	}
	cout << "Displaying all students in degree program '" << degree << "'\n----------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
			{
				classRosterArray[i]->print();
			}
		}
	}
	cout << endl << endl;
}

//destructor: (no return type)
Roster::~Roster() {
	// Deallocate memory for each Student object in the array
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i]; // Delete the Student object to free memory
		classRosterArray[i] = nullptr; // Set the pointer to nullptr
	}
	cout << "DONE";
	cout << endl << endl;
}