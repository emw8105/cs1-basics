/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/1/2021
Purpose of program:
The program receives the accident statistics of 4 different regions and
then offers the user a list of menu choices based on the statistics. The
user can choose to find the region that is the safest based on accident statistics,
find the least safe, or display all of the recorded statistics

*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// function prototypes
int getChoice();
void getAccidentStats(double&, double&, double&, double&); // use reference variables to edit them within the function
void findSafest(double, double, double, double);
void findLeastSafe(double, double, double, double);
void displayAll(double, double, double, double);


int main()
{
    double accidentStatsNorth;
    double accidentStatsSouth;
    double accidentStatsEast;
    double accidentStatsWest;

    // call functions for user inputs with accident statistics for each reason and their menu choice
    getAccidentStats(accidentStatsNorth, accidentStatsSouth, accidentStatsEast, accidentStatsWest);
    int menuChoice = getChoice();

    // switch statement to utilize given user menu choice, call respective function
    switch (menuChoice)
    {
    case 1: // finds the safest region given the accidents statistics for each
        findSafest(accidentStatsNorth, accidentStatsSouth, accidentStatsEast, accidentStatsWest);
        break;

    case 2: // finds the least safe region given the accidents statistics for each
        findLeastSafe(accidentStatsNorth, accidentStatsSouth, accidentStatsEast, accidentStatsWest);
        break;

    case 3: // displays all of the regions and their accident statistics
        displayAll(accidentStatsNorth, accidentStatsSouth, accidentStatsEast, accidentStatsWest);
        break;
    }

    cout << "Exiting" << endl;

    return 0;
}

int getChoice()
{
    int menuChoice;
    cout << "Menu" << endl; // output the menu display with list of options
    cout << "----" << endl;
    cout << "1->Display safest region, 2->Display least safe region, 3->Display all" << endl;
    cin >> menuChoice; // receive user input
    cout << "You entered " << menuChoice << endl;
    if (menuChoice > 3 || menuChoice < 1) // check for invalid input
    {
        cout << "Invalid choice" << endl;
        return -1; // returning negative 1 will
    }
    else
        return menuChoice; // if input is valid, return the user input
}

void getAccidentStats(double& accidentStatsNorth, double& accidentStatsSouth, double& accidentStatsEast, double& accidentStatsWest)
{
    cout << "Enter the accident stats for the North region: "; // prompts user input for accident statistics
    cin >> accidentStatsNorth; // records user input
    if (accidentStatsNorth > 1 || accidentStatsNorth < 0) // input validation
    {
        cout << "Accident stats must be between 0 and 1" << endl; // if input is invalid, exit function
        exit(EXIT_FAILURE);
    }
    else
        cout << "Accident stats entered for the North region is " << accidentStatsNorth << endl;
    cout << "Enter the accident stats for the South region: "; // prompts user input for accident statistics
    cin >> accidentStatsSouth; // records user input
    if (accidentStatsSouth > 1 || accidentStatsSouth < 0) // input validation
    {
        cout << "Accident stats must be between 0 and 1" << endl; // if input is invalid, exit function
        exit(EXIT_FAILURE);
    }
    else
        cout << "Accident stats entered for the South region is " << accidentStatsSouth << endl;
    cout << "Enter the accident stats for the East region: "; // prompts user input for accident statistics
    cin >> accidentStatsEast; // records user input
    if (accidentStatsEast > 1 || accidentStatsEast < 0) // input validation
    {
        cout << "Accident stats must be between 0 and 1" << endl; // if input is invalid, exit function
        exit(EXIT_FAILURE);
    }
    else
        cout << "Accident stats entered for the East region is " << accidentStatsEast << endl;
    cout << "Enter the accident stats for the West region: "; // prompts user input for accident statistics
    cin >> accidentStatsWest; // records user input
    if (accidentStatsWest > 1 || accidentStatsWest < 0) // input validation
    {
        cout << "Accident stats must be between 0 and 1" << endl; // if input is invalid, exit function
        exit(EXIT_FAILURE);
    }
    else
            cout << "Accident stats entered for the West region is " << accidentStatsWest << endl;
}

void findSafest(double accidentStatsNorth, double accidentStatsSouth, double accidentStatsEast, double accidentStatsWest)
{
    // start with largest possible value and compare to each recording the current smallest region
    double smallest = 1.0;
    string region = "";
    if (accidentStatsNorth < smallest) // compare current smallest to North
    {
        smallest = accidentStatsNorth;
        region = "north";
    }
    if (accidentStatsSouth < smallest) // compare current smallest to South
    {
        smallest = accidentStatsNorth;
        region = "south";
    }
    if (accidentStatsEast < smallest) // compare current smallest to East
    {
        smallest = accidentStatsEast;
        region = "east";
    }
    if (accidentStatsWest < smallest) // compare current smallest to West
    {
        smallest = accidentStatsWest;
        region = "west";
    }
    cout << "Region " << region << " is the safest, with " << smallest << " accidents per capita" << endl; // output final smallest region
}

void findLeastSafe(double accidentStatsNorth, double accidentStatsSouth, double accidentStatsEast, double accidentStatsWest)
{
    // start with smallest possible value and compare to each recording the current smallest region
    double largest = 0.0;
    string region = "";
    if (accidentStatsNorth > largest) // compare current largest to North
    {
        largest = accidentStatsNorth;
        region = "north";
    }
    if (accidentStatsSouth > largest) // compare current largest to South
    {
        largest = accidentStatsNorth;
        region = "south";
    }
    if (accidentStatsEast > largest) // compare current largest to East
    {
        largest = accidentStatsEast;
        region = "east";
    }
    if (accidentStatsWest > largest) // compare current largest to West
    {
        largest = accidentStatsWest;
        region = "west";
    }
    cout << "Region " << region << " is the least safe, with " << largest
     << " accidents per capita" << endl;
}

void displayAll (double accidentStatsNorth, double accidentStatsSouth, double accidentStatsEast, double accidentStatsWest)
{
    // displays the region and the corresponding recorded statistics of accidents
    cout << "North region has " << accidentStatsNorth << " accidents per capita" << endl;
    cout << "South region has " << accidentStatsSouth << " accidents per capita" << endl;
    cout << "East region has " << accidentStatsEast << " accidents per capita" << endl;
    cout << "West region has " << accidentStatsWest << " accidents per capita" << endl;
}
