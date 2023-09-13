// 9_23_rand

/*
C++ has a math library, need to #include<cmath>
rand() generates a pseudo random number, but always gives the same
sequence of values
Use srand(seed) to change the sequence of random values
A convenient way to get a different seed value each time is time(0)
rand() gives a random number in the range [0, INT_MAX]]
To generate a random number in a different range, do scaling(%) and shifting(+)
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double x;
    cout << "Enter an argument for square root: ";
    cin >> x;
    cout << "Square root is " << sqrt(x) << endl;

    cout << endl << "5 random numbers: " << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    // Using a seed
    unsigned int seed = time(0);
    cout << "Enter the seed: ";
    cin >> seed;

    cout << "Seed is " << seed << endl;
    srand(seed);

    // Random numbers between 1 and 6
    // % does the scaling, + does the shifting
    int r1 = rand() % 6 + 1;
    int r2 = rand() % 6 + 1;
    int r3 = rand() % 6 + 1;
    int r4 = rand() % 6 + 1;

    cout << r1 << endl << r2 << endl << r3 << endl << r4 << endl;

    return 0;
}
