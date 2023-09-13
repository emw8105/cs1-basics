/*Author: Evan Wright
Compiler: GNU GCC
Date: 12/1/2021
Purpose of program:
The program accesses a file specified by the user
and collects data elements from the file representing
student record information containing a netID, a major,
and a GPA. The information is displayed back to the user
and then preforms various tasks with the data, such as
finding the highest and lowest GPA among the records,
allows searching of a specific netID to display the
corresponding record, etc.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int populateArrays(string fileName, int netIDArray[], string majorArray[], double gpaArray[], const int ARRAY_SIZE, int& numRecords);

int main()
{
    const int ARRAY_SIZE = 15; // declare array sizes with a constant value
    int netIDArray[ARRAY_SIZE];
    string majorArray[ARRAY_SIZE];
    double gpaArray[ARRAY_SIZE];
    string fileName;
    int numRecords = 0;

    cout << "Enter file name: "; // prompt user and receive input
    cin >> fileName;

    // loop through file and record the elements into respective given arrays
    int result = populateArrays(fileName, netIDArray, majorArray, gpaArray, ARRAY_SIZE, numRecords);
    if (result == 1) // if the function returns 1, then display an error message
    {
        cout << "File \"" << fileName << "\" could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    else // if it doesn't return a 1, then the data reading was successful, so begin outputting data
    {
        cout << "Number of records = " << numRecords << endl << endl;
        cout << "******" << endl << "Part 1" << endl << "******" << endl;
        cout << "NetID array" << endl << "-----------" << endl;
        for (int i = 0; i < numRecords; i++) // loop through the netIDArray and output the data with the correct format
        {
            if ((i+1) % 3 == 0 || (i+1) == numRecords) // check for newline formatting every 3 elements and ignore comma for the last element
            {
                cout << "netIDArray[" << i << "] = " << netIDArray[i];
                cout << endl;
            }
            else // if not the 3rd or last element, continue on the current line separated by a comma
            {
                cout << "netIDArray[" << i << "] = " << netIDArray[i] << ", ";
            }
        }
        cout << endl;
        cout << "Major array" << endl;
        cout << "-----------" << endl;
        for (int i = 0; i < numRecords; i++) // loop through the majorArray and output the data with the correct format
        {
            if ((i+1) % 3 == 0 || (i+1) == numRecords) // check for newline formatting every 3 elements and ignore comma for the last element
            {
                cout << "majorArray[" << i << "] = " << majorArray[i];
                cout << endl;
            }
            else // if not the 3rd or last element, continue on the current line separated by a comma
            {
                cout << "majorArray[" << i << "] = " << majorArray[i] << ", ";
            }
        }
        cout << endl;
        cout << "GPA array" << endl;
        cout << "---------" << endl;
        for (int i = 0; i < numRecords; i++) // loop through the gpaArray and output the data with the correct format
        {
            if ((i+1) % 3 == 0 || (i+1) == numRecords) // check for newline formatting every 3 elements and ignore comma for the last element
            {
                cout << "gpaArray[" << i << "] = " << gpaArray[i];
                cout << endl;
            }
            else // if not the 3rd or last element, continue on the current line separated by a comma
            {
                cout << "gpaArray[" << i << "] = " << gpaArray[i] << ", ";
            }
        }
        // search for highest and lowest gpa by index
        double highest = 0.0; // variables store the current highest/lowest value
        int highestIndex = 0; // and the corresponding index for the value
        double lowest = 4.0;
        int lowestIndex = 0;
        for (int i = 0; i < numRecords; i++) // loop through the elements in the gpaArray
        {
            if (gpaArray[i] > highest) // check if the current element is greater than the currently recorded highest value
            {
                highest = gpaArray[i]; // if true, make that element the new highest
                highestIndex = i; // record the corresponding index
            }
            if (gpaArray[i] < lowest) // check if the current element is lesser than the currently recorded lowest value
            {
                lowest = gpaArray[i]; // if true, make that element the new lowest
                lowestIndex = i; // record the corresponding index
            }
        }
        // output the results of the highest/lowest GPA student records
        cout << endl << "Lowest GPA" << endl << "----------" << endl;
        cout << "NetID is " << netIDArray[lowestIndex] << ", major is " << majorArray[lowestIndex] << ", GPA = " << gpaArray[lowestIndex] << endl;
        cout << endl << "Highest GPA" << endl << "-----------" << endl;
        cout << "NetID is " << netIDArray[highestIndex] << ", major is " << majorArray[highestIndex] << ", GPA = " << gpaArray[highestIndex] << endl;

        int givenNetID = 0;
        int netIDIndex = -1;

        cout << endl << "Search on student's netID" << endl << "-------------------------" << endl;
        cout << "Input student's netID, -1 to quit: "; // prompt user and receive input
        cin >> givenNetID;
        while (givenNetID != -1) // once the student enters -1, the loop is either skipped or exited
        {
            netIDIndex = -1; // placeholder index value, if entered value is not found in the array then -1 is used to confirm the netID does not exist
            for (int i = 0; i < numRecords; i++) // loop through the netIDArray
            {
                if (netIDArray[i] == givenNetID) // if the current element in the array is what the user entered, record the index of the element
                {
                    netIDIndex = i;
                }
            }
            if (netIDIndex == -1) // if the element was not found in the array
            {
                cout << "NetID not found" << endl;
            }
            else // the netID was found in the array, output the student record of the corresponding student
            {
                cout << "NetID is " << netIDArray[netIDIndex] << ", major is " << majorArray[netIDIndex] << ", GPA = " << gpaArray[netIDIndex] << endl;
            }

            cout << endl;
            cout << "Input student's netID, -1 to quit: "; // repeat prompt to allow user to exit or search for another netID
            cin >> givenNetID;
        }
    }
    return 0;
}

int populateArrays(string fileName, int netIDArray[], string majorArray[], double gpaArray[], const int ARRAY_SIZE, int& numRecords)
{
    ifstream inputFile;
    int counter = 0;
    inputFile.open(fileName); // attempt to open the file specified by the user
    if (inputFile.fail()) // Test for file open failure
    {
        return 1; // if the file opening fails, the 1 tells the main function to output an error
    }
    else
    {
        // if the file opening was successful, copy the file values into the arrays
        while (counter < ARRAY_SIZE && inputFile >> netIDArray[counter] >> majorArray[counter] >> gpaArray[counter])
        {
            counter++; // use to track the amount of elements copied
        }
        if (counter <= ARRAY_SIZE) // using the reference variable, return either the amount of elements copied or the max array capacity
        {
            numRecords = counter;
        }
        else
        {
            numRecords = ARRAY_SIZE;
        }
        inputFile.close(); // close the file when done
    }
    return 0;
}
