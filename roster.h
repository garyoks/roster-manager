#pragma once
#include <iostream>
#include "student.h"

class Roster {
public:
	//members
	static int addIndex;
	Student* classRosterArray[5];

	//methods
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse();
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};