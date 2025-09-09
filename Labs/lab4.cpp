/*
*This C++ program calculate taxable income and tax amount using 2023 tax brackets and marginal calculations
*CECS 275 - Fall 2025 
*@author Jundy Kato
*@author Ivan Tran
*@version 1.0.0
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {

    /*
        ifstream input;
        char status;
        while (input.open("data.txt") {
            cout << status << endl;
        }
        
        input.close();
    
    */
    
    // Setting the decimals two places
    cout << fixed << setprecision(2);

    ifstream input("data.txt");

    // Declaring data types for each variable
    double gross_income, calc_income, new_income;
    string tax_rate;
    char filing_status;
    double standard_deduction = 0.0;

    // Loop to read each line from the file
    while (input >> gross_income >> filing_status) {
        // Creating an if statement to check if the income is less than 0 before proceeding to the next input
        // Stop the whole program if the income is less than 0
        if (gross_income <= 0) {
            cout << "Income cannot be 0 or less." << endl;
            continue;
        }

        // Standard Deduction for each filing status
        if (filing_status == 'S' || filing_status == 's' || filing_status == 'P' || filing_status == 'p') {
            standard_deduction = 14600;
        } else if (filing_status == 'H' || filing_status == 'h') {
            standard_deduction = 21900;
        } else if (filing_status == 'J' || filing_status == 'j') {
            standard_deduction = 29200;
        }
        
        // Calculate the actual income after the standard deduction
        // Based on the calc income we can calculate the tax amount
        calc_income = gross_income - standard_deduction;

        // "S" || "s" = Single
        if (filing_status == 'S' || filing_status == 's') {
            if (calc_income <= 11600) {
                tax_rate = "10%";
                calc_income = calc_income * 0.10;
            } else if (calc_income <= 47150) {
                tax_rate = "12%";
                calc_income = 11600 * 0.10
                            + (calc_income - 11600) * 0.12;
            } else if (calc_income <= 100525) {
                tax_rate = "22%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (calc_income - 47150) * 0.22;
            } else if (calc_income <= 191950) {
                tax_rate = "24%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (calc_income - 100525) * 0.24;
            } else if (calc_income <= 243725) {
                tax_rate = "32%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (191950 - 100525) * 0.24
                            + (calc_income - 191950) * 0.32;
            } else if (calc_income <= 609350) {
                tax_rate = "35%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (191950 - 100525) * 0.24
                            + (243725 - 191950) * 0.32
                            + (calc_income - 243725) * 0.35;
            } else {
                tax_rate = "37%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (191950 - 100525) * 0.24
                            + (243725 - 191950) * 0.32
                            + (609350 - 243725) * 0.35
                            + (calc_income - 609350) * 0.37;
            }
        }
        // "H" || "h" = Head of Household
        else if (filing_status == 'H' || filing_status == 'h') {
            if (calc_income <= 16550) {
                tax_rate = "10%";
                calc_income = calc_income * 0.10;
            } else if (calc_income <= 63100) {
                tax_rate = "12%";
                calc_income = 16550 * 0.10
                            + (calc_income - 16550) * 0.12;
            } else if (calc_income <= 100500) {
                tax_rate = "22%";
                calc_income = 16550 * 0.10
                            + (63100 - 16550) * 0.12
                            + (calc_income - 63100) * 0.22;
            } else if (calc_income <= 191950) {
                tax_rate = "24%";
                calc_income = 16550 * 0.10
                            + (63100 - 16550) * 0.12
                            + (100500 - 63100) * 0.22
                            + (calc_income - 100500) * 0.24;
            } else if (calc_income <= 243700) {
                tax_rate = "32%";
                calc_income = 16550 * 0.10
                            + (63100 - 16550) * 0.12
                            + (100500 - 63100) * 0.22
                            + (191950 - 100500) * 0.24
                            + (calc_income - 191950) * 0.32;
            } else if (calc_income <= 609350) {
                tax_rate = "35%";
                calc_income = 16550 * 0.10
                            + (63100 - 16550) * 0.12
                            + (100500 - 63100) * 0.22
                            + (191950 - 100500) * 0.24
                            + (243700 - 191950) * 0.32
                            + (calc_income - 243700) * 0.35;
            } else {
                tax_rate = "37%";
                calc_income = 16550 * 0.10
                            + (63100 - 16550) * 0.12
                            + (100500 - 63100) * 0.22
                            + (191950 - 100500) * 0.24
                            + (243700 - 191950) * 0.32
                            + (609350 - 243700) * 0.35
                            + (calc_income - 609350) * 0.37;
            }
        }
        // "J" || "j" = Married Filing Jointly
        else if (filing_status == 'J' || filing_status == 'j') {
            if (calc_income <= 23200) {
                tax_rate = "10%";
                calc_income = calc_income * 0.10;
            } else if (calc_income <= 94300) {
                tax_rate = "12%";
                calc_income = 23200 * 0.10
                            + (calc_income - 23200) * 0.12;
            } else if (calc_income <= 201050) {
                tax_rate = "22%";
                calc_income = 23200 * 0.10
                            + (94300 - 23200) * 0.12
                            + (calc_income - 94300) * 0.22;
            } else if (calc_income <= 383900) {
                tax_rate = "24%";
                calc_income = 23200 * 0.10
                            + (94300 - 23200) * 0.12
                            + (201050 - 94300) * 0.22
                            + (calc_income - 201050) * 0.24;
            } else if (calc_income <= 487450) {
                tax_rate = "32%";
                calc_income = 23200 * 0.10
                            + (94300 - 23200) * 0.12
                            + (201050 - 94300) * 0.22
                            + (383900 - 201050) * 0.24
                            + (calc_income - 383900) * 0.32;
            } else if (calc_income <= 731200) {
                tax_rate = "35%";
                calc_income = 23200 * 0.10
                            + (94300 - 23200) * 0.12
                            + (201050 - 94300) * 0.22
                            + (383900 - 201050) * 0.24
                            + (487450 - 383900) * 0.32
                            + (calc_income - 487450) * 0.35;
            } else {
                tax_rate = "37%";
                calc_income = 23200 * 0.10
                            + (94300 - 23200) * 0.12
                            + (201050 - 94300) * 0.22
                            + (383900 - 201050) * 0.24
                            + (487450 - 383900) * 0.32
                            + (731200 - 487450) * 0.35
                            + (calc_income - 731200) * 0.37;
            }
        }
        // "P" || "p" = Married Filing Separately
        else if (filing_status == 'P' || filing_status == 'p') {
            if (calc_income <= 11600) {
                tax_rate = "10%";
                calc_income = calc_income * 0.10;
            } else if (calc_income <= 47150) {
                tax_rate = "12%";
                calc_income = 11600 * 0.10
                            + (calc_income - 11600) * 0.12;
            } else if (calc_income <= 100525) {
                tax_rate = "22%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (calc_income - 47150) * 0.22;
            } else if (calc_income <= 191950) {
                tax_rate = "24%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (calc_income - 100525) * 0.24;
            } else if (calc_income <= 243725) {
                tax_rate = "32%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (191950 - 100525) * 0.24
                            + (calc_income - 191950) * 0.32;
            } else if (calc_income <= 365600) {
                tax_rate = "35%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (191950 - 100525) * 0.24
                            + (243725 - 191950) * 0.32
                            + (calc_income - 243725) * 0.35;
            } else {
                tax_rate = "37%";
                calc_income = 11600 * 0.10
                            + (47150 - 11600) * 0.12
                            + (100525 - 47150) * 0.22
                            + (191950 - 100525) * 0.24
                            + (243725 - 191950) * 0.32
                            + (365600 - 243725) * 0.35
                            + (calc_income - 365600) * 0.37;
            }
        }

        // Calculating for the Taxable income
        // Did not create a new variable for taxable income because calc_income is already the taxable income after standard deduction
        double taxable_income = gross_income - standard_deduction;

        // Display all the outputs properly formatted
        cout << "\n";
        cout << "gross income: " << gross_income << endl;
        cout << "filing status: " << filing_status << endl;
        cout << "Standard deduction: " << standard_deduction << endl;
        cout << "taxable income: " << taxable_income << endl;
        cout << "tax amount : " << calc_income << " (rate " << tax_rate << ")" << endl;
    }

    input.close();
    return 0;
}