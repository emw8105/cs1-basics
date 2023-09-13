// 11_30_2D_array

/*
A 2D array is logically a table with rows and columns
You define a 2D array by providing the data type, name of the array, number of rows and columns

To identify an element, you provide the array name + 2 indexes: The 1st one for the rows, the
2nd one for the columns. Numbering starts at zero.

To step through the elements, use nested loops
*/

#include <iostream>

using namespace std;

int main()
{
    const int NUM_STUDENTS = 4;
    const int NUM_TESTS = 3;

    double score[NUM_STUDENTS][NUM_TESTS]; // NUM_STUDENTS is the number of rows
    // NUM_TESTS is the number of columns

    for (int stud = 0; stud < NUM_STUDENTS; stud++)
    {
        for (int test = 0; test < NUM_TESTS; test++)
        {
            cout << "Enter score of test #" << (test + 1)
            << " for student #" << (stud + 1) << ": ";
            cin >> score[stud][test];
            cout << endl;
        }
    }

    for (int stud = 0; stud < NUM_STUDENTS; stud++)
    {
        cout << "Scores for student #" << (stud + 1) << endl;
        for (int test = 0; test < NUM_TESTS; test++)
        {
            cout << "Score of test #" << (test + 1)
            << ": " << score[stud][test] << " ";
        }
        cout << endl << endl;
    }


    return 0;
}
