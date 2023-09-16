/*
This program takes an inputted amount of mass (kg) and calculates the
weight (N) that the object would be based on the acceleration due to gravity
on other bodies in the solar system. It won't calculate negative masses because
they must be greater than 0. If the object is lighter than 5N (on earth), it will result
in outputting that the object is light. Likewise if the object is heavier than
1500N (on earth), it will result in outputting that the object is heavy.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed;
    const double EARTH_GRAVITY = 9.81; // acceleration due to the gravity on earth
    const double MOON_GRAVITY = 1.62; // acceleration due to the gravity on the moon
    const double VENUS_GRAVITY = 8.87; // acceleration due to the gC:\Homeworks\lesson4part1\main.cppravity on venus
    double mass;

    cout << "Enter the mass in kg\n"; //prompt the user
    cin >> mass; //store inputted mass amount in kg
    cout << "The mass is " << setprecision(4) << mass << " kg\n";
    if (mass <= 0) { // check if the inputted mass is negative
        cout << "The mass must be greater than zero\n";
    }
    else { // if the inputted mass is positive, continue the program
        cout << setw(8) << left << "Location" << right << setw(14) << "Weight (N)" << endl; // header for the table
        cout << setw(8) << left << "Earth" << right << setw(14) << setprecision(4) << mass * EARTH_GRAVITY << endl; // earth gravity weight
        cout << setw(8) << left << "Moon" << right << setw(14) << setprecision(4) << mass * MOON_GRAVITY << endl; // moon gravity weight
        cout << setw(8) << left << "Venus" << right << setw(14) << setprecision(4) << mass * VENUS_GRAVITY << endl; // venus gravity weight

        if (mass * EARTH_GRAVITY >= 1500) { // if the object's weight on earth is greater than / equal to 1500 Newtons
            cout << "The object is heavy\n";
        }
        else if (mass * EARTH_GRAVITY < 5) { // if the objects weight on earth is less than 5 Newtons
            cout << "The object is light\n";
        }
    }
    return 0;
}
