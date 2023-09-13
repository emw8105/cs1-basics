// 10_5_menu_check_input

/*
Logical operators operate on boolean expressions
They are:
NOT or NEGATION (!): !A is true is A is false, !A is false if A is true
AND (&&) (A && B) is true if and only if both A and B are true
OR (||) (A || B) is false if and only if both A and B are false
the order of precedence is: NOT, AND, OR

if/else if can be used for menus
trailing else can be used to catch invalid input
Alternatively, can use logical operators to check a value is within a range

*/

#include <iostream>

using namespace std;

int main()
{
    int choice;

    cout << "Menu, enter your choice: " << endl;
    cout << "1 - Chicken" << endl;
    cout << "2 - Beef" << endl;
    cout << "3 - Fish" << endl;
    cout << "4 - Vegan" << endl;

    cin >> choice;

    if (choice == 1)
        cout << "You chose chicken" << endl;
    else if (choice == 2)
        cout << "You chose beef" << endl;
    else if (choice == 3)
        cout << "You chose fish" << endl;
    else if (choice == 4)
        cout << "You chose vegan" << endl;
    else // trailing else
        cout << "Invalid choice" << endl;

    // Menu with input range checking
    cout << "Menu, enter your choice: " << endl;
    cout << "1 - Chicken" << endl;
    cout << "2 - Beef" << endl;
    cout << "3 - Fish" << endl;
    cout << "4 - Vegan" << endl;

    cin >> choice;

    if (choice < 1 || choice > 4)
        cout << "Invalid input" << endl;
    else // Input is valid, no need for trailing else
    {
        if (choice == 1)
            cout << "You chose chicken" << endl;
        else if (choice == 2)
            cout << "You chose beef" << endl;
        else if (choice == 3)
            cout << "You chose fish" << endl;
        else if (choice == 4)
            cout << "You chose vegan" << endl;
    }

    cout << "Enter another choice: ";
    cin >> choice;
    if (choice >=1 && choice <=4)
    {
        if (choice == 1)
            cout << "You chose chicken" << endl;
        else if (choice == 2)
            cout << "You chose beef" << endl;
        else if (choice == 3)
            cout << "You chose fish" << endl;
        else if (choice == 4)
            cout << "You chose vegan" << endl;
    }
    else
        cout << "Invalid input" << endl;
    return 0;
}
