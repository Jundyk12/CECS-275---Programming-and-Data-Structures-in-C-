/*
*this C++ program prompts the user for their gross income & filing status to then calculate their income tax, standard deduction, and 
*taxable income and prints the output
*CECS 275 - Fall 2025
*author Ivan Tran
*author Jundy Kato
*version 6.3.0
*last updated 9/08/2025
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double long  gross_income;
    char filing_status;
    double long calc_income;
    char tax_rate;
    cout << "Enter your gross income: ";
    cin >> gross_income;
    cout << "Please enter your filing status (S - single, H - head of household, J - Married filing jointly, P - married filing separately): ";
    cin >> filing_status;
    calc_income = gross_income;
    if (filing_status == 'S' || filing_status == 's') { //calc tax for single
        if (calc_income <= 11600) {
            calc_income = (calc_income * 0.10);
            tax_rate = '10%';  }
        else if  (calc_income >= 11601 && calc_income <= 47150 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = '12%'; }
        else if (calc_income >= 47151 && calc_income <= 100525) {
            calc_income = (calc_income * 0.22);
            tax_rate = '22%'; }
        else if (calc_income >= 100526 && calc_income <= 191950) {
            calc_income = (calc_income * 0.24); 
            tax_rate = '24%'; }
        else if (calc_income >= 191951 && calc_income <= 243725) {
            calc_income = (calc_income * 0.32); 
            tax_rate = '32%'; }
        else if (calc_income >= 243726 && calc_income <= 609350) {
            calc_income = (calc_income * 0.35); 
            tax_rate = '35%'; }
        else if (calc_income >= 609351) {
            calc_income = (calc_income * 0.37); 
            tax_rate = '37%'; }
        
 
        }
    
    if (filing_status == 'H' || filing_status == 'h') { //calc tax for head of household
        if (calc_income <= 16550) {
            calc_income = (calc_income * 0.10);  
            tax_rate = '10%';}
        else if  (calc_income >= 16551 && calc_income <= 63100 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = '12%'; }
        else if (calc_income >= 63101 && calc_income <= 100500) {
            calc_income = (calc_income * 0.22); 
            tax_rate = '22%'; }
        else if (calc_income >= 100501 && calc_income <= 191950) {
            calc_income = (calc_income * 0.24); 
            tax_rate = '24%'; }
        else if (calc_income >= 191951 && calc_income <= 243700) {
            calc_income = (calc_income * 0.32); 
            tax_rate = '32%'; }
        else if (calc_income >= 243701 && calc_income <= 609350) {
            calc_income = (calc_income * 0.35); 
            tax_rate = '35%'; }
        else if (calc_income >= 609351){
            calc_income = (calc_income * 0.37); 
            tax_rate = '37%'; }
        }

    if (filing_status == 'J' || filing_status == 'j') { //calc tax for married filing jointly 
        if (calc_income <= 23200) {
            calc_income = (calc_income * 0.10);  
            tax_rate = '10%'; }
        else if  (calc_income >= 23201 && calc_income <= 94300 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = '12%'; }
        else if (calc_income >= 94301 && calc_income <= 201050) {
            calc_income = (calc_income * 0.22); 
            tax_rate = '22%'; }
        else if (calc_income >= 201051 && calc_income <= 383900) {
            calc_income = (calc_income * 0.24); 
            tax_rate = '24%'; }
        else if (calc_income >= 383901 && calc_income <= 487450) {
            calc_income = (calc_income * 0.32); 
            tax_rate = '32%'; }
        else if (calc_income >= 487451 && calc_income <= 731200) {
            calc_income = (calc_income * 0.35); 
            tax_rate = '35%'; }
        }

    if (filing_status == 'P' || filing_status == 'p') { //calc married file separately
        if (calc_income <= 11600) {
            calc_income = (calc_income * 0.10); 
            tax_rate = '10%'; }
        else if  (calc_income >= 11601 && calc_income <= 47150 ) {
            calc_income = (calc_income * 0.12); 
            tax_rate = '12%'; }
        else if (calc_income >= 47151 && calc_income <= 100525) {
            calc_income = (calc_income * 0.22); 
            tax_rate = '22%'; }
        else if (calc_income >= 100526 && calc_income <= 191950) {
            calc_income = (calc_income * 0.24); 
            tax_rate = '24%'; }
        else if (calc_income >= 191951 && calc_income <= 243725) {
            calc_income = (calc_income * 0.32); 
            tax_rate = '32%'; }
        else if (calc_income >= 243726 && calc_income <= 365600) {
            calc_income = (calc_income * 0.35); 
            tax_rate = '35%'; }
        else if (calc_income >= 365601){
            calc_income = (calc_income * 0.37); 
            tax_rate = '37%'; }
        
 
        }
    return 0;
    
    cout << "  " << endl;
    cout << "gross income: ";
    cout << "filing status: " << filing_status;
    cout << "Standard deduction: " << ;
    cout << "taxable income: " << ;
    cout << "tax amount : " << ;
}

