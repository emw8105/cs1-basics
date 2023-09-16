/*
This program calculates the amount of days, hours, minutes, and remaining
seconds given an amount of seconds. It will not take an amount of seconds
unless it is greater than 0.
*/

#include <iostream>

using namespace std;

int main()
{
    long long int seconds;
    long long int days;
    long long int hours;
    long long int minutes;
    long long int remainingSeconds;

    cout << "Enter seconds\n"; // prompt the user
    cin >> seconds;
    cout << "Total seconds: " << seconds << endl << endl;
    if (seconds <= 0) { // check if the amount of seconds are greater than 0
        cout << "Total seconds must be greater than zero\n";
    }
    else { // else continue the program
        //only output values if they are more than 0
        if (seconds >= 86400) { // check if there are enough seconds to count a whole day
            days = seconds / 86400;
            seconds = seconds - (days * 86400); // subtract the days to find the remaining seconds
        }
        else {
            days = 0; // if there are not enough seconds, set the amount of days to 0
        }
        if (seconds >= 3600) { // check if there are enough seconds to count a whole hour
            hours = seconds / 3600;
            seconds = seconds - (hours * 3600); // subtract the hours to find the remaining seconds
        }
        else {
            hours = 0; // if there are not enough seconds, set the amount of hours to 0
        }
        if (seconds >= 60) { // check if there are enough seconds to count a whole minute
            minutes = seconds / 60;
            seconds = seconds - (minutes * 60); // subtract the minutes to find the remaining seconds
        }
        else {
            minutes = 0; // if there are not enough seconds, set the amount of minutes to 0
        }
        remainingSeconds = seconds;

        //output corresponding value only if they are greater than 0
        if (days != 0) {
            cout << days << " day(s)" << endl;
        }
        if (hours != 0) {
            cout << hours << " hour(s)" << endl;
        }
        if (minutes != 0) {
            cout << minutes << " minute(s)" << endl;
        }
        if (seconds != 0) {
            cout << seconds << " second(s)" << endl;
        }
    }
    return 0;
}
