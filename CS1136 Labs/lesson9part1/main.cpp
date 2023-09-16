/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/18/2021
Purpose of program:
The program outputs a graph of sales data for different
stores based on the inputted file. The program does data
validation on the data read in from the file and converts
the numbers into a * based graph format for the user
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool read(ifstream& inputFile, long long int& salesData, unsigned int& storeNum);
void display(ofstream& outputFile, long long int salesData, unsigned int storeNum);

int main()
{
    string fileName;
    unsigned int storeNum;
    long long int salesData;
    ifstream inputFile;
    ofstream outputFile;

    cout << "Enter input file name" << endl; // prompt user
    cin >> fileName; // read in user input


    inputFile.open(fileName); // attempt to open the specified file of the user
    outputFile.open("saleschart.txt"); // open output file
    if (inputFile) // check if the input file is valid
    {
        outputFile << "SALES BAR CHART" << endl; // begin outputting header to output file
        outputFile << "(Each * equals 5,000 dollars)" << endl;
        while (inputFile >> storeNum >> salesData) // loop through the input file
        {
            if (read(inputFile, salesData, storeNum)) // gather line of data and validate input from input file
                display(outputFile, salesData, storeNum); // convert and output to output file
        }
    }
    else
    {
        cout << "File \"" << fileName << "\" could not be opened" << endl; // output error if file can't be opened
    }
    inputFile.close(); // close both files when done
    outputFile.close();


    return 0;
}

bool read(ifstream& inputFile, long long int& salesData, unsigned int& storeNum)
{

    if (inputFile) // check if there is data left in the input file
    {
        if (storeNum < 1 || storeNum > 99) // perform input validation on storeNum
        {
            cout << "The store number " << storeNum << " is not valid" << endl;
        }
        if (salesData < 0) // perform input validation on salesData
        {
            cout << "The sales value for store " << storeNum << " is negative" << endl;
        }
            return true; // if a line of data has been read, return true
    }
    else
    {
        return false; // if all the data has been read, return false
    }
}

void display(ofstream& outputFile, long long int salesData, unsigned int storeNum)
{
    salesData = salesData / 5000; // convert salesData to rounded-down multiples of 5000
    outputFile << "Store " << setw(2) << storeNum << ": "; // set up line of output
    for (int i = 0; i < salesData; i++) // loop through the amount of multiples calculated
    {
        outputFile << "*"; // output a star for each multiple
    }
    outputFile << endl;
}
