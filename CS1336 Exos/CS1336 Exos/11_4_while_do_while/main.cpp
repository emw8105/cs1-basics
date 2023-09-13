// 11_4_while_do_while

/*
while(expr) loop is the first type of loop in C++
The while loop is a pretest loop, because it tests before the loop execution
As long as the expression is true, stay in the loop
If the first evaluation of expr is false, the loop is never entered
No semi-colon after the while

Can use the while loop for input validation

do-while is the 2nd type of loop
Start by executing the loop once, then evaluate expr (posttest loop)
A do-while is always executed at least once
If expr is true, stay in the loop. If expr is false, exit the loop
Must have a semi-colon after the while
*/
#include <iostream>

using namespace std;

int main()
{
    const int MAX_REATTEMPTS = 3;
    int numEmployees, emplCount;
    int numAttempts = 0;
    double hours, rate, salary;
    int choice;

    cout << "Enter number of employees: ";
    cin >> numEmployees;

    while (numEmployees <= 0 && numAttempts < MAX_REATTEMPTS)
    {
        cout << "Enter number of employees: ";
        cin >> numEmployees;
        numAttempts++;
    }

    if (numEmployees <= 0)
        cout << "Too many attempts, give up" << endl;
    else // Input is valid
    {
        emplCount = 0;
        while (emplCount < numEmployees)
        {
            cout << "Enter hours and rate: ";
            cin >> hours >> rate;
            salary = hours * rate;
            cout << "Salary is " << salary << endl;
            emplCount++;
        }
    }

    // do-while

    do
    {
        cout << "Make your choice: 1-> Chicken, 2-> Beef, 3->Vegan, 4->Quit:";
        cin >> choice;
        cout << "Your choice is " << choice << endl;
    } while (choice != 4);



    return 0;
}
