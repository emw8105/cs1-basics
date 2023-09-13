// 10_28_driver

/*
A driver is a piece of code to test if a function is correct
A stub is a simplified function used in conjunction with the rest of the
program to test the rest of he program
*/

#include <iostream>

using namespace std;

bool isEven(int num);

int main()
{
    if (isEven(8))
        cout << "The function correctly determined a number is even";
    else
        cout << "The function did not correctly determined a number is even";

    cout << endl;
    if (!isEven(17))
        cout << "The function correctly determined a number is odd";
    else
        cout << "The function did not correctly determined a number is odd";
    return 0;
}

bool isEven(int num)
{
    if (num % 2 == 0)
        return true;
    else
        return false;
}
