//10_21_return

/*
The return statement can be used to exit a function and return to the calling function.
return can be put anywhere in a function, statements that follow the return will not
be executed

Can be used to prevent abnormal termination of program (example of divide by zero)

Can be "return expression" if the function returns a value, or just "return" if the
function returns nothing (void)

Various ways to use the data returned by a function: use in a cout, assign to a variable,
use in an expression
*/
#include <iostream>

using namespace std;

void div(double, double);
double calcAverage(double, double);

int main()
{
    double num, denom, res;

    cout << "Enter a numerator and a denominator: ";
    cin >> num >> denom;
    div(num, denom);

    // Different ways to use a value returned by a function
    // First way: Use in cout
    cout << "The average is " << calcAverage(num, denom) << endl;
    // Second way: Assign to a variable and later use the variable
    res = calcAverage(num, denom);
    cout << "Square of the average is " << res * res << endl;
    //Third way: Use in an expression
    cout << "Square of the average is " << calcAverage(num, denom) * calcAverage(num, denom) << endl;

    return 0;
}

void div(double x, double y)
{
    if (y == 0.0)
    {
        cout << "Cannot divide by zero" << endl;
        return; // This return is not optional, case of abnormal termination
    }
    cout << "The quotient is " << x/y << endl;
    return; // Optional
}

double calcAverage(double x, double y)
{
    return (x + y)/2; // Not optional
}
