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

    //Input data from user

    //principal of the amount of the loan
    double principal_amount = 0;
    cout << "Loan Amount (principal) in dollars? "; 
    cin >> principal_amount;

    double annual_rate,loan_years;

    //How many years of the loan
    cout << "Loan term in years? ";
    cin >> loan_years;

    //Interest rate
    cout << "Annual interest rate (as percentage, e.g., 5 for 5%)? ";
    cin >> annual_rate;

    //Declaring and converting
    double monthly_rate, monthly_payment, interest_paid, interest_total;
    int total_number_payments;

    monthly_rate = (annual_rate / 100.0) / 12.0;     //Monthly rate
    total_number_payments = loan_years * 12;        //calculating total number of payment:

    //Calculating the monthly mortgage payment
    monthly_payment = principal_amount * (monthly_rate * pow(1+monthly_rate, total_number_payments)) / (pow(1 + monthly_rate, total_number_payments) - 1);   
    //calculating total interest paid:
    interest_total = monthly_payment * total_number_payments;
    interest_paid = interest_total - principal_amount;

    //Show the all input data back:
    cout << "Loan Amount: " << principal_amount << endl;
    cout << "Interest Rate: " << annual_rate << endl;
    cout << "Loan term: " << loan_years << endl;
    cout << "Total interest paid: " << interest_paid << endl;
    cout << "Total number of payment: " << total_number_payments << endl;
    cout << "Monthly payment $: " << monthly_payment << endl;


    return 0;

    /*
    Case 1:
    Principal = 200000
    Rate = 5
    Years = 30
    Total = $1073.64

    Case 2:
    Principal = -100000
    Rate = 4
    Years = -15
    Total = $-1507.80

    Case 3:
    Principal = 250000
    Rate = -4
    Years = 15
    Total = $-3832.69

    Case 4:
    Principal = 300000
    Rate = 6
    Years = 30
    Total = $9025.25

    Case 5:
    Principal = 150000
    Rate = 0
    Years = 30
    Total = $-nan

    Case 6:
    Principal = -50000
    Rate = 5
    Years = 10
    Total = $-1062.35


    Case 7:
    Principal = 120000
    Rate = 7
    Years = 20
    Total = $2664.74

    Case 8:
    Principal = 350000
    Rate = -4.25
    Years = 30
    Total = $3468.04

    Case 9:
    Principal = 180000
    Rate = 3
    Years = 15
    Total = $6239.76

    Case 10:
    Principal = -75000
    Rate = -6.5
    Years = 10
    Total = $6865.20

    */
}
