// 11_9_sentinel_nested_loops

/*
A sentinel is a special value to indicate end of data
The special value must be different from a valid value

A sentinel is useful to exit the loop when the user does not know upfront
how many times the program needs to loop

A loop can be nested within another loop

Any combination is possible: while within a while, while within a for loop, etc.
*/

#include <iostream>

using namespace std;

int main()
{
    const int MY_SENTINEL = -1; // This is my sentinel
    int hours;
    double rate;
    const double MIN_RATE = 10;
    const double MAX_RATE = 500;

    cout << "Enter the number of hours, " << MY_SENTINEL << " when done: ";
    cin >> hours;

    while (hours != MY_SENTINEL)
    {
        cout << "Enter the rate: ";
        cin >> rate;
        while (rate < MIN_RATE || rate > MAX_RATE) // while loop for input validation
        {
            cout << "Invalid value, please reenter: ";
            cin >> rate;
        }
        cout << "Salary is " << hours * rate << endl;
        cout << "Enter the number of hours, " << MY_SENTINEL << " when done: ";
        cin >> hours;
    }

    return 0;
}
