#include "Roster.h"
void Roster::parse (string classrosterdata)/*This parses each row - one at a time*/
{
    DegreeType dt = SOFTWARE; /* default value*/
    if (classrosterdata.at(1) == '1') dt = SECURITY;
    else if (classrosterdata.at(1) == '2') dt = NETWORK;
    else if (classrosterdata.at(1) == '3') dt = SOFTWARE;
    else if (classrosterdata.at(1) == '4') dt = SECURITY;
    else if (classrosterdata.at(1) == '5') dt = SOFTWARE;
    
    int rhs = classrosterdata.find(","); /*find the comma*/
    string dstudentID = classrosterdata.substr(0, rhs); /*extract the substring in front of the comma*/
    
    int lhs = rhs + 1; /*move past the previous comma*/
    rhs = classrosterdata.find(",", lhs);
    string dfirstname = classrosterdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1; /*move past the previous comma*/
    rhs = classrosterdata.find(",", lhs);
    string dlastname = classrosterdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1; /*keep going*/
    rhs = classrosterdata.find(",", lhs);
    string demailaddress = classrosterdata.substr(lhs, rhs -lhs);
    
    lhs = rhs + 1; /*keep going*/
    rhs = classrosterdata.find(",", lhs);
    int dage = stoi(classrosterdata.substr(lhs, rhs -lhs));
    
    lhs = rhs + 1; /*keep going*/
    rhs = classrosterdata.find(",", lhs);
    int ddays1 = stod(classrosterdata.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1; /*keep going*/
    rhs = classrosterdata.find(",", lhs);
    int ddays2 = stod(classrosterdata.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1; /*keep going*/
    rhs = classrosterdata.find(",", lhs);
    int ddays3 = stod(classrosterdata.substr(lhs, rhs-lhs));/*third price*/
    /*Already determined the book type - it was the first thing we did - call add() method*/
    
    add(dstudentID, dfirstname, dlastname, demailaddress, dage, ddays1, ddays2, ddays3, dt);/*Prices go in seperately*/
}

/*The infamous, redundant and wholly unnecessay add method - it only does one thing*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int ddays1, int ddays2, int ddays3, DegreeType dt)
{
    /*Put prices back into an array for constructor - OK it does two things*/
    int parr[3] = {ddays1, ddays2, ddays3};
    /*Make the book a new object. Remember the lastIndex starts at -1 and not 0*/
     /*Remember to use the PREFIX form of ++. Using postfix will MESS YOU UP!*/
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, dt); /*Use full constructor*/
}

void Roster::printAll() {
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}


void Roster::printInvalidemailAddress()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string emailAddress = (classRosterArray[i] ->getemailAddress());
        if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)) 
        {
            any = true;
            cout << emailAddress << ": " << classRosterArray[i] ->getfirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDays(string studentID)
{
    
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] ->getstudentID()==studentID)
        {
        cout << studentID << ":";
        cout << (classRosterArray[i] ->getdays()[0] +
                 classRosterArray[i] ->getdays()[1] +
                 classRosterArray[i] ->getdays()[2])/3.0 <<std::endl;
    }
            }
}



void Roster::printByDegreeType(DegreeType dt)
{
    Student::printheader();
    for (int i = 0; i <= Roster::lastIndex; i++){
        if(Roster::classRosterArray[i] ->getDegreeType() == SOFTWARE) classRosterArray[i] ->print();
    }
    cout << std::endl;
}

void Roster::removeStudentBystudentID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i] ->getstudentID() == studentID)
    {
        success = true; /*found*/
        if (i < studentDataTable - 1)
    {
        Student* temp = classRosterArray[i];
        classRosterArray[i] = classRosterArray[studentDataTable - 1];
        classRosterArray[studentDataTable - 1] = temp;
    }
        Roster::lastIndex --;
    }
    }
        if (success)
    {
    
    }
        else
    {
        cout <<studentID<< " Error not found." <<std::endl << std::endl;
    
    }
}

Roster::~Roster()
{
    for (int i = 0; studentDataTable; i++)
{
    delete classRosterArray[i];
    classRosterArray[i] = nullptr;
            }
}
