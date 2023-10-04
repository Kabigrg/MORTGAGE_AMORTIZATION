#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
int main()
 
{
string Project2;
cout << " Send the mortgage amortization table to a file (enter a file name): ";
cin >> Project2;

ofstream outFile(Project2);
outFile << setw(45) << right << "MORTGAGE AMORTIZATION TABLE"  << endl;
outFile << endl;
outFile << endl;

 double loanAmount;
    cout << "Enter Loan amount (0-9999999), for example 300000.90: ";
    cin >> loanAmount; 
while (!((loanAmount > 0) && (loanAmount <=9999999)))
{cout << "Enter Loan amount (0-9999999), for example 300000.90: ";
    cin >> loanAmount; }
outFile << "Amount: " << setw(20) << right << "$" << loanAmount << endl;

float Rate;
    cout << "Enter annual interest rate(0-30), for example 4.25 meaning 4.25%:  ";
    cin >> Rate; 
while (!((Rate > 0) && (Rate <= 30)))
{cout << "Enter annual interest rate(0-30), for example 4.25 meaning 4.25%:  ";
    cin >> Rate; }
outFile << "Interest Rate:  " << setw(15) << right << Rate << "%" << endl;

cout << " ######   Assignment 2 Sample Program Copyright - Kabita Gurung  ######" << endl;

int Duration;
    cout << "Enter no. of years as integer(1-99), for example 30: ";
    cin >> Duration; 
while (!((Duration > 1) && (Duration <= 99)))
{cout << "Enter no. of years as integer(1-99), for example 30: ";
    cin >> Duration; }
outFile << "Term(Years): " << setw(16) << right << Duration << endl;

double numberOfPayments = Duration * 12;
double InterestRate = Rate/100;
double monthlyInterestRate = InterestRate/12.0;

double numerator = (loanAmount) * (monthlyInterestRate);
double denominator = (1- 1/pow(1 + monthlyInterestRate, numberOfPayments));
double monthlyPayment = numerator/denominator;
outFile << "Monthly Payment: " << setw(11) << right << "$" << monthlyPayment << endl;

int Principal;
    cout << "Enter additional principal per month (0-9999999), for example 300: ";
    cin >> Principal; 
while (!((Principal > 0) && (Principal <= 9999999)))
{cout << "Enter additional principal per month (0-9999999), for example 300: ";
    cin >> Principal; }
outFile << "Additional Principal: " << setw(6) << right << "$" << Principal << endl;

float ActualPayment = monthlyPayment + Principal;
outFile << "Actual Payment: " << setw(12) << right << "$" << ActualPayment << endl;

outFile << " ######   Assignment 2 Sample Program Copyright - Kabita Gurung  ######" << endl;

outFile << endl;
outFile << endl;
outFile << endl;

outFile << setw(48) << right << "Principal          Interest       Balance" << endl;

double NewBalance = loanAmount;
double NewActualPayment = monthlyPayment + Principal;

        int i = 1; 

        while (NewBalance > 0) {
            double NewInterest = NewBalance * monthlyInterestRate;
            double NewPrincipal = NewActualPayment - NewInterest;
             NewBalance -= NewPrincipal;

    outFile << i << setw(16) << right <<NewPrincipal << setw(16) << right << NewInterest << setw(16) << right << NewBalance << endl;
i++;

}

outFile.close();

return 0;

}
