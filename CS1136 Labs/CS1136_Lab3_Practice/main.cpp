#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

string companyName;
int stockShares;
double purchasePrice;
double salePrice;
const double commissionPercentage = 0.035;

cout << fixed;

cout << "Enter the name of the company" << endl;
getline(cin, companyName);
cout << "Enter shares of stock" << endl;
cin >> stockShares;
cout << "Enter purchase price" << endl;
cin >> purchasePrice;
cout << "Enter sale price" << endl;
cin >> salePrice;
double commissionCost = commissionPercentage * (purchasePrice * stockShares);

cout << endl;
cout << "Company: " << companyName << endl;
cout << "Shares: " << stockShares << endl << endl;

cout << "Purchase/share: $" << setprecision(2) << purchasePrice << endl;
cout << "Cost of stock: $" << setprecision(2) << purchasePrice * stockShares << endl;
cout << "Cost of commission: $" << setprecision(2) << commissionCost << endl;
double totalCost = (purchasePrice * stockShares) + commissionCost;
cout << "Total cost: $" << setprecision(2) << totalCost << endl << endl;

cout << "Sale/share: $" << setprecision(2) << salePrice << endl;
cout << "Income from stock: $" << setprecision(2) << salePrice * stockShares << endl;
cout << "Cost of commission: $" << setprecision(2) << (salePrice * stockShares) * commissionPercentage << endl;
double totalIncome = (salePrice * stockShares) - ((salePrice * stockShares) * commissionPercentage);
cout << "Total income: $" << setprecision(2) << totalIncome << endl << endl;
cout << "Gain or loss: $" << setprecision(2) << totalIncome - totalCost << endl;

}
