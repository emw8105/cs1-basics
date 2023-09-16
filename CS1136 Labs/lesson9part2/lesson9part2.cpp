/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/21/2021
Purpose of program:
The program reads in values from a file specified by the
user, then performs input validation. It determines
the average of the valid inputs and then outputs
them to a file
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void read(ifstream& inputFile, int& val, int& inVal, double& average, double num);
void display(ofstream& outputFile, int val, int inVal, double average);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    ofstream invalidOutFile;
    string fileName;
    double num;
    int validNum = 0;
    int invalidNum = 0;
    double average = 0;

    cout << fixed; // turn on decimals

    cout << "Enter input file name" << endl; // prompt user
    cin >> fileName; // read in user input

    inputFile.open(fileName); // attempt to open the specified file of the user
    outputFile.open("output.txt"); // open output file
    invalidOutFile.open("invalid-values.txt"); // open invalid-values output file

    if (inputFile) // check if the input file is valid
    {
        cout << "Reading from file \""<< fileName << "\"" << endl;
        while (inputFile >> num) // loop through the file
        {
            read(inputFile, validNum, invalidNum, average, num); // call read function
            if (num > 105 || num < 0)
            {
                invalidOutFile << num << endl; // if a specific value is invalid, output it to the file
            }
        }
        display(outputFile, validNum, invalidNum, average); // call display function

    }
    else
    {
        cout << "File \"" << fileName << "\" could not be opened" << endl;
    }
    return 0;
}


void read(ifstream& inputFile, int& val, int& inVal, double& average, double num)
{
    //function reads the line of input and performs data validation
    if (inputFile)
    {
        if (num > 105 || num < 0) // check if the number is invalid
        {
            inVal++; // add 1 to the invalid numbers counter
        }
        else // else if the number is valid
        {
            val++; // add 1 to the valid numbers
            average+= num; // add the num to the average
        }
    }

}

void display(ofstream& outputFile, int val, int inVal, double average)
{
    cout << "Total values: " << val + inVal << endl;
    cout << "Invalid values: " << inVal << endl;
    cout << "Valid values: " << val << endl;
    cout << "Average of valid values: " << setprecision(4) << average / val << endl;
    outputFile << "Total values: " << val + inVal << endl;
    outputFile << "Invalid values: " << inVal << endl;
    outputFile << "Valid values: " << val << endl;
    outputFile << "Average of valid values: " << setprecision(4) << average / val << endl;
}
