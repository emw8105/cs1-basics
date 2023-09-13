// 9_30_nested_if

#include <iostream>

using namespace std;

int main()
{
    const double PASSING_GPA_UNDERGRAD = 3.5;
    const double PASSING_GPA_GRAD = 3.7;
    double gpa;
    string name;
    string grade;
    char status; // Grad or undergrad


    cout << "Enter the student's GPA: ";
    cin >> gpa;
    cin.ignore();

    cout << "Enter the student's name: ";
    getline(cin, name);

    cout << "Enter the student's status, U for undergrad, G for grad:";
    cin >> status;

    if (status == 'U') // Undergrad
    {
        if (gpa >= PASSING_GPA_UNDERGRAD) // No semi-colon after the )
        {
            // Start block of code
            cout << "Congratulations on your GPA!" << endl;
            grade = "P";
        } // End block of code
        else
        {
            cout << "Try to do better next time!" << endl;
            grade = "F";
        }
    }
    else // Grad
    {
        if (gpa >= PASSING_GPA_GRAD) // No semi-colon after the )
        {
            // Start block of code
            cout << "Congratulations on your GPA!" << endl;
            grade = "P";
        } // End block of code
        else
        {
            cout << "Try to do better next time!" << endl;
            grade = "F";
        }
    }

    cout << "Student's name is " << name << endl;
    cout << "Student's GPA is " << gpa << endl;
    cout << "Student's status is " << status << endl;
    cout << "Student's grade is " << grade << endl;

    return 0;
}
