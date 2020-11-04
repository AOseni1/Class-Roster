#include "Student.h"
Student::Student()
{
    this ->studentID = "";
    this ->firstName = "";
    this ->lastName = "";
    this ->emailAddress = "";
    this ->age = 0;
    for (int i = 0; i < daysArraySize; i++) this -> days [i] = 0;
    this ->degreeType = DegreeType::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degreeType){
    this ->studentID = studentID;
    this ->firstName = firstName;
    this ->lastName = lastName;
    this -> emailAddress = emailAddress;
    this ->age = age;
    for (int i = 0; i < daysArraySize; i++) this ->days[i] = days[i];
    this ->degreeType = degreeType;
}
Student::~Student() {} /*Destructor does nothing - the Book class creates nothing dynamically*/

/*getters*/
string Student::getstudentID() {return this ->studentID;}
string Student::getfirstName() {return this -> firstName;}
string Student::getlastName() {return this -> lastName;}
string Student::getemailAddress() {return this-> emailAddress;}
int Student::getage() {return this-> age;}
int* Student::getdays() {return this->days;}/*An array name is a pointer!*/
DegreeType Student::getDegreeType(){return this->degreeType;}

/*setters*/
void Student::setstudentID(string studentID) {this ->studentID = studentID;}
void Student::setfirstName(string firstName) { this -> firstName = firstName;}
void Student::setlastName(string lastName){ this ->lastName = lastName;}
void Student::setemailAddress(string emailAddress){ this ->emailAddress = emailAddress;}
void Student::setage(int age){ this ->age = age;}
void Student::setdays(int days[])
{
    for (int i = 0; i <daysArraySize; i++) this ->days[i] = days[i];
}
void Student::setDegreeType(DegreeType dt) {this ->degreeType = dt;}

void Student::printheader()/*use to print the header*/
{
    cout << "ID" << '\t';
    cout << "First" << '\t';
    cout << "Last" << '\t';
    cout << "Email Address" << '\t' << '\t';
    cout << "Age" << '\t';
    cout << "Days to Complete" << '\t';
    cout << "Degree" << std::endl;
}

void Student::print()
{

    cout << this ->getstudentID() << '\t';
    cout << this ->getfirstName() << '\t';
    cout << this ->getlastName() << '\t';
    cout << this ->getemailAddress() << '\t';
    cout << this ->getage() << '\t';
    cout << this ->getdays()[0] << ',';
    cout << this ->getdays()[1] << ',';
    cout << this ->getdays()[2] << '\t';
    cout << degreeTypeStrings[this ->getDegreeType()] << '\n'; /*booktype to string*/
}
