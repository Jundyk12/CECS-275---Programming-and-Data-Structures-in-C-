/*
*this C++ program converts a user input of milliseconds and converts it 
into days, hours, minutes, seconds, and milliseconds. Creating a time converter
*CECS 275 - Fall 2025
*author Ivan Tran
*author Jundy Kato
*version 6.3.0
*last updated 9/03/2025
*/


#include <iostream>

using namespace std;
int total_milli;
int total_days;
int total_hours;
int total_minutes;
int total_seconds;
int total_ms;
int calculate_milli;
int main() {
    cout << "Enter in ms: "; //properly formats input
    cin >> total_milli ; //takes input in ms
    calculate_milli = total_milli; //replaces input value so total_milli can be used to format output

    //calculates days and updates remaining milliseconds
    total_days = total_milli /86400000;
    calculate_milli %= 86400000;

    //calculates hours and updates remaining milliseconds
    total_hours = calculate_milli / 3600000;
    calculate_milli %= 3600000;

    //calculates minutes and updates remaining milliseconds
    total_minutes = calculate_milli / 60000;
    calculate_milli %= 60000;

    //calculates seconds & ms and updates remaining milliseconds
    total_seconds = calculate_milli / 1000;
    total_ms = calculate_milli % 1000;
    float total_seconds_milli = (float)total_seconds + (float)total_ms / 1000;


    //if statements take into account formatting issues such as 01d 05:03:04:002
    cout << total_milli << " ms = ";
    if (total_days < 10) //if days is less than 10 add a 0 in front 
        cout << "0" << total_days << "d ";
    else 
        cout << total_days << "d " ;
    if (total_hours < 10)   //if hours is less than 10 add a 0 in front
        cout << "0" << total_hours << ":";
    else 
        cout << total_hours << ":";
    if (total_minutes < 10) //if minutes is less than 10 add a 0 in front
        cout << "0" << total_minutes << ":";
    else 
        cout << total_minutes << ":";
    if (total_seconds_milli < 10)   //if seconds is less than 10 add a 0 in front
        cout << "0" << total_seconds_milli;
    else
    cout << total_seconds_milli
    <<  endl;
    return 0;

}