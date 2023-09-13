/*Author: Evan Wright
Compiler: GNU GCC
Date: 10/2/2021
Purpose of program:
Based on the entered highway number, the program determines the cardinal
direction of travel, whether or not the highway is auxiliary or primary,
and if it is auxiliary then the primary road it services as well.
*/

#include <iostream>

using namespace std;

int main()
{
    int highway; // stores the number of the highway

    cout << "Enter the highway number: ";
    cin >> highway;

    // direction
    if (highway % 2) // when even, remainder is 0, so statement is false
        cout << "The highway goes north/south.\n"; // else, the highway goes north/south
    else
        cout << "The highway goes east/west.\n"; // if highway is even, the highway goes east/west


    // auxiliary and service road status
    if (highway <= 99) // highways greater than 100 are auxiliary
        cout << "I-" << highway << " is primary.\n";
    else // if the highway is auxiliary, additionally state which road it servers
    {
        cout << "I-" << highway << " is auxiliary.\n";
        cout << "The highway serves I-" << (highway%100) << ".\n";
    }

    return 0;
}
