/*
*this C++ program prompts the user for their username, password, and filename. With the filename, the user will generate a predetermined txt file
*that calculates their weighted grades across each category along with outputting their final letter grade.
*CECS 275 - Fall 2025
*author Ivan Tran
*author Jundy Kato
*version 6.3.0
*last updated 9/10/2025
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime> //for rand()

using namespace std;
string username;
string password;
string filename;
string lettergrade;
int total;
int labs_scores = 0;
int score = 0;
int quiz_scores = 0;
int midterm_scores = 0;
int project_score = 0;
int finals_grade = 0;
int datapoints = 5;
double weighted_final;
double weighted_midterms;
double weighted_lab;
double weighted_quiz;
double weighted_project;
double total_percent_grade;
const int lettergrade_a = 90;
const int lettergrade_b = 80;
const int lettergrade_c = 70;
const int lettergrade_d = 60;
const int lettergrade_f = 60;
const int reset_var = 0;
float lab_weight_percent = 15.0;
float quiz_weight_percent = 15.0;
float midterm_weight_percent = 40.0;
float project_weight_percent = 10.0;
float final_weight_percent = 20.0;
float total_lab_points = 100.0;
float total_quiz_points = 70.0;
float total_midterm_points = 100.0;
float total_project_points = 100.0;
float total_final_points = 100.0;
int test_case_datapoint = 31;
int linecounter = 0;



int main() {
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your file name: ";
    cin >> filename;

    //To create a file
    ofstream out;
    out.open("filename");

    // create the test file using user input for filename
    ofstream outfile(filename);
    //first line is 31 datapoints
    outfile << "20 7 2 1 1" << endl;
    // First test case
    outfile << "5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 10 10 10 10 10 10 10 50 50 100 100" << endl;
    // Second test case
    outfile << "4 5 5 3 2 5 5 5 5 5 4 5 5 1 0 5 5 4 5 5 9 8 10 10 7 7 6 45 35 89 90" << endl;
    //random function
    outfile.close();

    
    //counts the number of line in generated file to determine # of test cases
    ifstream readlines(filename);
    while (readlines >> datapoints) {
        linecounter++;
    }
    readlines.close();
    linecounter = floor(linecounter / test_case_datapoint);

    //calculate lab scores with generated txt file
    ifstream calculate(filename);

    //skip first 5 datapoints since they are not part of student scores
    for (int i = 0; i < 5; ++i) {
        calculate >> score;
    }
    
    for (int j = 0; j < linecounter; ++j) { //loop for each "line" there is in file
        labs_scores = reset_var; quiz_scores = reset_var; midterm_scores = reset_var; //reset variables for each run
        weighted_lab = reset_var; weighted_quiz = reset_var; weighted_midterms = reset_var; 
        project_score = reset_var; finals_grade = reset_var;
        score = reset_var;

        //calculate lab scores
        for (int i = 0; i < 20; ++i) {
            calculate >> score;
            labs_scores += score;
        }
        weighted_lab = (labs_scores / total_lab_points) * lab_weight_percent;

        //calculate quiz scores
        for (int i = 0; i < 7; ++i) {
            calculate >> score;
            quiz_scores += score;
        }
        weighted_quiz = (quiz_scores / total_quiz_points) * quiz_weight_percent;

        //calculate midterm scores
        for (int i = 0; i < 2; ++i) {
            calculate >> score;
            midterm_scores += score;
        }
        weighted_midterms = (midterm_scores / total_midterm_points) * midterm_weight_percent;

        //calculate project
        calculate >> score;
        project_score += score;
        weighted_project = (project_score / total_project_points) * project_weight_percent;

        //calculate final test grade
        calculate >> score;
        finals_grade += score;
        weighted_final = (finals_grade / total_final_points) * final_weight_percent;  


  
  
    //add up all weighted scores to get final grade
    total_percent_grade = weighted_lab + weighted_quiz + weighted_midterms + weighted_project + weighted_final;

   //determine letter grade using if statements
    if (total_percent_grade >= lettergrade_a) {
        lettergrade = "A";
    } else if (total_percent_grade >= lettergrade_b) {
        lettergrade = "B";
    } else if (total_percent_grade >= lettergrade_c) {
        lettergrade = "C";
    } else if (total_percent_grade >= lettergrade_d) {
        lettergrade = "D";
    } else if (total_percent_grade < lettergrade_f) {
        lettergrade = "F";

    }

    //all outputs

    cout << fixed << setprecision(2);
    cout << "\nLabs grade: " << weighted_lab << "%" << endl;
    cout << "Quiz grade: " << weighted_quiz << "%" << endl;
    cout << "Midterm Exams grade: " << weighted_midterms << "%" << endl;
    cout << "Project grade: " << weighted_project << "%" << endl;
    cout << "Final Exam grade: " << weighted_final << "%" << endl;
    cout << "Total percentage earned: " << total_percent_grade << "%" << endl;
    cout << "Final letter grade: " << lettergrade << "\n" << endl;

}
    calculate.close();
    out.close();
    return 0;
    
}