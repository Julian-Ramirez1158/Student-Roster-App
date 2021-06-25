#include <sstream>
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"



using namespace std;

const string studentData[5] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Julian,Ramirez,jram417@wgu.edu,27,31,40,35,SOFTWARE"
};


void Roster::parseStudents() {



	// for loop
	int counterElement = 0;
	string studentElement = "";
	for (counterElement = 0; counterElement < 5; counterElement++) {
	
		string studentInfo[9];

		int counterColumn = 0;
		int posData = 0;
		int offSetData = 0;
		studentElement = studentData[counterElement];

	
		while (counterColumn < 9) {
			posData = studentElement.find(',', offSetData);
			studentInfo[counterColumn] = studentElement.substr(offSetData, posData - offSetData);
			offSetData = posData + 1;
			counterColumn++;
		}

		DegreeProgram degreeEnum;
		auto degreeKey = enumMap.find(studentInfo[8]);
		if (degreeKey != enumMap.end()) {
			degreeEnum = degreeKey->second;
		}

		add(studentInfo[0], // ID
			studentInfo[1], // fname	
			studentInfo[2], // lname
			studentInfo[3], // email
			stoi(studentInfo[4]), // age
			stoi(studentInfo[5]), // day1
			stoi(studentInfo[6]), // day2
			stoi(studentInfo[7]), // day 3
			degreeEnum // enum program
		);
	}


}

void Roster::add(string studentID, 
				string firstName, 
				string lastName, 
				string emailAddress, 
				int age, 
				int daysInCourse1, int daysInCourse2, int daysInCourse3, 
				DegreeProgram degreeType) {

	const static int courseDaysArraySize = 3;
	int courseDays[courseDaysArraySize] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[finalIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeType);
	
}

void Roster::remove(string studentID) {
	cout << "Removing student by ID: " << studentID << endl;
	bool studentFound = false;
	int i = 0;
	for (i = 0; i < finalIndex; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
			classRosterArray[i] = nullptr;
			studentFound = true;
		}
	}
	if (!studentFound) {
		cout << "\tError! Student with ID " << studentID << " was not found in the roster." << endl;
	}
	
	cout << endl;


}

void Roster::printAll() {
	int i = 0;
	 
	cout << "All students: " << endl;
	Student::printHead();
	for (i = 0; i < finalIndex; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->printStudentInfo();
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	int i = 0;
	int* courseCompletion;
	for (i = 0; i < finalIndex; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
			courseCompletion = classRosterArray[i]->getCourseCompletion(); 
			float averageDays = (float(courseCompletion[0]) + float(courseCompletion[1]) + float(courseCompletion[2])) / 3.00;
			cout << "\tFor student " << studentID << ": " << averageDays << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	cout << "Invalid emails: " << endl;
	int i = 0;
	for (i = 0; i < finalIndex; ++i) {
		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->getEmailAddress();

			if (email.find(' ', 0) != string::npos || email.find('@', 0) == string::npos || email.find('.', 0) == string::npos) {
				cout << "\tFor student " << classRosterArray[i]->getStudentId() << ": " << email << endl;
			}
		}
	}
	cout << endl;

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students by degree program:" << endl;
	int index = 0;
	Student::printHead();
	for (index = 0; index < finalIndex; ++index) {
		if (classRosterArray[index] != nullptr && classRosterArray[index]->getDegreeProgram() == degreeProgram) {
			classRosterArray[index]->printStudentInfo();
		}
	}

	cout << endl;
}


Roster::~Roster() {}


