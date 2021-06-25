#pragma once
#include "student.h"
#include "degree.h"
#include <iostream>
#include <vector>

using namespace std;



class Roster {
public:
	const static int arraySize = 5;
	Student* classRosterArray[arraySize]; // array of pointers
	int finalIndex = 0;
	


public:
	

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeType);
	
	void parseStudents();

	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);


	// Destructor

	~Roster();

};
