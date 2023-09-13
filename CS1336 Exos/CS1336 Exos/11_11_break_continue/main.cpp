// 11_11_break_continue

/*
When a break statement inside a loop is executed, the program exists the loop
unconditionally
When a continue statement inside a loop is executed, the program goes to the end of the
loop and prepares for the next iteration
Use them sparingly, they make the code harder to understand
The while loop and for loop are not necessarily equivalent when there is a continue
*/

#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    cout << "While loop w/o break and w/o continue" << endl;
    while (num < 5)
    {
        num++;
        cout << "num = " << num << endl;
    }

    num = 0;
    cout << endl << "While loop with break" << endl;
    while (num < 5)
    {
        num++;
        if (num == 3)
            break;
        cout << "num = " << num << endl;
    }

    num = 0;
    cout << endl << "While loop with continue" << endl;
    while (num < 5)
    {
        num++;
        if (num == 3)
            continue;
        cout << "num = " << num << endl;
    }

    // While loop and for loop are not necessarily equivalent
    // when there is continue
    cout << endl;
    for (num = 1; num < 6; num++)
    {
        cout << "num = " << num << endl;
        if (num == 3)
            continue;
    }

    num = 1;
    while (num < 6)
    {
        cout << "num = " << num << endl;
        // if (num == 3) // Loop forever if uncommented
           // continue;
        num++;
    }



    return 0;
}
