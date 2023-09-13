// 11_16_array

/*
An array is a collection of variables of the same type
Each variable is an element of the array
The elements are stored in adjacent memory locations

To access an element of an array, we provide the array name + subscript (index) value
The first element has index zero

Before you use an array, you must define it: data type, name and number of elements (size declarator)
Good practice: use named constant for the size declarator

An int expression (e.g. variable) can be used for the index value

Three ways to initialize an array:
1. Initialization list with an explicit size declarator (number of values in list = size)
2. Partial initialization: number of values in list < size, the missing values are assumed to be zero
3. Implicit array sizing: No explicit size declarator is provided. The size is derived from the
number of values in the list

Global array (arrays defined outside of any function) are initialized by default to zero
Local arrays (arrays defined inside a function) are not initialized by default
*/

#include <iostream>

using namespace std;

int main()
{
    // Define array
    const int NUM_REGIONS = 4;
    double stats[NUM_REGIONS];

    // Access array elements
    cout << "Enter stats for first region: ";
    cin >> stats[0];

    cout << "Enter stats for second region: ";
    cin >> stats[1];

    cout << "Stats for first region: " << stats[0] << endl;
    cout << "Stats for second region: " << stats[1] << endl;

    // Can use an expression that evaluates to an int for the subscript
    cout << endl << "Array with loop" << endl;

    for (int i = 0; i < NUM_REGIONS; i++)
    {
        cout << "Enter stats: ";
        cin >> stats[i];
    }

    cout << endl << "Content of stats array" << endl;
    for (int i = 0; i < NUM_REGIONS; i++)
    {
        cout << stats[i] << endl;
    }

    // Partial initialization
    const int NUM_TESTS = 6;
    int tests[NUM_TESTS] = {9, 8, 7};

    cout << endl << "Partial Initialization: Content of tests array" << endl;
    for (int i = 0; i < NUM_TESTS; i++)
    {
        cout << tests[i] << endl;
    }

    int testScores[] = {90, 85, 80, 75}; // Implicit array sizing
    int numElements = sizeof(testScores)/sizeof(int);
    cout << endl << "testScores array has " << numElements << " elements" << endl;

    for (int i = 0; i < numElements; i++)
    {
        cout << testScores[i] << endl;
    }

    return 0;
}
