// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Roster.h"
using namespace std;


int main()
{

    cout << "Student Roster\n";

    const string studentData[] = // Student Data Table
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Phil,McCup,Phil.McCupUp@gmail.com,30,21,28,21,SOFTWARE"
    };

    // Creates an instance of Roster called "classRoster"
    Roster classRoster; 
    
    //Parses the Array into an object
    for (int i = 0; i < numOfStudents; i++)
    {
        classRoster.parse(studentData[i]);
    }

    //Prints the data
    classRoster.printAll();
    cout << "\n";

    //Separates students by degree program  
    for (int i = 0; i < programType; i++)
    {
        cout << "Showing students in the same program: " << degreeProgramName[i] << "\n";
        classRoster.printDegreeProgram((DegreeProgram)i);
    }
    //Looks for invalid emails and outputs them
    cout << "Students with and invalid email address: \n";
    classRoster.printInvalidEmails();
    cout << "\n\n";

    //finds the average number of days for a student to complete a course
    cout << "A Students average number of days to complete 3 courses: \n";
    for (int i = 0; i < numOfStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    cout << "\n";

    //removes student "A1"
    cout << "Removing Student 'A1'... \n";
    classRoster.remove("A1");
    cout << "\n";

    //Confirms student "A1" has been removed
    cout << "Confirming Student 'A1' was removed... \n";
    classRoster.remove("A1");
    cout << "\n";

    
    return 0;
}
