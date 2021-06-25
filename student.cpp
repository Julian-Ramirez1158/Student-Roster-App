#include <iostream>
#include "student.h"
#include "degree.h"

using namespace std;




// Getters

string Student::getStudentId() {
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

int Student::getStudentAge() {
	return studentAge;
}

int* Student::getCourseCompletion() { 
	return courseCompletion;
}


DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

// Setters

void Student::setStudentId(string ID) {
	studentID = ID;
}

void Student::setFirstName(string fName) {
	firstName = fName;
}

void Student::setLastName(string lName) {
	lastName = lName;
}

void Student::setEmailAddress(string email) {
	emailAddress = email;
}

void Student::setStudentAge(int age) {
	studentAge = age;
}

void Student::setCourseCompletion(int courseDays[courseDaysArray]) { // array
	courseCompletion[0] = courseDays[0];
	courseCompletion[1] = courseDays[1];
	courseCompletion[2] = courseDays[2];
}


void Student::setDegreeProgram(DegreeProgram program) {
	degreeProgram = program;
}

// Print student info

void Student::printHead() {
	printf("\t%-3s%-15s%-15s%-30s%-6s%-16s%-15s\n", "ID", "First Name", "Last name", "Email address", "Age", "Days in Course", "Degree Program");
}

void Student::printStudentInfo() {
	printf("\t%-3s%-15s%-15s%-30s%-6d%-4d%-4d%-8d%-15s\n", studentID.c_str(), firstName.c_str(), lastName.c_str(), emailAddress.c_str(), studentAge, courseCompletion[0], courseCompletion[1], courseCompletion[2], degreeProgramStrings[(int)degreeProgram].c_str()); 
}

Student::Student(
	string ID,
	string fName,
	string lName,
	string email,
	int age,
	int courseDays[courseDaysArray],
	DegreeProgram program
)
{
	studentID = ID;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	studentAge = age;
	courseCompletion[0] = courseDays[0];
	courseCompletion[1] = courseDays[1];
	courseCompletion[2] = courseDays[2];
	degreeProgram = program;
}


