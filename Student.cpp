#include <iomanip>
#include <iostream>
#include "Student.h"
using namespace std;


Student::Student() { // Sets values to "empty"
 
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArraySize; i++)
        {
        this->daysInCourse[i] = 0;
        };
    this->degreeProgram = DegreeProgram::SECURITY;

}

Student::Student(string studentId, //constructor
                 string firstName, 
                 string lastName, 
                 string emailAddress, 
                 int age, 
                 double daysInCourse[], 
                 DegreeProgram degreeProgram)
{
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysInCourseArraySize; i++)
    {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

Student::~Student() //Deconstructor
{
}




//Setters
void Student::setStudentId(string sid) //short for student ID, sets studentId
{
    this->studentId = sid;
}

void Student::setFirstName(string firstName) // sets first name 
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName) // sets last name 
{
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) // sets email address )
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) // sets age
{
    this->age = age;
}

void Student::setDaysInCourse(double daysInCourse[]) // sets each element in the array 
{
    for (int i = 0; i < daysInCourseArraySize; i++)
    {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::setDegreeProgram(DegreeProgram dp) // sets degree program 
{
    this->degreeProgram = dp;
}



//Getters

string Student::getStudentId() // gets studentId
{
    return this->studentId;
}

string Student::getFirstName() // gets firstName
{
    return this->firstName;
}

string Student::getLastName() // gets lastName
{
    return this->lastName;
}

string Student::getEmailAddress() // gets emailAddress
{
    return this->emailAddress;
}

int Student::getAge() // gets age
{
    return this->age;
}

double* Student::getDaysInCourse() // gets daysInCourse
{
    return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram() // gets degreeProgram
{
    return this->degreeProgram;
}


// Print Functions



void Student::printTableHeader() //Prints header information
{
    cout << "Student ID" 
         << "\t" << "First Name" 
         << "\t" << "Last Name" 
         << "\t\b" << "Email"
         << "\t\t\t" << "Age" 
         << "\t" << "Days in Course"
         << "\t" << "Degree Program" << "\n";
}

void Student::print() //Prints parsed string data
{
    cout << this->getStudentId() <<    "\t\t";
    cout << this->getFirstName() <<    "\t\t";
    cout << this->getLastName() << "   \t";
    cout << "\b" << this->getEmailAddress() << "  \t";
    cout << this->getAge() << "\t";
    for (int i = 0; i < daysInCourseArraySize; i++)
    {
        cout << this->getDaysInCourse()[i] << ",";
    }
    cout << "\b";
    cout << "   \t" << degreeProgramName[this->getDegreeProgram()] << "\n";
}


