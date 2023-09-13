/*Author: Evan Wright
Compiler: GNU GCC
Date: 11/15/2021
Purpose of program:
The program uses pre-downloaded files with a list of
recorded employee hours and wages to determine which
is the highest salary, lowest salary, and average salary
of chosen files.
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <iomanip>

using namespace std;

bool highestSalary (string, double&);
bool lowestSalary (string, double&);
bool avgSalary (string, double&);

int main()
{
    string fileName;
    double val;
    cout << "Enter input file name: "; // prompt user
    cin >> fileName; // receive input

    highestSalary(fileName, val); // find the highest salary recorded in the read in file

    cout << "Enter input file name: "; // prompt user
    cin >> fileName; // receive input

    lowestSalary(fileName, val); // find the lowest salary recorded in the read in file

    cout << "Enter input file name: "; // prompt user
    cin >> fileName; // receive input

    avgSalary(fileName, val); // find the average of the salaries recorded in the read in file

    return 0;
}

bool highestSalary (string fileName, double& val)
{
    double salary;
    double hours;
    double wage;
    double highestSal = INT_MIN; // set to the lowest possible value
    ifstream inFile; // declare file object
    inFile.open(fileName); // open the file specified by the user
    if (inFile.fail() || !(inFile >> hours >> wage)) // test for file open failure or empty file
    {
        cout << "Invalid file" << endl << endl;
        inFile.close();
        return false;
    }
    else
    {
        inFile.close();
        inFile.open(fileName);
        while (inFile >> hours >> wage) // loop through the file
        {
            salary = wage * hours; // multiply the values given to find the salary
            if (highestSal < salary) // check if the current salary is higher than the current highest recorded salary
            {
                highestSal = salary; // if it is higher, set the current highest recorded salary to be the salary in question
            }
        }
    }
    val = highestSal; // set the highest salary to val to send it back by reference
    cout << "Highest salary is " << val << endl << endl; // output
    inFile.close(); // close the file
    return true;
}

bool lowestSalary(string fileName, double& val)
{
    double salary;
    double hours;
    double wage;
    double lowestSal = INT_MAX; // set to be the highest possible value
    ifstream inFile; // declare file object
    inFile.open(fileName); // open the file specified by the user
    if (inFile.fail() || !(inFile >> hours >> wage)) // test for file open failure or empty file
    {
        cout << "Invalid file" << endl << endl;
        inFile.close();
        return false;
    }
    else
    {
        inFile.close();
        inFile.open(fileName);
        while (inFile >> hours >> wage) // loop through the file
        {
            salary = wage * hours; // multiply the values given to find the salary
            if (lowestSal > salary) // if the current salary is lower than the lowest recorded salary
            {
                lowestSal = salary; // set the lowest recorded salary to be the current salary
            }
        }
    }
    val = lowestSal; // set val to the lowest salary to pass back by reference
    cout << "Lowest salary is " << val << endl << endl; // output
    inFile.close(); // close the file
    return true;
}

bool avgSalary (string fileName, double& val)
{
    // double salary;
    double hours;
    double wage;
    double average = 0;
    int counter = 0;
    ifstream inFile; // declare file object
    inFile.open(fileName); // open the file specified by the user
    if (inFile.fail() || !(inFile >> hours >> wage)) // test for file open failure or empty file
    {
        cout << "Invalid file" << endl << endl;
        inFile.close();
        return false;
    }
    else
    {
        inFile.close();
        inFile.open(fileName);
        while (inFile >> hours >> wage) // loop through the file
        {
            average += (hours * wage); // multiply and add up the values given to find the total salary
            counter++; // record the amount of values added to divide by to find average
        }
    }
    val = average / counter; // find the average and set it to val to pass it back by reference
    cout << "Average salary is " << setprecision(6) << val << endl; // output
    inFile.close(); // close the file
    return true;
}
