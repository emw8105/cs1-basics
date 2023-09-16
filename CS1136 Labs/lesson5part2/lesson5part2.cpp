/*
This program takes a selected medium and an inputted amount of seconds to
determine the travel distance of a sound through the medium in meters
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double seconds;
    unsigned int medium;
    const double CD_SPEED = 258.0; // constant values for the constant m/s medium speeds
    const double AIR_SPEED = 331.5;
    const double HELIUM_SPEED = 972.0;
    const double HYDROGEN_SPEED = 1270.0;

    cout << fixed; // turn on decimals

    cout << "Select the medium that sound is traveling through:\n"; // prompt the user
    cout << "1 Carbon Dioxide\n";
    cout << "2 Air\n";
    cout << "3 Helium\n";
    cout << "4 Hydrogen\n";

    cin >> medium; // store the inputted medium

    if (medium < 1 || medium > 4) // if the number is anything except 1-4
    {
        cout << "The menu value is invalid. Please run the program again.\n";
    }
    else // if the number is 1-4
    {
        cout << "Enter time (in seconds)\n"; // prompt the user
        cin >> seconds; // store the inputted value into seconds
        if (seconds < 0.0000 || seconds > 30.0000) // if the value is any number not between 0.0000 and 30.0000
        {
            cout << "The time must be between 0.000 and 30.000 (inclusive)\n";
        }
        //calculate the travel distance by multiplying the m/s of the medium by the seconds
        else if (medium == 1) // if the medium selected is Carbon Dioxide
        {
            cout << "Carbon Dioxide: " << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << setprecision(4) << CD_SPEED*seconds << " meters" << endl;
        }
        else if (medium == 2) // if the medium selected is Air
        {
            cout << "Air: " << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << setprecision(4) << AIR_SPEED*seconds << " meters" << endl;
        }
        else if (medium == 3) // if the medium selected is Helium
        {
            cout << "Helium: " << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << setprecision(4) << HELIUM_SPEED*seconds << " meters" << endl;
        }
        else // if the medium selected is Hydrogen
        {
            cout << "Hydrogen: " << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << setprecision(4) << HYDROGEN_SPEED*seconds << " meters" << endl;
        }
    }

    return 0;
}
