#pragma once
#include <iostream>
#include <map>
using namespace std;


enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" }; // parallel array of strings

static const map<string, DegreeProgram> enumMap = { {"SECURITY", DegreeProgram::SECURITY} , {"NETWORK", DegreeProgram::NETWORK}, {"SOFTWARE", DegreeProgram::SOFTWARE} };