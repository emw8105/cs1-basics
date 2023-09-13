// 11_18_array_processing

/*
Going out of bounds: when your index values are not in the range of the array
The complier will not give an error
Effect is unpredictable: program may freeze, crash, have elusive bugs, etc.

An array name is the address of the array
For an array of chars, when cout << arrName is executed, it will print from the 1st character, then
go to the next char, until a null terminator is found
To store a properly formatted C-string, you need a null terminator at the end

For an array on non-chars, when cout << arrName is executed, it will print the starting address of the array

To print the array content, use a loop
Use a loop to print the content, calculate average, sum, find the lowest/highest value

Partially filled array: When you don't know the size you need, you can oversize the array.
The array may be partially filled. You need to maintain a counter to track the number of
actual values in the array
*/

#include <iostream>

using namespace std;

int main()
{
    // Going out of bounds
    const int ARR_SIZE = 5;
    int arr[ARR_SIZE];

    // for (int i = 0; i < ARR_SIZE + 100000; i++) // This goes out of bounds
    for (int i = 0; i < ARR_SIZE; i++)
        arr[i] = 500;

    cout << endl;
    for (int i = 0; i < ARR_SIZE; i++)
        cout << arr[i] << " ";

    // Array name is the address of the array
    const int NUM_SCORES = 3;
    int arr1[] = {9, 8, 7};
    // char arr2[] = {'H', 'e', 'n', 'r', 'y'}; // Array of chars but not a C-string
    char arr2[] = {'H', 'e', 'n', 'r', 'y', '\0'};
    char arr3[] = "Henry"; // Equivalent way to initialize

    cout << endl;
    cout << "cout char array2 name: " << arr2 << endl;
    cout << "cout char array3 name: " << arr3 << endl;
    cout << "cout non-char array name: " << arr1 << endl;

    // Calculate the average
    double scores[NUM_SCORES] = {9.1, 9.2, 9.3};
    double total = 0, avg;
    for (int i = 0; i < NUM_SCORES; i++)
        total += scores[i];
    avg = total / NUM_SCORES;
    cout << endl << "Average is " << avg << endl;

    // Find lowest
    double lowest = scores[0];
    for (int i = 0; i < NUM_SCORES; i++)
    {
        if (lowest > scores[i])
            lowest = scores[i];
    }
    cout << "Lowest value is " << lowest << endl;

    // Partially filled array
    const int SIZ =  4;
    double scores2[SIZ];
    double score;
    int index = 0;

    cout << endl << "Enter a score, -1 if done: ";
    cin >> score;
    while (score != -1 && index < SIZ)
    {
        scores2[index] = score;
        cout << endl << "Enter a score, -1 if done: ";
        cin >> score;
        index++;
    }

    cout << endl << "Content of scores array" << endl;
    for (int i = 0; i < index; i++)
        cout << scores2[i] << endl;

    return 0;
}
