// 10_7_scope

/*
The scope of a variable is the part of the program where you can access the variable
The scope begins when the variable is defined and ends at the end of the block of code
where it is defined

Can define a variable in an inner block which has the same name as a variable in the outer block,
but they are different variables (try to avoid in general)
When the scopes overlap, the inner block variable hides the outer block variable
*/

#include <iostream>

using namespace std;

int main()
{
    int num; // outer block variable

    cout << "In outer block, enter a number to be stored in num: ";
    cin >> num;
    cout << "Value stored in num is " << num << endl;

    if (1)
    {
        int num;
        cout << "In inner block, enter another number to be stored in num: ";
        cin >> num;
        cout << "Value stored in num is " << num << endl;
    }

    cout << "Back in outer block, value stored in num is " << num << endl;


    return 0;
}
