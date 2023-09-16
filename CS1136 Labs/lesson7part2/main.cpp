/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/3/2021
Purpose of program:
The program is to calculate the future value of a deposit
based on inputted present value, interest rate, and the
amount of months, then it displays all of the recorded values
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

//reference variables in read function used to modify the values used in the rest of the program
void read (double& presentValue, double& interestRate, int& months);
double futureValue(double presentValue, double interestRate, int months);
void display(double presentValue, double interestRate, int months, double futureValue);

int main()
{
    cout << fixed;
    double presentValue, interestRate, calculatedFV;
    int months;
    read(presentValue, interestRate, months); // call function with reference variables as arguments
    interestRate /= 100; // divide for calculations
    calculatedFV = futureValue(presentValue, interestRate, months); // call function using previously modified variables
    interestRate *= 100; // remultiply to display original value
    display(presentValue, interestRate, months, calculatedFV);// call function with all primary values used
    return 0;
}

void read (double& presentValue, double& interestRate, int& months)
{
    cout << "Enter present value\nEnter monthly interest rate\nEnter months\n"; // prompt user
    cin >> presentValue >> interestRate >> months; // receive multiple inputs
    if (presentValue <= 0 || interestRate <= 0 || months <= 0) // input validation
    {
        cout << setprecision(2) << presentValue << " " << setprecision (3) << interestRate << " " << months << endl;
        cout << "One or more of the above values are not greater than zero\n";
        exit(EXIT_FAILURE);
    }
}

double futureValue(double presentValue, double interestRate, int months)
{
    double temp = 1 + interestRate; // use placeholder value to input into pow function
    double futureValue = presentValue * (pow(temp, months)); // calculate the future value
    return futureValue;
}

void display (double presentValue, double interestRate, int months, double futureValue)
{
    // display values in a table with 2 columns, the top column tells the user what the value of the bottom column represents
    cout << setw(18) << "Future Value" << setw(18) << "Present Value" << setw(18)
        << "Monthly Interest" << setw(10) << "Months" << endl;
    cout << setw(18) << setprecision(2) << futureValue << setw(18) << setprecision(2)
        << presentValue << setw(18) << setprecision(3) << interestRate << setw(10)
        << months << endl;
}
