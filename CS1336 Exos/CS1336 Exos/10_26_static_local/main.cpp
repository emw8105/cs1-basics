// 10_26_static_local

/*
Static local variables have local scope, but a different lifetime:
they are not destroyed when the function is exited

Static local variables are initialized to zero by default
Initialization of a static local variable(explicit or by default) is
done only the first time the function is called
*/

#include <iostream>

using namespace std;

void addArg(double x);
void addArgStatic(double x);

int main()
{
    double res = 1000; // local variable

    cout << "Inside main, res = " << res << endl;
    addArg(10);
    addArg(10);
    addArg(10);
    cout << "Back from addArg, res = " << res << endl;

    cout << "\nNow call addArgStatic\n";
    addArgStatic(10);
    addArgStatic(10);
    addArgStatic(10);


    return 0;
} // Scope of res and num end here

void addArg(double x) // x is a parameter
{
    double res = 500; // Local variaable
    cout << "Entered addArg, res = " << res << endl;
    res = res + x;
    cout << "Exiting addArg, res = " << res << endl;
} // Scope of x and res end here

void addArgStatic(double x) // x is a parameter
{
    static double res = 500; // Static Local variaable
    cout << "Entered addArgStatic, res = " << res << endl;
    res = res + x;
    cout << "Exiting addArgStatic, res = " << res << endl;
} // Scope of x and res end here
