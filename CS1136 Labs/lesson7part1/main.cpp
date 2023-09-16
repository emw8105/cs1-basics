/*Author: Evan Wright
Compiler: GNU GCC
Date: 10/27/2021
Purpose of program:
The program manages the orders of spool for a spool
company by determining the requested amount of spool,
comparing it to the spool in stock, and using the
shipping cost to calculate the amount of spool on
back order if need be and the total cost of the
purchase
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void read(int&, int&, double&);
void display(int, int, double);

int main()
{
    cout << fixed; // turn on decimals

    int spoolOrder;
    int spoolStock;
    double shipCharge;


    read(spoolOrder, spoolStock, shipCharge); // calls the read function
    display(spoolOrder, spoolStock, shipCharge); // calls the display function
    return 0;
}

//function takes reference variables as parameters to modify the values used throughout the program
void read(int& spoolOrder, int& spoolStock, double& shipCharge)
{
    char shipAndHandle;

    cout << "Spools to be ordered" << endl; // prompt user
    cin >> spoolOrder; // receive and store value
    if (spoolOrder < 1) // input validation
    {
        cout << "Spools order must be 1 or more" << endl;
        exit(EXIT_FAILURE); // causes function to stop
    }
    else
    {
        cout << "Spools in stock" << endl; // prompt user
        cin >> spoolStock; // receive and store value
        if (spoolStock < 0) // input validation
        {
            cout << "Spools in stock must be 0 or more" << endl;
            exit(EXIT_FAILURE); // causes function to stop
        }
        else
        {
            cout << "Special shipping and handling (y or n)" << endl; // prompt user
            cin >> shipAndHandle; // receive and store value
            if (shipAndHandle == 'y') // check for user specification
            {
                cout << "Shipping and handling amount" << endl; // prompt user
                cin >> shipCharge; // receive and store value
                if (shipCharge < 0) // input validation
                {
                    cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
                    exit(EXIT_FAILURE); // causes function to stop
                }
            }
            else // if user doesn't specify or value is unaccounted for, use default shipping charge
            {
                shipCharge = 12.99;
            }
        }
    }
}

//displays the values calculated in read as well as new values
void display(int spoolOrder, int spoolStock, double shipCharge)
{
    int spoolBackOrder = 0;
    double readyToShip = spoolOrder;
    double totalShipCharge;
    // if the order is more than what is in stock, put the excess on backorder and make the available
    // spool in stock the readyToShip value
    if (spoolOrder > spoolStock)
    {
        spoolBackOrder = spoolOrder - spoolStock;
        readyToShip = spoolStock;
    }
    totalShipCharge = readyToShip * shipCharge; // the shipping cost is per unit of spool, so multiply by the amount ready to ship
    //output values
    cout << "Spools ready to ship: " << static_cast<int>(readyToShip) << endl;
    cout << "Spools on back-order: " << spoolBackOrder << endl;

    readyToShip*=104.0; // multiply the amount of spool ready to ship by the cost per unit of spool
    cout << "Subtotal ready to ship: $" << setw(10) << setprecision(2) << readyToShip << endl;
    cout << "Shipping and handling:  $" << setw(10) << setprecision(2) << totalShipCharge << endl;
    cout << "Total shipping charges: $" << setw(10) << setprecision(2) << readyToShip + totalShipCharge << endl;
}
