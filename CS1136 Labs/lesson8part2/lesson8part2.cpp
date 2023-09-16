/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/10/2021
Purpose of program:
The program receives a start value, end value, and increment value,
and uses them to calculate every incremental value difference between
the start and end value on a temperature range. This increment is converted
to celsius and kelvin in addition to fahrenheit and then displayed in
a table
*/

#include <iostream>
#include <iomanip>

using namespace std;

void read(double& startVal, double& endVal, double& incVal);
double toCelsius(double fahrenheit);
double toKelvin(double celsius);

int main()
{
    cout << fixed; // turn on demicals

    double startVal, endVal, incVal; // declare variables and then have them given value by the read function
    read(startVal, endVal, incVal);
    cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << setw(18) << "Kelvin" << endl; // table header
    cout << setw(18) << setprecision(4) << startVal << setw(18) << toCelsius(startVal) << setw(18) << toKelvin(toCelsius(startVal)) << endl; // first line of calculation with initial values
    while (startVal + incVal <= endVal) // keep repeating calculation as long as another increment can be made without going past the end value
    {
        startVal += incVal; // add the increment to the start value and calculate
        cout << setw(18) << setprecision(4) << startVal << setw(18) << toCelsius(startVal) << setw(18) << toKelvin(toCelsius(startVal)) << endl;
    }

    return 0;
}

double toCelsius(double fahrenheit)
{
    // converts fahrenheit to celsius using formula
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

double toKelvin(double celsius)
{
    // converts celsius to kelvin using formula
    double kelvin = celsius + 273.15;
    return kelvin;
}

void read(double& startVal, double& endVal, double& incVal)
{
    cin >> startVal >> endVal >> incVal; // read in values
    while (startVal > endVal || endVal <= 0.0 || incVal <= 0.0) // make sure the start value is less than the end value and ending and increment value is greater than 0
    {
        cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl; // display error for user and repeat until input is valid
        cin >> startVal >> endVal >> incVal;
    }
}
