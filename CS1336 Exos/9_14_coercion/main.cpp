// 9_14_coercion

#include <iostream>

using namespace std;

int main()
{
    // Rule #1: char, short, unsigned short are automatically
    // converted to int in a mathematical expression
    cout << 'a' + 1 << endl << 'a' * 'b' << endl;

    // Rule #2: The lower ranked type will be promoted to the higher rank
    // in the same expression
    cout << 10/3.0 << endl;

    // Rule #3: In an assignment, the right hand side is converted to the
    // type of the left hand side (could be a demotion or a promotion)
    double myDouble = 10.9;
    int myInt;
    myInt = myDouble; // Demotion
    cout << "Value of myInt = " << myInt << endl;

    // Coercion is temporary and does not change the type of the original data
    cout << "Size of myDouble = " << sizeof(myDouble) << endl;

    myInt = 5;
    myDouble = myInt; // Promotion
    cout << "Value of myDouble/2 = " << myDouble/2 << endl; // No integer division expected


    return 0;
}

