/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/8/2021
Purpose of program:
The program calculates the fees of a certain banking account based on
user inputs. It calculates the check fee, monthly fee, and total fee
based on their account balance checking fee bracket, and performs
input validation on each entry
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//function prototypes
double getBalance();
int getNumChecks();
double calcCheckFee(int numChecks, double bal);
double calcMonthlyFee(double bal);

int main()
{
    double balance; // amount of money in the bank account
    int numChecks; // number of checks ordered
    double checkFee; // stores the cost of each check
    double monthlyFee; // stores the additional monthly fee
    int menuChoice; // stores the user menu choice

    cout << fixed;

    while (menuChoice != 2) // loops the program while the user choice is not 2
    {
        cout << "Menu" << endl;
        cout << "1 -> Calculate fee, 2 -> Quit" << endl; // prompt the user
        cin >> menuChoice; //receive and store result

        if (menuChoice == 2) // if the user choice is 2, terminate program
        {
            cout << "Exiting" << endl;
            exit(EXIT_SUCCESS);
        }

        // if the user choice is anything except 2, continue
        balance = getBalance(); // call getBalance function, store results in balance
        numChecks = getNumChecks(); // call getNumChecks function, store results in numChecks
        numChecks = ((numChecks - 1) / 50) + 1; // convert numChecks to rounded multiple for calculations
        checkFee = calcCheckFee(numChecks, balance); // call calcCheckFee and store results in checkFee
        monthlyFee = calcMonthlyFee(balance); // call calcMonthlyFee and store results in monthlyFee

        // display results of calculations
        cout << "The check fee is $" << setprecision(2) << checkFee << endl;
        cout << "The monthly fee is $" << setprecision(2) << monthlyFee << endl;
        cout << "The total fee is $" << setprecision(2) << checkFee + monthlyFee << endl;
    }

    return 0;
}

double getBalance()
{
    double balance;
    int counter = 1; // tracks the number of attempts
    cout << "Enter the account balance: "; // prompt user
    cin >> balance; // receive and store result
    cout << "Balance entered is " << setprecision(2) << balance << endl; // print input back to user
    while (balance < -100.0) // loop until attempts expire or input is valid
    {
        if (counter > 5) // user given 5 reattempts, the 6th terminates the program
        {
            cout << "Too many unsuccessful attempts, exiting" << endl;
            exit(EXIT_FAILURE);
        }
        cout << "Balance must be at least -$100, please reenter: "; // reprompt user
        cin >> balance; // receive and store result
        cout << "Balance entered is " << setprecision(2) << balance << endl; //reprint input for user
        counter++; // add an extra attempt used
    }
    return balance; // send back valid input to be stored in balance variable in main
}

int getNumChecks()
{
    int numChecks;
    int counter = 1; // tracks the number of attempts
    cout << "Enter the number of checks (min 50, max 500): "; // prompt user
    cin >> numChecks; // receive and store result
    cout << "Number of checks entered is " << numChecks << endl; // print input back to user
    while (numChecks < 50 || numChecks > 500) // loop until attempts expire or input is valid
    {
        if (counter > 5) // user given 5 reattempts, the 6th terminates the program
        {
            cout << "Too many unsuccessful attempts, exiting" << endl;
            exit(EXIT_FAILURE);
        }
        cout << "We do not process less than 50 checks or more than 500 checks, please reenter: "; // reprompt user
        cin >> numChecks; // receive and store result
        cout << "Number of checks entered is " << numChecks << endl; // reprint input for user
        counter++; // add extra attempt used
    }
    return numChecks; // send back valid input to be stored in numChecks variable in main
}

double calcCheckFee(int numChecks, double bal)
{
    double checkFee;

    // determine the check fee cost based on the account balance bracket
    if (bal < 0)
        checkFee = 6.00;
    else if (bal >= 0 && bal < 100)
        checkFee = 4.00;
    else if (bal >= 100 && bal < 1000)
        checkFee = 2.50;
    else if (bal >= 1000 && bal < 5000)
        checkFee = 1.10;
    else if (bal >= 5000)
        checkFee = 0;

    checkFee = checkFee*numChecks;// total check fee cost in the cost of each check multiplied by the amount of checks
    return checkFee; // return result of calculations
}

double calcMonthlyFee(double bal)
{
    // determine the monthly fee cost based on the account balance bracket
    double monthlyFee;
    if (bal < 0)
        monthlyFee = 20;
    else if (bal >= 0 && bal < 100)
        monthlyFee = 10;
    else if (bal >= 100 && bal < 1000)
        monthlyFee = 5;
    else if (bal >= 1000 && bal < 5000)
        monthlyFee = 2.00;
    else if (bal >= 5000)
        monthlyFee = 0;

    return monthlyFee; // return result of calculations
}
