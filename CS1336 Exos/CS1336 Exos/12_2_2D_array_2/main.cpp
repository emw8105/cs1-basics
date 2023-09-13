// 12_2_2D_array_2

/*
A 2D array is mapped row by row to the physical memory
To initialize, you can use 1D initialization lists, one for each row
Partial initialization: omitted values will be set to zero

When a 2D array is a function argument, the array name (array address) is passed to the function
The number of columns (2nd dimension) must always be provided in the prototype and function header.

If the function needs to know the number of rows, it must be provided as an additional argument
*/

#include <iostream>
#include <iomanip>

using namespace std;


const int NUM_TESTS = 3;
void print2DArray(double a[][NUM_TESTS], int numRows);

int main()
{
    const int NUM_STUDENTS = 4;


    int student, test;
    double total;

    double arr[NUM_STUDENTS][NUM_TESTS] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}, {100, 110, 120}};
    // Row by row initialization with 1D initialization list

    // Print array
    cout << "Content of arr array" << endl;
    print2DArray(arr, NUM_STUDENTS);

    double score[NUM_STUDENTS][NUM_TESTS] = {{90.5, 91.5, 92.5}, {80.5, 81.5, 82.5}, {70.5}, {}};
    // Partial initialization

    cout << endl << "Content of score array" << endl;
    print2DArray(score, NUM_STUDENTS);

    //Calculate average for a student (row)
    cout << "Enter the student for which you want to calculate the average: ";
    cin >> student;
    total = 0;
    for (int test = 0; test < NUM_TESTS; test++)
        total += score[student - 1][test];
    cout << "Average for student is " << total/NUM_TESTS << endl;


    //Calculate average for a test (column)
    cout << "Enter the test for which you want to calculate the average: ";
    cin >> test;
    total = 0;
    for (int student = 0; student < NUM_STUDENTS; student++)
        total += score[student][test - 1];
    cout << "Average for test is " << total/NUM_STUDENTS << endl;

    // Calculate the average for all tests and all students
    total = 0;
    for (int student = 0; student < NUM_STUDENTS; student++)
    {
        for (int test = 0; test < NUM_TESTS; test++)
            total += score[student][test];
    }
    cout << "Average for all tests and all students is " << total/(NUM_STUDENTS * NUM_TESTS) << endl;


    return 0;
}

void print2DArray(double a[][NUM_TESTS], int numRows)
{
    for (int student = 0; student < numRows; student++)
    {
        for (int test = 0; test < NUM_TESTS; test++)
        {
            cout << setw(7) << a[student][test] << " ";
        }
        cout << endl;
    }
}
