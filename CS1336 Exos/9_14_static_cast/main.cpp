// 9_14_static_cast

/*
With type cast, the programmer can explicitly change the data type
*/

#include <iostream>

using namespace std;

int main()
{
    // First example: avoid integer division
    int numberBooks, numberMonths;

    cout << "Enter the number of books you read: ";
    cin >> numberBooks;
    cout << "Enter the number of months: ";
    cin >> numberMonths;

    cout << "On average, you read " << static_cast<double>(numberBooks)/numberMonths
    << " books per month" << endl;

    // Second example: convert between ASCII code and char
    cout << "ASCII code of a is = " <<  static_cast<int>('a') << endl;
    cout << "Char having ASCII = 98 is " << static_cast<char>(98);

    return 0;
}
