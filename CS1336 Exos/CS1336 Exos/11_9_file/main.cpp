// 11_9_file

#include <iostream>
#include <fstream> // Needed for file I/O

using namespace std;

int main()
{
    int netID;
    double GPA;

    // Write to a file
    ofstream outFile; // Define a file stream object for output

    outFile.open("out.txt");

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

    inFile.open("in.txt");

    if (inFile.fail()) // Test for file open failure
    {
        cout << "Could not open input file" << endl;
        exit(EXIT_FAILURE);
    }



    return 0;
}
