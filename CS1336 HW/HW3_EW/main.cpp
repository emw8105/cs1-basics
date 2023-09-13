/*Author: Evan Wright
Compiler: GNU GCC
Date: 9/22/2021
Purpose of program:
To calculate the gross profit and profit shares of a movie theater and the movie distributor
by using the inputted number of adult and child tickets and outputting it along with the
movie name, location of the theater, and the various portions of the gross income generated
from the movie's revenue
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string movieTitle;
    int numAdultTickets;
    const double adultPrice = 11.75;
    int numChildTickets;
    const double childPrice = 6.55;
    const double grossProfitPercentage = 0.20;
    string theaterLocation;

    cout << fixed; // turn on decimals

    cout << "Please enter the movie title: "; //prompt to user for inputs to store
    getline(cin, movieTitle); // use getline so spaces will be saved
    cout << "Movie title is " << movieTitle << endl;

    cout << "Please enter the number of adult tickets sold: ";
    cin >> numAdultTickets; // store inputted number of adult tickets
    cout << "Number of adult tickets sold is " << numAdultTickets << endl;

    cout << "Please enter the number of child tickets sold: ";
    cin >> numChildTickets; // store inputted number of child tickets
    cout << "Number of child tickets sold is " << numChildTickets << endl;

    cout << "Please enter the theater's location: ";
    cin.ignore(); // flush the buffer
    getline(cin, theaterLocation); // use getline to spaces will be saved
    cout << "Theater location is " << theaterLocation << endl;

    double grossProfit = ((numAdultTickets * adultPrice) + (numChildTickets * childPrice));
    // gross profit is the total revenue gained from all ticket sales

    cout << "Gross profit is $" << setprecision(2) << grossProfit << endl;
    cout << "Net profit is $" << setprecision(2) << grossProfit * grossProfitPercentage << endl;
    //Net theater profit is 20% of the gross profit
    cout << "Distributor profit is $" << setprecision(2) << grossProfit * (1 - grossProfitPercentage) << endl << endl;
    //Distributor profit is the remaining 80% of the gross profit

    cout << "Revenue Report" << endl;
    cout << "==============" << endl;

    //double x = 146.789, y = 24.2;
   //cout << setw(40) << "This text is right justified" << endl;
   //cout << setw(40) << left << "This text is left justified" << right << setw(8) << x << endl;
   //cout << setw(40) << left << "This is another left justified text" << right << setw(8) << y << endl;

    cout << setw(28) << left << "Movie Title: " // begin building the table to display the information
         << setw(10) << movieTitle << endl; // output the movie title
    cout << setw(28) << left << "Theater Location: "
         << setw(10) << theaterLocation << endl; // output the theater location
    cout << setw(28) << left << "Adult Tickets Sold: " << right
         << setw(9) << numAdultTickets << endl; // output the number of adult tickets
    cout << setw(28) << left << "Child Tickets Sold: " << right
         << setw(9) << numChildTickets << endl; // output the number of child tickets
    cout << setw(28) << left << "Gross Box Office Profit: " << right
         << '$' << setw(7) << setprecision(2) << grossProfit << endl; // output the gross profit
    cout << setw(28) << left << "Net Box Office Profit: " << right // output the theater net profit
         << '$' << setw(8) << setprecision(2) << (grossProfit * grossProfitPercentage) << endl;
    cout << setw(28) << left << "Amount Paid to Distributor: " << right // output the distributor profit portion
         << '$' << setw(7) << setprecision(2) << (grossProfit * (1 - grossProfitPercentage)) << endl;

    return 0;
}
