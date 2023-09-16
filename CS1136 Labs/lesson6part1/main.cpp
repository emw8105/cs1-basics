/*
The purpose of the program is to use a specified number
of seconds to calculate the distance traveled on the Earth
and the moon in that time interval. It then outputs the
calculations to the user.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// function for reading in the number of seconds entered by the user
double readSeconds()
{
    double seconds;

    cout << "Enter the time (in seconds)" << endl; // prompt the user
    cin >> seconds; // read in the value and store it
    return seconds;
}
// function for calculating the distance traveled on earth based on seconds passed
double calculateEarthDistance(double seconds)
{
    const double EARTH_GRAV = 9.8; // initialize the value for the gravity of the earth as a constant value of 9.8
    double distance = 0.5 * EARTH_GRAV * pow(seconds, 2); // use the formula for calculating the distance traveled
    return distance;
}
// function for calculating the distance traveled on the moon based on seconds passed
double calculateMoonDistance(double seconds)
{
    const double MOON_GRAV = 1.6; // initialize the value for the gravity of the moon as a constant value of 1.6
    double distance = 0.5 * MOON_GRAV * pow(seconds, 2); // use the formula for calculating the distance traveled
    return distance;
}
// function for displaying the previously-done calculations
void displayResults(double seconds, double earthDistance, double moonDistance)
{
cout << "The object traveled " << setprecision(4) << earthDistance
<< " meters in " << setprecision(2) << seconds << " seconds on Earth\n";
cout << "The object traveled " << setprecision(4) << moonDistance
<< " meters in " << setprecision(2) << seconds << " seconds on the Moon\n";
}
int main()
{
    cout << fixed; // turn on decimal points

    double seconds = readSeconds(); // use the readSeconds() function to get the number of seconds from the user

    if (seconds < 0) // check if there is a valid number of seconds
        cout << "The time must be zero or more" << endl;
    else // otherwise complete the calculations
    {
        double earthDistance = calculateEarthDistance(seconds);
        double moonDistance = calculateMoonDistance(seconds);
        displayResults(seconds, earthDistance, moonDistance);
    }
    return 0;
}
