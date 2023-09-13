// 10_7_switch

/*
switch(expr) can be used to select one among n choices
menu is a typical example
expr must evaluate to an int
the expr that follows the "case" must be a constant int
default is optional, but recommended to catch error cases

Execution will "fall through" (execute the next statement, even if
it is under a different case if there is no "break"

A char can also be used, in which case the ints being handled are the
ASCII codes of the char
*/

#include <iostream>

using namespace std;

int main()
{
    int userChoice;

    cout << "Menu, enter your choice:" << endl;
    cout << "1 - Chicken" << endl;
    cout << "2 - Beef" << endl;
    cout << "3 - Fish" << endl;
    cout << "4 - Vegan" << endl;

    cin >> userChoice;
    const int num = 2;

    switch(userChoice)
    {
    case 1:
        cout << "You chose chicken" << endl;
        break;
    case num: // variable must be constant to use as a case
        cout << "You chose beef" << endl;
        break;
    case 2 + 1:
        cout << "You chose fish" << endl;
        break;
    case 4:
        cout << "You chose vegan" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    // Use a char
    char userChoice2;

    cout << "Menu, enter your choice:" << endl;
    cout << "C - Chicken" << endl;
    cout << "B - Beef" << endl;
    cout << "F - Fish" << endl;
    cout << "V - Vegan" << endl;

    cin >> userChoice2;

        switch(userChoice2)
    {
    case 'C':
        cout << "You chose chicken" << endl;
        break;
    case 'B':
        cout << "You chose beef" << endl;
        break;
    case 'F':
        cout << "You chose fish" << endl;
        break;
    case 'V':
        cout << "You chose vegan" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
    }



    return 0;
}
