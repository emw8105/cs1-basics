// 11_2_increment_decrement

/*
Increment/decrement operators increment or decrement a variable respectively
You are allowed to use the operators only on a variable
They come in 2 flavors:
- Prefix: When used in an expression, the prefix increment/decrement is applied before
the expression is evaluated (examples of cout, assignment, relational operator)
- Postfix: When used in an expression, the prefix increment/decrement is applied after
the expression is evaluated (examples of cout, assignment, relational operator)
*/

#include <iostream>

using namespace std;

int main()
{
    int num1 = 5;
    int num2 = 10, x;
    int num, res;

    // Basic increment/decrement
    cout << "num1 is " << num1 << endl;
    cout << "Now execute num1++" << endl;
    num1++;
    cout << "After num1++, num1 is " << num1 << endl;

    // Increment/decrement with cout
    cout << endl;
    cout << "num1 is " << num1 << endl;
    cout << "Next we cout << ++num1" << endl;
    cout << ++num1 << endl; // Prefix
    cout << "After cout << ++num1, num1 is " << num1 << endl;
    cout << "Next we cout << num1++" << endl;
    cout << num1++; // Postfix increment
    cout << endl;
    cout << "After cout << num1++, num1 is " << num1 << endl;

    cout << endl << "num2 is " << num2 << endl;
    cout << "Next we cout << --num2" << endl;
    cout << --num2 << endl; // Prefix decrement
    cout << "After cout << --num2, num2 is " << num2 << endl;
    cout << "Next we cout << num2--" << endl;
    cout << num2--; // Postfix decrement
    cout << endl;
    cout << "After cout << num2--, num2 is " << num2 << endl;

    // Increment/decrement with assignment
    cout << endl << "num1 is " << num1 << endl;
    cout << "Now execute x = num1++" << endl;
    x = num1++;
    cout << "After x = num1++, x is " << x << ", num1 is " << num1 << endl;
    cout << "Now execute x = ++num1" << endl;
    x = ++num1;
    cout << "After x = ++num1, x is " << x << ", num1 is " << num1 << endl;

    cout << endl << "num2 is " << num2 << endl;
    cout << "Now execute x = num2--" << endl;
    x = num2--;
    cout << "After x = num2--, x is " << x << ", num2 is " << num2 << endl;
    cout << "Now execute x = --num2" << endl;
    x = --num2;
    cout << "After x = --num2, x is " << x << ", num2 is " << num2 << endl;

    // Increment/decrement with relational operator
    num = 4;
    cout << endl << "num is " << num << endl;
    if (++num == 5)
        cout << "++num is equal to 5" << endl;
    else
        cout << "++num is not equal to 5" << endl;
    cout << "After if (++num == 5), num is " << num << endl;

    num = 4;
    cout << endl << "num is " << num << endl;
    if (num++ == 5)
        cout << "num++ is equal to 5" << endl;
    else
        cout << "num++ is not equal to 5" << endl;
    cout << "After if (num++ == 5), num is " << num << endl;

    // res = (num1 + num2)++; // This won't compile because (num1 + num2) is not a variable

    return 0;
}
