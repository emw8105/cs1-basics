// 9_30_if

/*
"if (boolean expression) allows statement(s) to be conditionally executed or skipped over
if boolean expression is TRUE, statement(s) are executed
To conditionally execute or skip over multiple statements, must enclose them in ( )
This creates a block of code
Should indent the statement(s)

"if/else"; 2 possible paths of execution
1. If expr is TRUE, path under the "if" is executed and path under "else" is skipped
2. If expr is FALSE, path under "if" is skipped, and path under "else" is executed

Numerical values can be used as boolean expressions: Zero is FALSE, non-zero is TRUE

If you assign zero to a bool variable, the value will be FALSE
If you assign non-zero value to a bool variable, the value will be TRUE
*/

#include <iostream>

using namespace std;

int main()
{
    const double PASSING_GPA = 3.5;
    double gpa;
    string name;
    string grade;

    cout << "Enter the student's GPA: ";
    cin >> gpa;
    cin.ignore();

    cout << "Enter the student's name: ";
    getline(cin, name);

    if (gpa > PASSING_GPA) // No semi-colon after the )
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

    cout << "Student's name is " << name << endl;
    cout << "Student's GPA is " << gpa << endl;
    cout << "Student's grade is " << grade << endl;

    // Any value not equal to zero is TRUE
    // zero is false
    if (5)
        cout << "5 is TRUE" << endl;
    if (505.7)
        cout << "505.7 is TRUE" << endl;
    int x = 10;
    if (2 * x + 1)
        cout <<  "x = " << x << ", 2*x+1 is TRUE" << endl;
    if (x - 10)
        cout << "x-10 is TRUE" << endl;
    else
        cout << "x-10 is FALSE" << endl;

    // Assign numbers to bool
    bool myBool = 3.14;
    if (myBool)
        cout << "myBool is TRUE" << endl;
    else
        cout << "myBool is FALSE" << endl;
    myBool = 0;
    if (myBool)
        cout << "myBool is TRUE" << endl;
    else
        cout << "myBool is FALSE" << endl;

        return 0;
}
