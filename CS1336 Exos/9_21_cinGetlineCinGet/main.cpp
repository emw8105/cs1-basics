// 9_21_cinGetlineCinGet

#include <iostream>

using namespace std;

int main()
{
    string name;
    char ch;

    // getline
    cout << "Enter first name followed by last name: ";
    // cin >> name;
    getline(cin, name);
    cout << "Name entered is " << name << endl;

    // Try to pause the program with cin, won't work
    cout << endl << "Hit enter to continue (use cin): ";
    cin >> ch;
    cout << endl << "Program resumed" << endl;

    // try cin.get
    cout << endl << "Hit enter to continue (use cin): ";
    cin.ignore(); // To get rid of the left over char in the buffer
    // Other options are cin.get, or getline
    cin.get();
    cout << endl << "Program resumed" << endl;

    // Can use cin.get to read one character at a time
    char ch1, ch2, ch3, ch4;
    cout << "\n\nEnter 3 characters, could be a space or a tab, followed by Enter: ";
    cin.get(ch1);
    cin.get(ch2);
    ch3 = cin.get(); // equivalent notation
    ch4 = cin.get();
    cout << "Characters entered are\n"
    << '*' << ch1 << '*' << endl
    << '*' << ch2 << '*' << endl
    << '*' << ch3 << '*' << endl
    << '*' << ch4 << '*' << endl;


    return 0;
}
