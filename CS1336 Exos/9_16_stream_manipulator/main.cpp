// 9_16_stream_manipulator

/*
With stream manipulators, you can control the output formatting
Requires #include<iomanip>
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // setw(x)
    double s11 = 90.0, s12 = 85.75, s13 = 95.1; // Student 1
    double s21 = 79.123, s22 = 88, s23 = 99; // Student 2
    string name1 = "Chewbacca", name2 ="R2D2";

    cout << "Student's name: " << name1 << ' ' << s11 << ' ' << s12 << ' ' << s13 << endl;
    cout << "Student's name: " << name2 << ' ' << s21 << ' ' << s22 << ' ' << s23 << endl;

    cout << "\nwith setw()" << endl;
    cout << "Student's name: " << setw(10) << name1 << setw(8) << s11 << setw(8) << s12 << setw(8) << s13 << endl;
    cout << "Student's name: " << setw(10) << name2 << setw(8) << s21 << setw(8) << s22 << setw(8) << s23 << endl;

    // showpoint
    cout << "\nShowpoint\n";
    cout << "s11 w/o showpoint is " << s11 << endl;
    cout << showpoint << "s11 with showpoint is " << s11 << endl; // turn on the "showpoint switch"

    // reset showpoint
    cout << resetiosflags(ios::showpoint);
    cout << "s11 after resetflags(showpoint) is " << s11 << endl;

    // setprecision(x) without fixed
    // x is the number of significant digits
    // which is the total number of digits before and after the decimal point
    double PI = 3.14159;
    cout << "\nPI w/o setprecision: " << PI << endl;
    cout << setprecision(6) << "PI w setprecision(6): " << PI << endl;
    cout << setprecision(4) << "PI w setprecision(4): " << PI << endl;

    // setprecision(x) with fixed
    // x is the number of digits after the decimal point
    cout << fixed; // turn on the "fixed" switch
    cout << setprecision(6) << "PI w setprecision(6) with fixed: " << PI << endl;
    cout << setprecision(4) << "PI w setprecision(4) with fixed: " << PI << endl;

    // reset fixed, turn off the switch
    cout << resetiosflags(ios::fixed);
    cout << "PI after resetflags(fixed) is " << PI << endl;
    cout << "PI w/o setprecision: " << PI << endl;

    cout << "\nTest scores with setw() and setprecision(2) and fixed";
    cout << fixed << setprecision(2) << endl;
    cout << "Student's name: " << setw(10) << name1 << setw(8) << s11 << setw(8) << s12 << setw(8) << s13 << endl;
    cout << "Student's name: " << setw(10) << name2 << setw(8) << s21 << setw(8) << s22 << setw(8) << s23 << endl;

    // Difference between fixed and showpoint
    cout << endl << resetiosflags(ios::fixed);
    double x = 90000000.0;
    cout << "x is " << x << endl;
    cout << fixed << "x with fixed is " << x << endl;
    cout << resetiosflags(ios::fixed);
    cout << showpoint << "x with showpoint is " << x << endl;

    return 0;
}
