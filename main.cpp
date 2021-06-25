#include <iostream>
#include "degree.h"
#include "roster.h"
#include "student.h"




using namespace std;



int main() {

	cout << "C867 Scripting & Programming Applications" << endl;
	cout << "Julian Ramirez" << endl;
	cout << "WGU Student ID: 003590538" << endl;
	cout << endl << endl;



	Roster classRoster = Roster(); 

	classRoster.parseStudents();

	classRoster.printAll();

	classRoster.printInvalidEmails();

	int index = 0; // For loop that calculates average number of days in courses
	int finalIndex = 5;
	cout << "Average days in course:" << endl;
	for (index = 0; index < finalIndex; ++index) {
		if (classRoster.classRosterArray[index] != nullptr) {
			classRoster.printAverageDaysInCourse(classRoster.classRosterArray[index]->getStudentId());
		}
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");
	
	classRoster.~Roster();


	




	system("pause > 0");
}