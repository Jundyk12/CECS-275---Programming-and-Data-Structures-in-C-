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

// Puting all the constants outside the main so they can be access globally in the code
// Created each constant for each bracket and standard deduction for better readability and easier to debug
// Alternatte between upper and lower brackets for better understanding of the ranges
// Seperate each one of the filing status with a comment for better readability
// Standard Deductions
const double S_STANDARD_DEDUCTION = 14600;
const double H_STANDARD_DEDUCTION = 21900;
const double J_STANDARD_DEDUCTION = 29200;
const double P_STANDARD_DEDUCTION = 14600;

// Single brackets
const double S_LOWER_BRACKET_1 = 0;
const double S_UPPER_BRACKET_1 = 11600;
const double S_LOWER_BRACKET_2 = 11601;
const double S_UPPER_BRACKET_2 = 47150;
const double S_LOWER_BRACKET_3 = 47151;
const double S_UPPER_BRACKET_3 = 100525;
const double S_LOWER_BRACKET_4 = 100526;
const double S_UPPER_BRACKET_4 = 191950;
const double S_LOWER_BRACKET_5 = 191951;
const double S_UPPER_BRACKET_5 = 243725;
const double S_LOWER_BRACKET_6 = 243726;
const double S_UPPER_BRACKET_6 = 609350;
const double S_LOWER_BRACKET_7 = 609351;

// Married Filing Jointly brackets
const double J_LOWER_BRACKET_1 = 0;
const double J_UPPER_BRACKET_1 = 23200;
const double J_LOWER_BRACKET_2 = 23201;
const double J_UPPER_BRACKET_2 = 94300;
const double J_LOWER_BRACKET_3 = 94301;
const double J_UPPER_BRACKET_3 = 201050;
const double J_LOWER_BRACKET_4 = 201051;
const double J_UPPER_BRACKET_4 = 383900;
const double J_LOWER_BRACKET_5 = 383901;
const double J_UPPER_BRACKET_5 = 487450;
const double J_LOWER_BRACKET_6 = 487451;
const double J_UPPER_BRACKET_6 = 731200;
const double J_LOWER_BRACKET_7 = 731201;

// Married Filing Separately brackets
const double P_LOWER_BRACKET_1 = 0;
const double P_UPPER_BRACKET_1 = 11600;
const double P_LOWER_BRACKET_2 = 11601;
const double P_UPPER_BRACKET_2 = 47150;
const double P_LOWER_BRACKET_3 = 47151;
const double P_UPPER_BRACKET_3 = 100525;
const double P_LOWER_BRACKET_4 = 100526;
const double P_UPPER_BRACKET_4 = 191950;
const double P_LOWER_BRACKET_5 = 191951;
const double P_UPPER_BRACKET_5 = 243725;
const double P_LOWER_BRACKET_6 = 243726;
const double P_UPPER_BRACKET_6 = 365600;
const double P_LOWER_BRACKET_7 = 365601;

// Head of Household brackets
const double H_LOWER_BRACKET_1 = 0;
const double H_UPPER_BRACKET_1 = 16550;
const double H_LOWER_BRACKET_2 = 16551;
const double H_UPPER_BRACKET_2 = 63100;
const double H_LOWER_BRACKET_3 = 63101;
const double H_UPPER_BRACKET_3 = 100500;
const double H_LOWER_BRACKET_4 = 100501;
const double H_UPPER_BRACKET_4 = 191950;
const double H_LOWER_BRACKET_5 = 191951;
const double H_UPPER_BRACKET_5 = 243700;
const double H_LOWER_BRACKET_6 = 243701;
const double H_UPPER_BRACKET_6 = 609350;
const double H_LOWER_BRACKET_7 = 609351;

// Created constants for each tax rate to prevent magic numbers
// Tax rates
const double RATE_10 = 0.10;
const double RATE_12 = 0.12;
const double RATE_22 = 0.22;
const double RATE_24 = 0.24;
const double RATE_32 = 0.32;
const double RATE_35 = 0.35;
const double RATE_37 = 0.37;

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
    double standard_deduction = 0.0; // Initialize standard_deduction to 0.0

    // Created while loop so that way it will just read until the end of the file and no need to type it
    while (input >> gross_income >> filing_status) {
        // Creating an if statement to check if the income is less than 0 before proceeding to the next input
        // Stop the whole program if the income is less than 0
        if (gross_income <= 0) {
            cout << "Income cannot be 0 or less." << endl;
            continue;
        }

        // Standard Deduction for each filing status
        // Included both uppercase and lowercase letters for the filing status
        if (filing_status == 'S' || filing_status == 's' || filing_status == 'P' || filing_status == 'p') {
            standard_deduction = S_STANDARD_DEDUCTION;
        } else if (filing_status == 'H' || filing_status == 'h') {
            standard_deduction = H_STANDARD_DEDUCTION;
        } else if (filing_status == 'J' || filing_status == 'j') {
            standard_deduction = J_STANDARD_DEDUCTION;
        }

        // Calculate the actual income after the standard deduction
        // Based on the calc income we can calculate the tax amount
        calc_income = gross_income - standard_deduction;

        // Made sure to use constant number instead of magic number to prevent errors or bugs in the future
        // Used marginal tax rate to calculate the tax amount
        // "S" || "s" = Single
        if (filing_status == 'S' || filing_status == 's') {
            if (calc_income <= S_UPPER_BRACKET_1) {
                tax_rate = "10%";
                calc_income = calc_income * RATE_10;
            } else if (calc_income <= S_UPPER_BRACKET_2) {
                tax_rate = "12%";
                calc_income = S_UPPER_BRACKET_1 * RATE_10
                            + (calc_income - S_UPPER_BRACKET_1) * RATE_12;
            } else if (calc_income <= S_UPPER_BRACKET_3) {
                tax_rate = "22%";
                calc_income = S_UPPER_BRACKET_1 * RATE_10
                            + (S_UPPER_BRACKET_2 - S_UPPER_BRACKET_1) * RATE_12
                            + (calc_income - S_UPPER_BRACKET_2) * RATE_22;
            } else if (calc_income <= S_UPPER_BRACKET_4) {
                tax_rate = "24%";
                calc_income = S_UPPER_BRACKET_1 * RATE_10
                            + (S_UPPER_BRACKET_2 - S_UPPER_BRACKET_1) * RATE_12
                            + (S_UPPER_BRACKET_3 - S_UPPER_BRACKET_2) * RATE_22
                            + (calc_income - S_UPPER_BRACKET_3) * RATE_24;
            } else if (calc_income <= S_UPPER_BRACKET_5) {
                tax_rate = "32%";
                calc_income = S_UPPER_BRACKET_1 * RATE_10
                            + (S_UPPER_BRACKET_2 - S_UPPER_BRACKET_1) * RATE_12
                            + (S_UPPER_BRACKET_3 - S_UPPER_BRACKET_2) * RATE_22
                            + (S_UPPER_BRACKET_4 - S_UPPER_BRACKET_3) * RATE_24
                            + (calc_income - S_UPPER_BRACKET_4) * RATE_32;
            } else if (calc_income <= S_UPPER_BRACKET_6) {
                tax_rate = "35%";
                calc_income = S_UPPER_BRACKET_1 * RATE_10
                            + (S_UPPER_BRACKET_2 - S_UPPER_BRACKET_1) * RATE_12
                            + (S_UPPER_BRACKET_3 - S_UPPER_BRACKET_2) * RATE_22
                            + (S_UPPER_BRACKET_4 - S_UPPER_BRACKET_3) * RATE_24
                            + (S_UPPER_BRACKET_5 - S_UPPER_BRACKET_4) * RATE_32
                            + (calc_income - S_UPPER_BRACKET_5) * RATE_35;
            } else {
                tax_rate = "37%";
                calc_income = S_UPPER_BRACKET_1 * RATE_10
                            + (S_UPPER_BRACKET_2 - S_UPPER_BRACKET_1) * RATE_12
                            + (S_UPPER_BRACKET_3 - S_UPPER_BRACKET_2) * RATE_22
                            + (S_UPPER_BRACKET_4 - S_UPPER_BRACKET_3) * RATE_24
                            + (S_UPPER_BRACKET_5 - S_UPPER_BRACKET_4) * RATE_32
                            + (S_UPPER_BRACKET_6 - S_UPPER_BRACKET_5) * RATE_35
                            + (calc_income - S_UPPER_BRACKET_6) * RATE_37;
            }
        }
        // "H" || "h" = Head of Household
        else if (filing_status == 'H' || filing_status == 'h') {
            if (calc_income <= H_UPPER_BRACKET_1) {
                tax_rate = "10%";
                calc_income = calc_income * RATE_10;
            } else if (calc_income <= H_UPPER_BRACKET_2) {
                tax_rate = "12%";
                calc_income = H_UPPER_BRACKET_1 * RATE_10
                            + (calc_income - H_UPPER_BRACKET_1) * RATE_12;
            } else if (calc_income <= H_UPPER_BRACKET_3) {
                tax_rate = "22%";
                calc_income = H_UPPER_BRACKET_1 * RATE_10
                            + (H_UPPER_BRACKET_2 - H_UPPER_BRACKET_1) * RATE_12
                            + (calc_income - H_UPPER_BRACKET_2) * RATE_22;
            } else if (calc_income <= H_UPPER_BRACKET_4) {
                tax_rate = "24%";
                calc_income = H_UPPER_BRACKET_1 * RATE_10
                            + (H_UPPER_BRACKET_2 - H_UPPER_BRACKET_1) * RATE_12
                            + (H_UPPER_BRACKET_3 - H_UPPER_BRACKET_2) * RATE_22
                            + (calc_income - H_UPPER_BRACKET_3) * RATE_24;
            } else if (calc_income <= H_UPPER_BRACKET_5) {
                tax_rate = "32%";
                calc_income = H_UPPER_BRACKET_1 * RATE_10
                            + (H_UPPER_BRACKET_2 - H_UPPER_BRACKET_1) * RATE_12
                            + (H_UPPER_BRACKET_3 - H_UPPER_BRACKET_2) * RATE_22
                            + (H_UPPER_BRACKET_4 - H_UPPER_BRACKET_3) * RATE_24
                            + (calc_income - H_UPPER_BRACKET_4) * RATE_32;
            } else if (calc_income <= H_UPPER_BRACKET_6) {
                tax_rate = "35%";
                calc_income = H_UPPER_BRACKET_1 * RATE_10
                            + (H_UPPER_BRACKET_2 - H_UPPER_BRACKET_1) * RATE_12
                            + (H_UPPER_BRACKET_3 - H_UPPER_BRACKET_2) * RATE_22
                            + (H_UPPER_BRACKET_4 - H_UPPER_BRACKET_3) * RATE_24
                            + (H_UPPER_BRACKET_5 - H_UPPER_BRACKET_4) * RATE_32
                            + (calc_income - H_UPPER_BRACKET_5) * RATE_35;
            } else {
                tax_rate = "37%";
                calc_income = H_UPPER_BRACKET_1 * RATE_10
                            + (H_UPPER_BRACKET_2 - H_UPPER_BRACKET_1) * RATE_12
                            + (H_UPPER_BRACKET_3 - H_UPPER_BRACKET_2) * RATE_22
                            + (H_UPPER_BRACKET_4 - H_UPPER_BRACKET_3) * RATE_24
                            + (H_UPPER_BRACKET_5 - H_UPPER_BRACKET_4) * RATE_32
                            + (H_UPPER_BRACKET_6 - H_UPPER_BRACKET_5) * RATE_35
                            + (calc_income - H_UPPER_BRACKET_6) * RATE_37;
            }
        }
        // "J" || "j" = Married Filing Jointly
        else if (filing_status == 'J' || filing_status == 'j') {
            if (calc_income <= J_UPPER_BRACKET_1) {
                tax_rate = "10%";
                calc_income = calc_income * RATE_10;
            } else if (calc_income <= J_UPPER_BRACKET_2) {
                tax_rate = "12%";
                calc_income = J_UPPER_BRACKET_1 * RATE_10
                            + (calc_income - J_UPPER_BRACKET_1) * RATE_12;
            } else if (calc_income <= J_UPPER_BRACKET_3) {
                tax_rate = "22%";
                calc_income = J_UPPER_BRACKET_1 * RATE_10
                            + (J_UPPER_BRACKET_2 - J_UPPER_BRACKET_1) * RATE_12
                            + (calc_income - J_UPPER_BRACKET_2) * RATE_22;
            } else if (calc_income <= J_UPPER_BRACKET_4) {
                tax_rate = "24%";
                calc_income = J_UPPER_BRACKET_1 * RATE_10
                            + (J_UPPER_BRACKET_2 - J_UPPER_BRACKET_1) * RATE_12
                            + (J_UPPER_BRACKET_3 - J_UPPER_BRACKET_2) * RATE_22
                            + (calc_income - J_UPPER_BRACKET_3) * RATE_24;
            } else if (calc_income <= J_UPPER_BRACKET_5) {
                tax_rate = "32%";
                calc_income = J_UPPER_BRACKET_1 * RATE_10
                            + (J_UPPER_BRACKET_2 - J_UPPER_BRACKET_1) * RATE_12
                            + (J_UPPER_BRACKET_3 - J_UPPER_BRACKET_2) * RATE_22
                            + (J_UPPER_BRACKET_4 - J_UPPER_BRACKET_3) * RATE_24
                            + (calc_income - J_UPPER_BRACKET_4) * RATE_32;
            } else if (calc_income <= J_UPPER_BRACKET_6) {
                tax_rate = "35%";
                calc_income = J_UPPER_BRACKET_1 * RATE_10
                            + (J_UPPER_BRACKET_2 - J_UPPER_BRACKET_1) * RATE_12
                            + (J_UPPER_BRACKET_3 - J_UPPER_BRACKET_2) * RATE_22
                            + (J_UPPER_BRACKET_4 - J_UPPER_BRACKET_3) * RATE_24
                            + (J_UPPER_BRACKET_5 - J_UPPER_BRACKET_4) * RATE_32
                            + (calc_income - J_UPPER_BRACKET_5) * RATE_35;
            } else {
                tax_rate = "37%";
                calc_income = J_UPPER_BRACKET_1 * RATE_10
                            + (J_UPPER_BRACKET_2 - J_UPPER_BRACKET_1) * RATE_12
                            + (J_UPPER_BRACKET_3 - J_UPPER_BRACKET_2) * RATE_22
                            + (J_UPPER_BRACKET_4 - J_UPPER_BRACKET_3) * RATE_24
                            + (J_UPPER_BRACKET_5 - J_UPPER_BRACKET_4) * RATE_32
                            + (J_UPPER_BRACKET_6 - J_UPPER_BRACKET_5) * RATE_35
                            + (calc_income - J_UPPER_BRACKET_6) * RATE_37;
            }
        }
        // "P" || "p" = Married Filing Separately
        else if (filing_status == 'P' || filing_status == 'p') {
            if (calc_income <= P_UPPER_BRACKET_1) {
                tax_rate = "10%";
                calc_income = calc_income * RATE_10;
            } else if (calc_income <= P_UPPER_BRACKET_2) {
                tax_rate = "12%";
                calc_income = P_UPPER_BRACKET_1 * RATE_10
                            + (calc_income - P_UPPER_BRACKET_1) * RATE_12;
            } else if (calc_income <= P_UPPER_BRACKET_3) {
                tax_rate = "22%";
                calc_income = P_UPPER_BRACKET_1 * RATE_10
                            + (P_UPPER_BRACKET_2 - P_UPPER_BRACKET_1) * RATE_12
                            + (calc_income - P_UPPER_BRACKET_2) * RATE_22;
            } else if (calc_income <= P_UPPER_BRACKET_4) {
                tax_rate = "24%";
                calc_income = P_UPPER_BRACKET_1 * RATE_10
                            + (P_UPPER_BRACKET_2 - P_UPPER_BRACKET_1) * RATE_12
                            + (P_UPPER_BRACKET_3 - P_UPPER_BRACKET_2) * RATE_22
                            + (calc_income - P_UPPER_BRACKET_3) * RATE_24;
            } else if (calc_income <= P_UPPER_BRACKET_5) {
                tax_rate = "32%";
                calc_income = P_UPPER_BRACKET_1 * RATE_10
                            + (P_UPPER_BRACKET_2 - P_UPPER_BRACKET_1) * RATE_12
                            + (P_UPPER_BRACKET_3 - P_UPPER_BRACKET_2) * RATE_22
                            + (P_UPPER_BRACKET_4 - P_UPPER_BRACKET_3) * RATE_24
                            + (calc_income - P_UPPER_BRACKET_4) * RATE_32;
            } else if (calc_income <= P_UPPER_BRACKET_6) {
                tax_rate = "35%";
                calc_income = P_UPPER_BRACKET_1 * RATE_10
                            + (P_UPPER_BRACKET_2 - P_UPPER_BRACKET_1) * RATE_12
                            + (P_UPPER_BRACKET_3 - P_UPPER_BRACKET_2) * RATE_22
                            + (P_UPPER_BRACKET_4 - P_UPPER_BRACKET_3) * RATE_24
                            + (P_UPPER_BRACKET_5 - P_UPPER_BRACKET_4) * RATE_32
                            + (calc_income - P_UPPER_BRACKET_5) * RATE_35;
            } else {
                tax_rate = "37%";
                calc_income = P_UPPER_BRACKET_1 * RATE_10
                            + (P_UPPER_BRACKET_2 - P_UPPER_BRACKET_1) * RATE_12
                            + (P_UPPER_BRACKET_3 - P_UPPER_BRACKET_2) * RATE_22
                            + (P_UPPER_BRACKET_4 - P_UPPER_BRACKET_3) * RATE_24
                            + (P_UPPER_BRACKET_5 - P_UPPER_BRACKET_4) * RATE_32
                            + (P_UPPER_BRACKET_6 - P_UPPER_BRACKET_5) * RATE_35
                            + (calc_income - P_UPPER_BRACKET_6) * RATE_37;
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