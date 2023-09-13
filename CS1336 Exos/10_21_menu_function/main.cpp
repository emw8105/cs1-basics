// 10_21_menu_function

/*

*/

#include <iostream>

using namespace std;

void processChicken();
void processBeef();
void processFish();
void processVegan();


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
        processChicken();
    else if (choice == 2)
        processBeef();
    else if (choice == 3)
        processFish();
    else if (choice == 4)
        processVegan();
    else // trailing else
        cout << "Invalid choice" << endl;

    return 0;
}

void processChicken()
{
    cout << "You chose chicken" << endl;
    // Other code, e.g. cook the chicken
}

void processBeef()
{
    cout << "You chose beef" << endl;
    // Other code, e.g. cook the chicken
}

void processFish()
{
    cout << "You chose Fish" << endl;
    // Other code, e.g. cook the fish
}

void processVegan()
{
    cout << "You chose Vegan" << endl;
    // Other code, e.g. cook vegan
}
