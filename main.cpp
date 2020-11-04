
#include "Roster.h"
//using std::endl;
int main()
{
    cout << "Name: Abisola Oseni" << std::endl;
    cout << "ID: #001345382" << std::endl;
    cout << "Course: C867" << std::endl;
    cout << "Programming Language: C++" << std::endl;
    cout << std::endl;
    /*THE LONG STRINGS TO PARSE*/
    const string classRosterData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Abisola,Oseni,aosen1@wgu.edu,33,50,50,50,SOFTWARE"
        
    };
    
    const int studentDataTable = 5; /*IT'S TOO BAD ARRAYS DON'T RECORD THEIR OWN SIZE*/
    Roster roster; /*THIS CREATES THE REPO USING THE DEFAULT PARAMETERLESS CONSTRUCTOR*/
    
    for (int i = 0; i < studentDataTable; i++) roster.parse(classRosterData[i]);
    cout << "Class Roster:" << std::endl;
    roster.printAll();
    cout << std::endl;
    
    for (int i = 0; i < 3; i++)
    {
    
    cout << "Displaying invalid email addresses" << std::endl;
    roster.printInvalidemailAddress();
    cout << std::endl;
    
    cout << "Displaying average days: " <<std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
    roster.printAverageDays(roster.classRosterArray[i] ->getstudentID());
    cout << std::endl;
    }
            cout << "Displaying by degree type: SOFTWARE" <<std::endl;
            roster.printByDegreeType(SOFTWARE);
        cout << std::endl;

    
    cout << "Remove A3." << std::endl;
        roster.removeStudentBystudentID("A3");
        roster.printAll();
        cout << std::endl;
        roster.removeStudentBystudentID("A3");
            cout << std::endl;
    return 0;
}
}

