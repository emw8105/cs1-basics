// 10_5_elseif

/*
if/elseif is logically equivalent to an "if" followed by an "else"
under which is nested an "if", but it's more convenient because of
no indentation
*/

#include <iostream>

using namespace std;

int main()
{
    const double A_SCORE = 3.7;
    const double B_SCORE = 3.2;
    const double C_SCORE = 2.7;
    const double D_SCORE = 2.2;

    double gpa;
    string netID;
    char grade;

    cout << "Enter the GPA: ";
    cin >> gpa;
    cout << "Enter the netID: ";
    cin >> netID;

    // Nested if
    if (gpa >= A_SCORE)
        grade = 'A';
    else
    {
        if (gpa >= B_SCORE)
            grade = 'B';
        else
        {
            if (gpa >= C_SCORE)
                grade = 'C';
            else
            {
                if (gpa >= D_SCORE)
                    grade = 'D';
                else
                    grade = 'F';
            } // End of gpa < C_SCORE
        } // End of gpa < B_SCORE
    } // End of gpa < A_SCORE

    /*cout << "Student's netID is " << netID << ", GPA is " << gpa << ", grade is "
    << grade << endl;*/

    // Equivalent code using if/else if
    if (gpa >= A_SCORE)
        grade = 'A';
    else if (gpa >= B_SCORE)
        grade = 'B';
    else if (gpa >= C_SCORE)
        grade = 'C';
    else if (gpa >= D_SCORE)
        grade = 'D';
    else if(gpa >= 0)
        grade = 'F';
    else
        cout << "GPA is invalid" << endl;

    cout << "Student's netID is " << netID << ", GPA is " << gpa << ", grade is "
    << grade << endl;


    return 0;
}
