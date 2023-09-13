/*
Author: Evan Wright
Compiler: GNU GCC
Date: 9/17/2021
Purpose of program: Calculates the average

Calculates the salary from the hourly rate and
number of hours worked.
The program prompts the user to input the hourly rate, number of hours
worked, then calculates the salary and displays it.
*/

#include <iostream>

using namespace std;

int main()
{
    string firstName, lastName;
    double test1, test2, test3;

    cout << "Please enter the student's first name: ";
    cin >> firstName;
    cout << "First name entered is " << firstName << endl;

    cout << "Please enter the student's last name: ";
    cin >> lastName;
    cout << "Last name entered is " << lastName << endl;

    cout << "Please enter the student's test 1 score: ";
    cin >> test1;
    cout << "Test 1 score entered is " << test1 << endl;

    cout << "Please enter the student's test 2 score: ";
    cin >> test2;
    cout << "Test 2 score entered is " << test2 << endl;

    cout << "Please enter the student's test 3 score: ";
    cin >> test3;
    cout << "Test 3 score entered is " << test3 << endl;

    cout << "The test average of " << firstName << ' ' << lastName << " is "
    << (test1 + test2 + test3)/3 << endl;


    return 0;
}
