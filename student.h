#pragma once
#include <iostream>
#include "degree.h"


using namespace std;

class Student {

public: 
	const static int courseDaysArray = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge; // could be string because no arithmetic operation is performed on this number
	int courseCompletion[3]; // create array for days (remains int)
	DegreeProgram degreeProgram;
	

public:

	// Full constructor

	Student(
		string ID,
		string fName,
		string lName,
		string email,
		int age,
		int courseDays[courseDaysArray],
		DegreeProgram program
	);
	


	// Getters
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int* getCourseCompletion();
	DegreeProgram getDegreeProgram();

	// Setters

	void setStudentId(string ID);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmailAddress(string email);
	void setStudentAge(int age);
	void setCourseCompletion(int[courseDaysArray]);
	void setDegreeProgram(DegreeProgram program);
	static void printHead();
	void printStudentInfo();
};
