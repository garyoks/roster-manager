#pragma once
#include <iostream>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Student {
private:
	//members:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	//constructors:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysToComplete, DegreeProgram degreeProgram);

	//getters:
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//setters:
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmailAddress(string);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//print:
	void print();
};