/*Author: Evan Wright
Compiler: GNU GCC
Date: 10/20/2021
Purpose of program:
The program takes a variety of inputs such as desired future value, the
annual interest rate, and the amount of years in order to calculate the
present value of money needed to reach the future value.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double futureValueRead(); // function prototypes
double annualInterestRead();
int numYearsRead();
double presentValue(double, double, int);
void displayOutput(double, double, double, int);

//main function
int main()
{
    double valueInPresent; // similarly named variables in main store outputted values of corresponding functions
    double futureValue;
    double annualInterestRate;
    int numYears;

    cout << fixed; // turn on decimals

    futureValue = futureValueRead(); // get value from futureValueRead, invalid returns 0
    if (futureValue) // invalid value results in false and skips nested ifs
    {
        annualInterestRate = annualInterestRead(); // get value from annualInterestRead, invalid returns 0
        if (annualInterestRate > 0) // invalid value results in false and skips nested ifs
        {
            numYears = numYearsRead(); // get value from numYearsRead, invalid returns 0
            if (numYears > 0) // invalid value results in false and skips nested ifs
            {
                annualInterestRate /= 100; // convert percentage to decimal for math
                valueInPresent = presentValue(futureValue, annualInterestRate, numYears); // get value from presentValue function
                annualInterestRate *= 100; // convert value back to readable percentage
                displayOutput(valueInPresent, futureValue, annualInterestRate, numYears); // display results
            }
        }
    }


    return 0;
}
double futureValueRead()
{
    double futureValue;
    cout << "Enter future value" << endl; // prompt user
    cin >> futureValue; // read in value
    if (futureValue <= 0) // check for invalid input
    {
        cout << "The future value must be greater than zero" << endl;
        return futureValue = 0; // if input is invalid, return 0 so if statement check is false
    }
    else
        return futureValue; // if the input is acceptable, return the value
}
double annualInterestRead()
{
    double annualInterest;
        cout << "Enter annual interest rate" << endl; // prompt user
        cin >> annualInterest; // read in value
        if (annualInterest <= 0) // check for invalid input
        {
            cout << "The annual interest rate must be greater than zero" << endl;
            return annualInterest = 0; // if input is invalid, return 0 so if statement check is false
        }
        else
            return annualInterest; // if the input is acceptable, return the value
}
int numYearsRead()
{
        int numYears;
        cout << "Enter number of years" << endl; // prompt user
        cin >> numYears; // read in value
        if (numYears <= 0) // check for invalid input
        {
            cout << "The number of years must be greater than zero" << endl;
            return numYears = 0; // if input is invalid, return 0 so if statement check is false
        }
        else
            return numYears; // if the input is acceptable, return the value
}
double presentValue(double futureValue, double interestRate, int numberYears)
{
// formula = P = F / ( (1 + r) ^ n)
double presentValue;
double temp; // temporary value to make math easier
temp = (1 + interestRate);
temp = pow(temp, numberYears);
presentValue = futureValue / temp;

return presentValue; // return the result of above calculations
}
void displayOutput(double presentValue, double futureValue, double interestRate, int numYears)
{
//display the results of the calculations in structured format
cout << "Present value: $" << setprecision(2) << presentValue << endl;
cout << "Future value: $" << setprecision(2) << futureValue << endl;
cout << "Annual interest rate: " << setprecision(3) << interestRate << "%" << endl;
cout << "Years: " << numYears << endl;

}
