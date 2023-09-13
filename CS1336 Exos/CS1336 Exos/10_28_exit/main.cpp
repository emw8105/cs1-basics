// 10_28_exit

/*
exit function can be called anywhere in the program to terminate.
Termination is immediate.
You can pass an int to indicate the status of termination
C++ has two constants that you can use:
exit(EXIT_SUCCESS): Normal termination
exit(EXIT_FAILURE): Abnormal termination
*/

#include <iostream>
#include <cstdlib> // For exit() function

using namespace std;

void divide(double x, double y);

int main()
{
    double num, denom;
    cout << "Enter 2 numbers: ";
    cin >> num >> denom;
    divide(num, denom);
    cout << "Exiting main";
    return 0;
}

void divide(double x, double y)
{
    if (y == 0.0)
    {
        cout << "Cannot divide by zero" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "The quotient is " << x/y << endl;
}
