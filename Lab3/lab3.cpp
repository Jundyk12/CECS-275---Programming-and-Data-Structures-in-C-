#include <iostream>
#include <iomanip> // Required for "set(w)", and "right" and "left"
#include <cmath>

using namespace std;

int main(){

    //Input data
    double principal = 0;
    cout << "Loan Amount (principal) in dollars? "; 
    cin >> principal;

    double annual;
    cout << "Annual interest rate (as percentage, e.g., 5 for 5%)? ";
    cin >> annual;

    double loan;
    cout << "Loan term in years? ";
    cin >> loan;

    //converting and calculation
    double r;
    int n;

    r = (annual / 100.0) / 12.0;     //Monthly rate
    n = loan * 12;                   //Number of months

    double total;
    total = principal * (r * pow(1+r, n)) / (pow(1 + r, n) - 1);   
    cout << "The monthly mortgage payment is $" << total << endl;

    return 0;



}
