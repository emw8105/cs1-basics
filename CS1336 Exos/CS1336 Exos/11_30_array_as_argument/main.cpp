// 11_30_array_as_argument

/*
Parallel arrays: 2 or more arrays of the same size, where elements at the same index
are related
The arrays may be of different types

When an array is passed as argument into a function, the array name (array address)
is passed to the function. The function operates (read/writes) on the original array.
Changes made by the function are made to the original array

The array name does not include the size info --> If the function needs the size info,
you need to provide it in an additional argument

If the function is not supposed to modify the array, a good practice is to use the
"const" qualifier next to the array name in the parameter list.
*/

#include <iostream>
#include <iomanip>

using namespace std;

void printArrayDouble(const double arr[], int arraySize);
double calcTotal(const double arr[], int arraySize);
void resetArray(double arr[], int arraySize, double val);

int main()
{
    const int SIZ = 4;

    // hours, rate and wage are parallel arrays
    int hours[SIZ];
    double rate[SIZ];
    double wage[SIZ];

    for (int i = 0; i < SIZ; i++)
    {
        cout << "Enter hours and rate for employee #"
        << (i + 1) << ": ";
        cin >> hours[i] >> rate[i];
    }

    for (int i = 0; i < SIZ; i++)
    {
        wage[i] = hours[i] * rate[i];
    }

    // Pass array to function
    cout << "Content of wage array" << endl;
    printArrayDouble(wage, SIZ);

    cout << endl << "Total of wages is " << calcTotal(wage, SIZ) << endl;

    // Pass array to function which modifies the array
    cout << endl << "Content of wage array" << endl;
    resetArray(wage, SIZ, 1000000);
    printArrayDouble(wage, SIZ);

    return 0;
}

void printArrayDouble(const double arr[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        cout << arr[i] << endl;
        // arr[0] = 1.5; // This won't compile, array is declared const
}

double calcTotal(const double arr[], int arraySize)
{
    double total = 0;
    for (int i = 0; i < arraySize; i++)
    {
        total += arr[i];
    }
    return total;
}

void resetArray(double arr[], int arraySize, double val)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < arraySize; i++)
        arr[i] = val;
}
