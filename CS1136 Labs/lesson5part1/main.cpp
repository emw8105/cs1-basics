/*
This program takes an inputted medium selected between air, water, and steel
and an inputted distance traveled through to calculate how long a sound would take
to travel the distance through the medium.
*/
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    unsigned int medium;
    double distance;
    const int AIR_SPEED = 1100;
    const int WATER_SPEED = 4900;
    const int STEEL_SPEED = 16400;

    cout << fixed; // turn on decimal points

    cout << "Select the medium that sound is traveling through:\n"; // prompt the user
    cout << "1 Air\n"; // provide options
    cout << "2 Water\n";
    cout << "3 Steel\n";
    cin >> medium; // store inputted value

    switch (medium)
    {
    case 1: // if the input is 1
        cout << "Enter distance (in feet)\n"; // prompt the user
        cin >> distance;
        if (distance <= 0) // make sure the inputted distance is greater than 0
            cout << "The distance must be greater than zero\n";
        else
        {
            cout << "Air: " << setprecision(4) << distance << " ft" << endl; // calculate the time
            cout << "Traveled for " << setprecision(4) << distance/AIR_SPEED << " seconds\n";
        }
        break;
    case 2: // if the input is 2
        cout << "Enter distance (in feet)\n"; // prompt the user
        cin >> distance;
        if (distance <= 0) // make sure the inputted distance is greater than 0
            cout << "The distance must be greater than zero\n";
        else
        {
            cout << "Water: " << setprecision(4) << distance << " ft" << endl; // calculate the time
            cout << "Traveled for " << setprecision(4) << distance/WATER_SPEED << " seconds\n";
        }
        break;
    case 3: // if the input is 3
        cout << "Enter distance (in feet)\n"; // prompt the user
        cin >> distance;
        if (distance <= 0) // make sure the inputted distance is greater than 0
            cout << "The distance must be greater than zero\n";
        else
        {
            cout << "Steel: " << setprecision(4) << distance << " ft" << endl; // calculate the time
            cout << "Traveled for " << setprecision(4) << distance/STEEL_SPEED << " seconds\n";
        }
        break;
    default: // if the input was anything else
        cout <<  "The menu value is invalid. Please run the program again.\n";
    }
    return 0;
}
