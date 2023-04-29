#pragma once
#include <iomanip>
#include <iostream>
#include "Student.h"
using namespace std;

class Roster
{
public:
	const static int classSize = 5;
	Student* classRosterArray[classSize];
	int rosterIndex = -1;

	~Roster(); // Deconstructor


	void parse(string studentInfo); // Parses string elements
	
	// Add and remove
	void add(string studentId, 
			 string firstName, 
			 string lastName, 
			 string emailAddress, 
			 int age, 
			 double cl1, 
			 double cl2, 
			 double cl3, 
			 DegreeProgram dp);
	void remove(string studentId);
	
	//Print functions
	void printAll();
	void printDegreeProgram(DegreeProgram dp);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentId);
};