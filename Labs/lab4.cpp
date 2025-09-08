#include <iostream>
#include <iomanip>
#include <string>   //Use string instead of char 
using namespace std;

int main() {
    //Setting the decimals two places
    cout << fixed << setprecision(2);

    //Declaring data types for each variables
    double gross_income, calc_income;
    string tax_rate;                    //Using string instead of char to able to more characters than a single one
    char filing_status;
    double standard_deduction = 0.0;    //Setting standard deduction to 0

    cout << "Enter your gross income: ";
    cin >> gross_income;
    cout << "Please enter your filing status (S - single, H - head of household, J - Married filing jointly, P - married filing separately): ";
    cin >> filing_status;

    //Standard Deduction and setting each char with their own standard deduction
    if (filing_status == 'S' || filing_status == 's' || filing_status == 'P' || filing_status == 'p') {
        standard_deduction = 14600;
    } else if (filing_status == 'H' || filing_status == 'h') {
        standard_deduction = 21900;
    } else if (filing_status == 'J' || filing_status == 'j') {
        standard_deduction = 29200;
    }

    //Calculate the actual income after the standard deduction 
    //Using the calculated income to check what would be the tax_rate
    calc_income = gross_income - standard_deduction;

    //Using multiple if, else and else if statement for each tax bracket and filing status
    //'s' || 'S' = single filing
    if (filing_status == 'S' || filing_status == 's') {
        if (calc_income <= 11600) {
            calc_income = (calc_income * 0.10);
            tax_rate = "10%";
        } else if  (calc_income >= 11601 && calc_income <= 47150 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = "12%";
        } else if (calc_income >= 47151 && calc_income <= 100525) {
            calc_income = (calc_income * 0.22);
            tax_rate = "22%";
        } else if (calc_income >= 100526 && calc_income <= 191950) {
            calc_income = (calc_income * 0.24); 
            tax_rate = "24%";
        } else if (calc_income >= 191951 && calc_income <= 243725) {
            calc_income = (calc_income * 0.32); 
            tax_rate = "32%";
        } else if (calc_income >= 243726 && calc_income <= 609350) {
            calc_income = (calc_income * 0.35); 
            tax_rate = "35%";
        } else if (calc_income >= 609351) {
            calc_income = (calc_income * 0.37); 
            tax_rate = "37%";
        }
    }

    //"H" || "h" = Head of household
    if (filing_status == 'H' || filing_status == 'h') {
        if (calc_income <= 16550) {
            calc_income = (calc_income * 0.10);  
            tax_rate = "10%";
        } else if  (calc_income >= 16551 && calc_income <= 63100 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = "12%";
        } else if (calc_income >= 63101 && calc_income <= 100500) {
            calc_income = (calc_income * 0.22); 
            tax_rate = "22%";
        } else if (calc_income >= 100501 && calc_income <= 191950) {
            calc_income = (calc_income * 0.24); 
            tax_rate = "24%";
        } else if (calc_income >= 191951 && calc_income <= 243700) {
            calc_income = (calc_income * 0.32); 
            tax_rate = "32%";
        } else if (calc_income >= 243701 && calc_income <= 609350) {
            calc_income = (calc_income * 0.35); 
            tax_rate = "35%";
        } else if (calc_income >= 609351){
            calc_income = (calc_income * 0.37); 
            tax_rate = "37%";
        }
    }

    //"J" || "j" for married filing jointly
    if (filing_status == 'J' || filing_status == 'j') {
        if (calc_income <= 23200) {
            calc_income = (calc_income * 0.10);  
            tax_rate = "10%";
        } else if  (calc_income >= 23201 && calc_income <= 94300 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = "12%";
        } else if (calc_income >= 94301 && calc_income <= 201050) {
            calc_income = (calc_income * 0.22); 
            tax_rate = "22%";
        } else if (calc_income >= 201051 && calc_income <= 383900) {
            calc_income = (calc_income * 0.24); 
            tax_rate = "24%";
        } else if (calc_income >= 383901 && calc_income <= 487450) {
            calc_income = (calc_income * 0.32); 
            tax_rate = "32%";
        } else if (calc_income >= 487451 && calc_income <= 731200) {
            calc_income = (calc_income * 0.35); 
            tax_rate = "35%";
        } else if (calc_income >= 731201) {
            calc_income = (calc_income * 0.37); 
            tax_rate = "37%";
        }
    }

    //"p" || "P" for married filing separtely
    if (filing_status == 'P' || filing_status == 'p') {
        if (calc_income <= 11600) {
            calc_income = (calc_income * 0.10); 
            tax_rate = "10%";
        } else if  (calc_income >= 11601 && calc_income <= 47150 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = "12%";
        } else if (calc_income >= 47151 && calc_income <= 100525) {
            calc_income = (calc_income * 0.22); 
            tax_rate = "22%";
        } else if (calc_income >= 100526 && calc_income <= 191950) {
            calc_income = (calc_income * 0.24); 
            tax_rate = "24%";
        } else if (calc_income >= 191951 && calc_income <= 243725) {
            calc_income = (calc_income * 0.32); 
            tax_rate = "32%";
        } else if (calc_income >= 243726 && calc_income <= 365600) {
            calc_income = (calc_income * 0.35); 
            tax_rate = "35%";
        } else if (calc_income >= 365601){
            calc_income = (calc_income * 0.37); 
            tax_rate = "37%";
        }
    }

    //Calculating for the Taxable income 
    //Did not call the calc_income since it is being use to calculate the tax amount not the taxable income
    double taxable_income = gross_income - standard_deduction;

    cout << "\n";
    cout << "gross income: " << gross_income << endl;
    cout << "filing status: " << filing_status << endl;
    cout << "Standard deduction: " << standard_deduction << endl;
    cout << "taxable income: " << taxable_income << endl;
    cout << "tax amount : " << calc_income << " (rate " << tax_rate << ")" << endl;

    return 0;
}
