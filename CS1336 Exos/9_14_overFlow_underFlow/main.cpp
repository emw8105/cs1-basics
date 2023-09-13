// 9_14_overFlow_underFlow

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int myInt;

    // Overflow
    myInt = INT_MAX; // Assign the max value of an int
    cout << "Max value of an int: " << myInt
         << ", Add 1 to the max value: " << myInt + 1 << endl;

    // Underflow
    myInt = INT_MIN; // Assign the min value of an int
    cout << "Min value of an int: " << myInt
         << ", Subtract 1 from the min value: " << myInt - 1 << endl;

    return 0;
}
