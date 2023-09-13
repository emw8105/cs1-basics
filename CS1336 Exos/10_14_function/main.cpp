// 10_14_function
/*
A function is a module of code that performs a task
The module is packaged in a block of code and is given a name
To execute the task, call the function by its name

A function definition contains
1. Return type: Put void if the function returns nothing
2. Name: Must follow the same naming rules as for variables. Good practice is to
choose meaningful names
3. Parameter list: List of the variables that hold the data passed through the function
(list could be empty)
4. Body: Statements that make up the function

Function Header: First line of the function definition

To process a function call, the compiler needs a minimum of info:
return type, name, parameter list (variable names can be omitted)
That minimum of info is provided in a function prototype

It's recommended to use function prototypes. With the prototypes, you can put the
function definition anywhere in your program. Without prototypes, you must put the
function definitions before the function call

You are not allowed to write a function definition inside another function definition
All the function definitions are at the same level

A function can call another function
*/
#include <iostream>

using namespace std;

// Function prototypes
void printHeader();
int getValue();
double calcAverage(int, int, int); // can leave the name in or take them away
void printResult(double val); // parameter names are ignored by the compiler anyway

int main()
{

    int val1, val2, val3;
    double average;

    // Print welcome message
    printHeader(); // Function call

    // Prompt the user to enter 3 values
    val1 = getValue(); // Function call
    val2 = getValue();
    val3 = getValue();

    // Calculate the average of the three
    average = calcAverage(val1, val2, val3); // val1, val2, val3 are arguents

    // Print result
    printResult(average); // average is an argument

    return 0;
}

// Function definitions

void printHeader()
{
    cout << "Hello, welcome to this program" << endl;
}

int getValue()
{
    int val;
    cout << "Enter a value: ";
    cin >> val;
    return val;
}

double calcAverage(int x, int y, int z) // x, y, z are parameters
{
    double res;
    res = static_cast<double>(x + y + z)/3; // or divide by 3.0
    return res;
}

void printResult(double val) // val is parameter
{
    cout << "Result of average calculation is " << val << endl;

}
