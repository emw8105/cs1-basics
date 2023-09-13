// 11_11_file

/*
A file can be a text file or a binary file
A file can be sequential access or random access

In a sequential access file, to access a data item, you have to
access first all the items that come before it.
In a random access file, you can jump directly to the desired data item

We focus on sequential access text files.


A program interacts (read/write) with a file through a file stream object
that you have to create

There are 3 types of file stream objects:
ifstream (input only), ofstream (output only) and fstream (input and output)

Steps:
Open the file
Use the file
Close the file

You should check if the open failed using
if(!fileStreamObject) or if(fileStreamObject.fail())

The stream extraction operator >> will return false if the read has an error.
A read when there is no data gives an error. We can use it in a while loop
to read until the end of the file

When while(inFile >> var) is executed, the read is actually performed and false
is returned if there is no more data
*/

#include <iostream>
#include <fstream> // Needed for file I/O

using namespace std;

int main()
{
    int netID;
    double GPA;
    string fileName;

    // Write to a file
    ofstream outFile; // Define a file stream object for output

    cout << "Enter the file name: ";
    cin >> fileName;

    outFile.open(fileName);

    if (outFile.fail()) // Test for file open failure
    {
        cout << "Could not open output file" << endl;
        exit(EXIT_FAILURE);
    }

    // File open is successful
    cout << "Enter a netID to write into the file, -1 if done: ";
    cin >> netID;
    while (netID != -1)
    {
        cout << "Enter a GPA: ";
        cin >> GPA;
        outFile << netID << ' ' << GPA << endl;
        cout << "Enter a netID to write into the file, -1 if done: ";
        cin >> netID;
    }
    outFile.close();

    // Read from a file
    ifstream inFile; // Define a file stream object for input

    cout << "Enter the file name: ";
    cin >> fileName;

    inFile.open(fileName);

    if (inFile.fail()) // Test for file open failure
    {
        cout << "Could not open input file" << endl;
        exit(EXIT_FAILURE);
    }

    // File open is successful
    while(inFile >> netID)
    {
        inFile >> GPA;
        cout << "netID and GPA read from file "
        << fileName << ": " << netID << " " << GPA << endl;
    }

    inFile.close();


    return 0;
}
