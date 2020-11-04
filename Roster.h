#pragma once
#include "Student.h"

class Roster
{
public:
    int lastIndex = -1;
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable];

public:
    void parse (string row);
    void add(string dstudentID,
    string dfistName,
    string dlastName,
    string demailAddress,
    int dage,
    int ddays1,
    int ddays2,
    int ddays3,
    DegreeType dt);
    void printAll(); /* Just calls the print() method in Student class for each book*/
    void printInvalidemailAddress();
    void printAverageDays(string studentID);
    void printByDegreeType(DegreeType dt); 
    void removeStudentBystudentID(string studentID);
    ~Roster();
};
