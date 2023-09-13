/*Author: Evan Wright
Compiler: GNU GCC
Date: 10/6/2021
Purpose of program:





*/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double balance; // amount of money in the bank account
    int numChecks; // number of checks ordered
    int roundedMultiple;
    double checkFeeBracket;
    double monthlyFeeBracket;


    cout << "Enter the account balance: ";
    cin >> balance;
    cout << "Balance entered is " << balance << endl;
    cout << fixed;
    if (balance < -100)
    {
        cout << "Balance must be at least -$100." << endl;
    }
    else
    {
        cout << "Enter the number of checks (min 50, max 500): ";
        cin >> numChecks;
        cout << "Number of checks entered is " << numChecks << endl;
        if (numChecks < 50 || numChecks > 500)
            cout << "We do not process less than 50 checks or more than 500 checks." << endl;
        else
        {
            roundedMultiple = ((numChecks - 1) / 50) + 1;

            if (balance < 0)
            {
                monthlyFeeBracket = 20;
                checkFeeBracket = 6.00;
            }
            else if (balance >= 0 && balance < 100)
            {
                monthlyFeeBracket = 10;
                checkFeeBracket = 4.00;
            }
            else if (balance >= 100 && balance < 1000)
            {
                monthlyFeeBracket = 5;
                checkFeeBracket = 2.50;
            }
            else if (balance >= 1000 && balance < 5000)
            {
                monthlyFeeBracket = 2.00;
                checkFeeBracket = 1.10;
            }
            else if (balance >= 5000)
            {
                monthlyFeeBracket = 0;
                checkFeeBracket = 0;
            }

            cout << "The check fee is $" << setprecision(2) << checkFeeBracket*roundedMultiple << endl;
            cout << "The monthly fee is $" << setprecision(2) << monthlyFeeBracket << endl;
            cout << "The total fee is $" << setprecision(2) << (checkFeeBracket*roundedMultiple) + monthlyFeeBracket << endl;
        }
    }

    return 0;
}
