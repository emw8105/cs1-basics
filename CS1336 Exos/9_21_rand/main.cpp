// 9_21_rand

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

    cout << endl << "5 random numbers: " << endl;

    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    return 0;
}
