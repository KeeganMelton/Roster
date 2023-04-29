#pragma once
#include <iomanip>
#include <iostream>
#include "Degree.h"
using std::string;
using namespace std;

class Student 
{
    private:
      string studentId;
      string firstName;
      string lastName;
      string emailAddress;
      int age;
      double daysInCourse[daysInCourseArraySize];
      DegreeProgram degreeProgram;


    public:
      Student(); // Sets "empty" values

      Student(     // Constructor
          string studentId, 
          string firstName, 
          string lastName, 
          string emailAddress, 
          int age, 
          double daysInCourse[], 
          DegreeProgram degreeProgram);

      ~Student(); // Deconstructor


       // Setters
       void setStudentId(string sId);
       void setFirstName(string firstName);
       void setLastName(string lastName);
       void setEmailAddress(string emailAddress);
       void setAge(int age);
       void setDaysInCourse(double daysInCourse[]);
       void setDegreeProgram(DegreeProgram dp);

       //Getters
       string getStudentId();
       string getFirstName();
       string getLastName();
       string getEmailAddress();
       int getAge();
       double* getDaysInCourse();
       DegreeProgram getDegreeProgram();

       // Print 
       static void printTableHeader();
       void print();
}; 

