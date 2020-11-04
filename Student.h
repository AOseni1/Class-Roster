#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
    const static int daysArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[daysArraySize];
    DegreeType degreeType;
public:
    Student();  /*Parameterless constructor - sets default values you always write this*/
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degreeType);/*Full constructor*/
    ~Student(); /*destructor*/
    
    /*getters aka accessors*/
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemailAddress();
    int getage();
    int* getdays();
    DegreeType getDegreeType();
    
    /*setters aka mutators*/
    void setstudentID(string studentID);
    void setfirstName(string firstName);
    void setlastName(string secondName);
    void setemailAddress(string emailAddress);
    void setage(int age);
    void setdays(int days[]);
    void setDegreeType(DegreeType dt);
    
    static void printheader();
    
    void print ();
    
    
};
