#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

//default constructor:
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = 0;
	}
	this->degreeProgram = DegreeProgram{};
}

//constructor to be called in Roster::add :
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysToComplete, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

//getters:
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getDaysToComplete() {
	return this->daysToComplete;
}
DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}


//setters:
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


//print:
void Student::print() {
	cout << this->getStudentID() << "\t"
		<< this->getFirstName() << "\t"
		<< this->getLastName() << "\t"
		<< this->getEmailAddress() << "\t"
		<< this->getAge() << "\t";

	cout << "{ ";
	for (int i = 0; i < 3; i++) {
		cout << this->getDaysToComplete()[i];
		if (i < 2) {
			cout << ", ";
		}
	}
	cout << " }\t";

	if (this->degreeProgram == SECURITY) {
		cout << "SECURITY";
	}
	else if (this->degreeProgram == NETWORK) {
		cout << "NETWORK";
	}
	else if (this->degreeProgram == SOFTWARE) {
		cout << "SOFTWARE";
	}
	cout << endl;
}