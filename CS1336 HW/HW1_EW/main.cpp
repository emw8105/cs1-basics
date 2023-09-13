#include <iostream>

using namespace std;

int main()
{
    char p = '#'; // stores the pound sign
    char s = ' '; // stores a space

    // output 1
    cout << s << s << s << p << endl;
    cout << s << s << p << p << p << endl;
    cout << s << p << p << p << p << p << endl;
    cout << p << p << p << p << p << p << p << endl;
    cout << endl;
    cout << p << p << endl;
    cout << p << p << endl;
    cout << p << p << endl;
    cout << endl;



    // output 2
    p = '*';
    cout << s << s << s << p << endl;
    cout << s << s << p << p << p << endl;
    cout << s << p << p << p << p << p << endl;
    cout << p << p << p << p << p << p << p << endl;
    cout << endl;
    cout << p << p << endl;
    cout << p << p << endl;
    cout << p << p << endl;
    cout << endl;

    return 0;
}
