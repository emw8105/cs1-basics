// 11_4_for_loop

/*
Syntax is for(initialization; test; update)
Start by executing the initialization, then test. If test is true, execute one iteration
of the loop, then update, then test again. As long as test is true, stay in the loop.
If test is false, exit the loop.
for loop is a pretest loop: Does not execute any iteration if the first test is false

May have multiple statements in initialization and update, separated by commas

Any or all of the initialization, test and update can be empty

If the test is empty, it evaluates to true.

May define a new variable in the initialization part. The scope of that variable is the whole for loop.

For loop is commonly used when the number of iterations is known
In most cases, the for loop and the while loop are equivalent options to implement the same logic

Can implement a running total in a loop
*/
#include <iostream>

using namespace std;

int main()
{
    const int MAX_REATTEMPTS = 3;
    int numEmployees, emplCount;
    int numAttempts = 0;
    double hours, rate, salary;

    cout << "Enter number of employees: ";
    cin >> numEmployees;

    while (numEmployees <= 0 && numAttempts < MAX_REATTEMPTS)
    {
        cout << "Enter number of employees: ";
        cin >> numEmployees;
        numAttempts++;
    }

    if (numEmployees <= 0)
        cout << "Too many attempts, give up" << endl;
    else // Input is valid
    {
        emplCount = 0;
        while (emplCount < numEmployees)
        {
            cout << "Enter hours and rate: ";
            cin >> hours >> rate;
            salary = hours * rate;
            cout << "Salary is " << salary << endl;
            emplCount++;
        }

        // For loop
        cout << endl << "Using for loop" << endl;
        double totalWages = 0; // Running total, remember to initialize
        for (int emplCount = 0; emplCount < numEmployees; emplCount++) // Scope of emplCount is from 62 to 69
        {
            cout << "Enter hours and rate: ";
            cin >> hours >> rate;
            salary = hours * rate;
            cout << "Salary is " << salary << endl;
            totalWages += salary;
        }
        cout << "Total wages is " << totalWages << endl;
    } // End of case valid input

    return 0;
}
