/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/10/2021
Purpose of program:
The program reads in an upper and a lower value from the
user, and then converts all of the numbers in between the values
into characters by using the ASCII table, and displays them in
a specific format
*/

#include <iostream>

using namespace std;

// function prototype
void read(unsigned int &, unsigned int &);
void display(unsigned int, unsigned int);

int main()
{
    unsigned int lower;
    unsigned int upper;

    read(lower, upper); // calls read function
    display(lower, upper); // calls display function
    return 0;
}

void read(unsigned int & lower, unsigned int & upper)
{
    cout << "Enter lower and upper values" << endl; // prompt user
    cin >> lower >> upper; // read in values appropriately
    while (lower < 32 || upper > 126 || lower > upper) // input validation, keep looping until inputs are valid
    {
        cout << "Values must be in range 32 to 126 inclusive" << endl; // detail input requirements for user
        cout << "Enter lower and upper values" << endl; // prompt user again
        cin >> lower >> upper; // read in values again
    }
}

void display (unsigned int lower, unsigned int upper)
{
    int counter = 0; // used for formatting the displayed characters into columns
    cout << "Characters for ASCII values between " << lower << " and " << upper << endl; // display the range of characters
    cout << "----+----+----+----+";
    while (lower <= upper) // loop until the lower value is greater than the upper value
    {
        if (counter % 20 == 0) // every 20 characters, go down a line to re-align with the + marked columns
        {
            cout << endl;
        }
        cout << static_cast<char>(lower); // output the value casted to a char using the ASCII table
        lower++; // increase lower to move to the next value
        counter++; // increase counter appropriately to track the width of the current row
    }
    cout << endl << "----+----+----+----+" << endl;
}
