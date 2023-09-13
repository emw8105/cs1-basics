// 10_28_pass_by_reference

/*
When pass by reference, the called function accesses the original variables in the calling
function, not copies
The called function is passed the address of the original variable (reference variable)
With pass by reference, the called function is able to pass back more than one item
of data. This overcomes the limitation of the return statement which can pass back only one item
Argument passed by reference must have a memory address, i.e. must be a variable
Use when appropriate: don't use if the argument should not be changed by the function, or if
the return statement is enough
*/

#include <iostream>
#include <cmath>

using namespace std;

void resetVar(int num);
void resetVarByRef(int & num);
void convertCoordinates(double angle, double length, double & x, double & y);

int main()
{

    int myInt = 100;

    resetVar(myInt);
    cout << "After resetVar, myInt = " << myInt << endl;

    resetVarByRef(myInt);
    cout << "After resetVarByRef, myInt = " << myInt << endl;


    // Example use of reference variables: to return more than one value
    double myAngle, myLength, xCoord, yCoord;

    cout << "Enter the angle and the length: ";
    cin >> myAngle >> myLength;
    cout << "Angle and length are " << myAngle << ", " << myLength << endl;
    convertCoordinates(myAngle, myLength, xCoord, yCoord);
    cout << "x and y coordinates are " << xCoord << ", " << yCoord << endl;
    return 0;
}

void resetVar(int num) // Pass by value
{
    cout << "Inside resetVar, num = " << num << endl;
    num = 0;
}

void resetVarByRef(int & num) // Pass by reference
{
    cout << "Inside resetVarByRef, num = " << num << endl;
    num = 0;
}

void convertCoordinates(double angle, double length, double & x, double & y)
// angle and length are passed by value, x and y are passed by reference
{
    x = length * cos(angle);
    y = length * sin(angle);
    // local variables are not destroyed because they are references/aliases to xCoord and yCoord variable
}
