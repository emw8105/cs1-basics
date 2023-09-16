/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/29/2021
Purpose of program:
The program takes file inputs of student recorded answers on an exam
and a corresponding answer key as specified by the user. The program
puts the file elements into an array to determine the total amount of
questions missed by comparing the arrays, and finding the corresponding
grade. The program displays the question missed and the correct answer
for that specific question, the student's grade, and whether or not the
student passed.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int read (char answersArray[30], string fileName);
void work (char studentArray[], char answerArray[], int studentNumVal, int answerNumVal);

int main()
{
    const int arraySize = 30;
    char studentList[arraySize]; // parallel arrays declared with same subscript
    char answerList[arraySize];
    string studentFileName;
    string answerFileName;
    ifstream studentFile;
    ifstream answersFile;
    int studentNumVal;
    int answerNumVal;

    cout << fixed;

    cout << "Enter student answers file name" << endl; // prompt user
    cin >> studentFileName; // receive input

    studentNumVal = read(studentList, studentFileName);

    cout << "Enter correct answer file name" << endl; // prompt user
    cin >> answerFileName; // receive input

    answerNumVal = read(answerList, answerFileName);

    if (studentNumVal != answerNumVal) // if the number of elements in the arrays are not equal
    {
        cout << "The student answers file has " << studentNumVal // output error and exit program
        << " entries and the correct answers file has " << answerNumVal << " entries" << endl;
        cout << "Grading cannot be done if they are not the same" << endl;
        exit(EXIT_FAILURE);
    }
    if (studentNumVal == 0 && answerNumVal == 0) // if there are no elements in the arrays

    {
        cout << "The number of student answers and correct answers are both 0" << endl; // display output
        cout << "No grade can be calculated" << endl;
        exit(EXIT_FAILURE);
    }

    work(studentList, answerList, studentNumVal, answerNumVal);

    return 0;
}

// performs input validation, if successful then puts file elements into given array and returns the number of elements
int read (char givenArray[30], string fileName)
{
    int counter = 0;
    ifstream inputFile;
    inputFile.open(fileName); // attempts to open the file specified by the user
    if (inputFile.fail()) // Test for file open failure
    {
        cout << "File \"" << fileName << "\" could not be opened" << endl; // if file fails, display error and exit
        exit(EXIT_FAILURE);
    }
    while (counter < 30 && inputFile >> givenArray[counter]) // if file is successful, loop through file and put elements into the array
    {
        counter++;
    }
    inputFile.close(); // close file when done
    if (counter < 30) // if there were less than 30 elements, return the number of elements
    {
        return counter;
    }
    else // if there were 30 or more elements, return 30
    {
        return 30;
    }
}

// loops through the arrays to determine number of questions missed to calculate the grade
void work (char studentArray[], char answerArray[], int studentNumVal, int answerNumVal)
{
    int counter = 0;
    double grade = 0;
    for (int i = 0; i < studentNumVal; i++) // loop through the array
    {
        if (studentArray[i] != answerArray[i]) // check the answer, if it was incorrect display the question # and correct answer
        {
            cout << "Question " << (i + 1) << " has incorrect answer '" << studentArray[i] << "', "
            << "the correct answer is '" << answerArray[i] << "'" << endl;
            counter++; // records the number of incorrect answers
        }
    }
    cout << counter << " questions were missed out of " << answerNumVal << endl; // output total incorrect questions
    grade = (static_cast<double>(answerNumVal - counter) / answerNumVal) * 100; // calculate the grade
    cout << "The student grade is " << setprecision(1) << grade << '%' << endl; // output grade
    if (grade >= 70) // check if student passed based on calculated grade
    {
        cout << "The student passed" << endl;
    }
    else
    {
        cout << "The student failed" << endl;
    }
}
