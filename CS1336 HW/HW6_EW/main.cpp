/*Author: Evan Wright
Compiler: GNU GCC
Date: 10/13/2021
Purpose of program:
To calculate the cost of a data bill based on the current
selected plan and the number of gigabytes used in the month.
Additionally, it offers information about each plan
*/

#include <iostream>

using namespace std;

double calcBill(char, double); // function prototype for calcBill

//main function
int main()
{
    int menuChoice;
    char dataPlan;
    double numGigabytes;
    double totalCost;

    cout << "Make your choice" << endl; // prompt user and provide options in a menu
    cout << "1 - Calculate bill" << endl;
    cout << "2 - Compare my plan with the other plan" << endl;
    cout << "3 - Get the pricing info for the plans" << endl;
    cout << "4 - Quit" << endl;
    cin >> menuChoice; // read and store the value inputted by the user

    // use switch statement to process inputted value
    switch (menuChoice)
    {
    case 1:
        {
            cout << "Enter your plan, S for silver, G for gold: "; // prompt user
            cin >> dataPlan; // read in value for the data plan
            if (dataPlan == 'S' || dataPlan == 'G') // input validation
            {
                cout << "How many Gigabytes did you use? "; // prompt user
                cin >> numGigabytes; // read in value as number of gigabytes used in a month
                if (numGigabytes >= 0) // input validation
                {
                    totalCost = calcBill (dataPlan, numGigabytes); // call function with user inputs as arguments
                    cout << "Your bill amount is $" << totalCost << endl; // output results of the function call
                }
                else // if the input was not valid i.e. a negative amount of gigabytes
                {
                    cout << "Invalid usage" << endl;
                }
            }
            else // if the input was not valid i.e. 'S' or 'G'
            {
                cout << "Invalid plan" << endl;
            }

            break;
        }
    case 2:
        {
            cout << "Enter your plan, S for silver, G for gold: "; // prompt user
            cin >> dataPlan; // read in value for the data plan
            if (dataPlan == 'S' || dataPlan == 'G') // input validation
            {
                cout << "How many Gigabytes did you use? "; // prompt user
                cin >> numGigabytes; // read in the value as number of gigabytes used in a month
                if (numGigabytes >= 0) // input validation
                {
                    totalCost = calcBill (dataPlan, numGigabytes); // call function with user inputs as arguments
                    cout << "Your bill amount is $" << totalCost << endl; // outputs results of the function call
                    if (dataPlan == 'S') // check result with opposite plan
                    {
                        totalCost = calcBill ('G', numGigabytes); // calculate and output resulting bill from opposite plan
                        cout << "Your bill would have been $" << totalCost << " with the Gold plan\n";
                    }
                    else if (dataPlan == 'G') // check again for opposite plan
                    {
                        totalCost = calcBill ('S', numGigabytes); // calculate and output resulting bill from opposite plan
                        cout << "Your bill would have been $" << totalCost << " with the Silver plan\n";
                    }
                }
                else // if the input was not valid i.e. a negative amount of gigabytes
                {
                    cout << "Invalid usage" << endl;
                }
            }
            else // if the input was not valid i.e. 'S' or 'G'
            {
                cout << "Invalid plan" << endl;
            }

            break;
        }
    case 3: // output information about both plans
        {
            cout << "Silver Plan\n";
            cout << "monthly fee is $29.99, 4 Gbytes are included, charge $10 per excess Gbyte\n";
            cout << "Gold Plan\n";
            cout << "monthly fee is $49.99, 8 Gbytes are included, charge $5 per excess Gbyte\n";
        }
    case 4: // quits the program by exiting break immediately
        {
            break;
        }
    default: // catch for invalid inputs (values not 1-4)
        {
           cout << "Invalid choice" << endl;
           break;
        }
    }
    cout << "Exiting" << endl;

    return 0;
}
//calcBill function to calculate the cost of the phone bill based on inputted values
double calcBill(char dataPlan, double numGigabytes)
{
    double totalCost;
    int roundedGigabytes = numGigabytes; // makes double value fit integer container
    if (numGigabytes > roundedGigabytes) // always rounds up if possible by comparing to value that was cut off
    {
        roundedGigabytes+=1; // adds 1 accordingly
    }

    if (dataPlan == 'S') // calculates the bill for the silver plan
    {
        totalCost = 29.99; // initial monthly cost
        if (roundedGigabytes > 4)
        {
            totalCost += (roundedGigabytes-4)*10; // additional cost for gigabytes over 4
        }
    }
    else // calculates the bill for the gold plan
    {
        totalCost = 49.99; // initial cost
        if (roundedGigabytes > 8)
        {
            totalCost += (roundedGigabytes-8)*5; // additional cost for gigabytes over 8
        }
    }
    return totalCost; // return the total cost
}
