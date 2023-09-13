// 10_26_local

/*
1. Scope:
Local variables are variables defined inside a function
Local variables follow the usual scope rules and therefore not accessible
outside the function
The other functions may have distinct variables with the same name

Parameters are like local variables, they are defined at the very beginning of
the function (in the parameter list). Their scope is the whole function.

2. Lifetime:
When a function begins execution, its local variables and parameter(s) are created
When a function exits, its local variable(s) and parameter(s) are destroyed
Any value stored in them is lost
One way to save the information is through the "return value" statement.
*/

#include <iostream>

using namespace std;

void addArg(double x);

int main()
{
    double res = 1000; // local variable

    cout << "Inside main, res = " << res << endl;
    addArg(10);
    addArg(10);
    addArg(10);
    cout << "Back from addArg, res = " << res << endl;


    return 0;
} // Scope of res and num end here

void addArg(double x) // x is a parameter
{
    double res = 500; // Local variaable
    cout << "Entered addArg, res = " << res << endl;
    res = res + x;
    cout << "Exiting addArg, res = " << res << endl;
} // Scope of x and res end here
