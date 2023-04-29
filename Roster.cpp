#include <iostream>
#include <string>
#include "Roster.h"
#include <iomanip>
#include <string>
using namespace std;



Roster::~Roster()
{
	//cout << endl << "Destructor Called (Roster)" << endl;
	for (int i = 0; i < numOfStudents; i++)
	{
		classRosterArray[i] = nullptr;
	}
}

void Roster::parse(string studentInfo)
{
		// finds the student ID in the string (start of string to comma)
		size_t rhs = studentInfo.find(",", 0);
		string sid = studentInfo.substr(0, rhs);

		// finds the first name of student (continuing string from current comma to next comma)
		size_t lhs = rhs + 1;
		rhs	= studentInfo.find("," , lhs);
		string fn = studentInfo.substr(lhs, rhs - lhs);

		// finds the last name of student (continuing string from current comma to next comma)
		lhs = rhs + 1;
		rhs = studentInfo.find(",", lhs);
		string ln = studentInfo.substr(lhs, rhs - lhs);

		// finds the emailaddress of student (continuing string from current comma to next comma)
		lhs = rhs + 1;
		rhs = studentInfo.find(",", lhs);
		string ea = studentInfo.substr(lhs, rhs - lhs);

		// finds the age of student (continuing string from current comma to next comma)
		lhs = rhs + 1;
		rhs = studentInfo.find(",", lhs);
		int a = stod(studentInfo.substr(lhs, rhs - lhs));

		// finds the days to complete 3 classes (continuing string from current comma to next comma)
		lhs = rhs + 1;
		rhs = studentInfo.find(",", lhs);
		double cl1 = stod(studentInfo.substr(lhs, rhs - lhs));
		lhs = rhs + 1;
		rhs = studentInfo.find(",", lhs);
		double cl2 = stod(studentInfo.substr(lhs, rhs - lhs));
		lhs = rhs + 1;
		rhs = studentInfo.find(",", lhs);
		double cl3 = stod(studentInfo.substr(lhs, rhs - lhs));

		// finds the degree program (looks at the last charater in the string to find degree program type)
		lhs = rhs + 1;
		rhs = studentInfo.find("\0", lhs);
		char degreeType = (studentInfo.back());
		DegreeProgram dp = DegreeProgram::SECURITY;
		if (degreeType == 'K')
		{
			dp = DegreeProgram::NETWORK;
		}
		else if (degreeType == 'E')
		{
			dp = DegreeProgram::SOFTWARE;
		}

		add(sid, fn, ln, ea, a, cl1, cl2, cl3, dp);
	
}



void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, double cl1, double cl2, double cl3, DegreeProgram degreeProgram)
{
	double courseDays[3] = { cl1,cl2,cl3 };
	classRosterArray[++rosterIndex] = new Student(studentId, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
}

void Roster::remove(string studentId)
{
	cout << "\n";
	for (int i = 0; i <= rosterIndex; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentId)
		{
			cout << "Removing " << classRosterArray[i]->getStudentId() << "\n";
			classRosterArray[i]->setStudentId("Student not found...");
		}
		else if (classRosterArray[i]->getStudentId() == "Student not found...")
		{
			cout << "Student not found..\n";
		}
	}
}





//Print Functions

void Roster::printAll()
{
	Student::printTableHeader();
	for (int i = 0; i <= rosterIndex; i++)
	{
		classRosterArray[i]->print();
	}

}

void Roster::printDegreeProgram(DegreeProgram dp)
{
	Student::printTableHeader();
	for (int i = 0; i <= rosterIndex; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
	cout << "\n";
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= rosterIndex; i++)
	{
		string ea = (classRosterArray[i]->getEmailAddress());
		if (ea.find(' ') != string::npos || (ea.find('@') == string::npos && ea.find('.') == string::npos))
		{
			cout << classRosterArray[i]->getStudentId() << " has an invalid email \"" << classRosterArray[i]->getEmailAddress() << "\"";
		}
	}

}

void Roster::printAverageDaysInCourse(string studentId)
{
	cout << "Average number of days for students to complete each course: ";
	for (int i = 0; i <= rosterIndex; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentId)
		{
			cout << studentId << "'s average is "
				 << (classRosterArray[i]->getDaysInCourse()[0] +
					 classRosterArray[i]->getDaysInCourse()[1] +
					 classRosterArray[i]->getDaysInCourse()[2]) / 3 << " days\n";
		}
	}
}


