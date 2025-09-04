/*

*This C++ program calculate the monthly mortgage 
*CECS 275 - Fall 2025 
*@author Jundy Kato
*@author Ivan Tran
*@version 1.0.0

*/


#include <iostream>
#include <iomanip> // Required for "set(w)", and "right" and "left"
#include <cmath>

using namespace std;

int main(){

    //Setting all to two decimal places
    cout << fixed << setprecision(2);

    //Input data
    double principal = 0;
    cout << "Loan Amount (principal) in dollars? "; 
    cin >> principal;

    double annual,loan;
    cout << "Annual interest rate (as percentage, e.g., 5 for 5%)? ";
    cin >> annual;

    cout << "Loan term in years? ";
    cin >> loan;

    //converting and calculation
    double r, total;
    int n;

    r = (annual / 100.0) / 12.0;     //Monthly rate
    n = loan * 12;                   //Number of months

    total = principal * (r * pow(1+r, n)) / (pow(1 + r, n) - 1);   
    cout << "The monthly mortgage payment is $" << total << endl;

    return 0;

    /*
    Case 1:
    Principal = 200000
    Rate = 5
    Years = 30
    Total = $1073.64

    Case 2:
    Principal = 100000
    Rate = 4
    Years = 15
    Total = $739.69

    Case 3:
    Principal = 250000
    Rate = 4
    Years = 15
    Total = $1122.61

    Case 4:
    Principal = 300000
    Rate = 6
    Years = 30
    Total = $1798.65

    Case 5:
    Principal = 150000
    Rate = 0
    Years = 30
    Total = $416.67

    Case 6:
    Principal = 50000
    Rate = 5
    Years = 10
    Total = $530.33


    Case 7:
    Principal = 120000
    Rate = 7
    Years = 20
    Total = $930.87

    Case 8:
    Principal = 350000
    Rate = 4.25
    Years = 30
    Total = $1721.79

    Case 9:
    Principal = 180000
    Rate = 3
    Years = 15
    Total = $1243.74

    Case 10:
    Principal = 75000
    Rate = 6.5
    Years = 10
    Total = $852.16

    */
}
