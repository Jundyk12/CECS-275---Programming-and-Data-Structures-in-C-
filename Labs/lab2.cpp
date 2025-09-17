/*
*this C++ program converts a user input of milliseconds and converts it 
into days, hours, minutes, seconds, and milliseconds. Creating a time converter
*CECS 275 - Fall 2025
*author Ivan Tran
*author Jundy Kato
*version 6.3.0
*last updated 9/03/2025
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

    int total_milli;
    int total_days;
    int total_hours;
    int total_minutes;
    int total_seconds;
    int total_ms;
    int calculate_milli;
    const int day_converter = 86400000; //number of milliseconds in a day
    const int hour_converter = 3600000; //number of milliseconds in an hour
    const int minute_converter = 60000; //number of milliseconds in a minute
    const int second_converter = 1000; //number of milliseconds in a second
    cout << "Enter in ms: "; //properly formats input
    cin >> total_milli ; //takes input in ms
    calculate_milli = total_milli; //replaces input value so total_milli can be used to format output

    //calculates days and updates remaining milliseconds
    total_days = calculate_milli /day_converter;
    calculate_milli %= day_converter;

    //calculates hours and updates remaining milliseconds
    total_hours = calculate_milli / hour_converter;
    calculate_milli %= hour_converter;

    //calculates minutes and updates remaining milliseconds
    total_minutes = calculate_milli / minute_converter;
    calculate_milli %= minute_converter;

    //calculates seconds & ms and updates remaining milliseconds
    total_seconds = calculate_milli / second_converter;
    total_ms = calculate_milli % second_converter;

    // convert ms (0–999) to centiseconds (0–99)
    int total_cs = total_ms / 10;

    //final outputs with proper formatting
    cout << total_milli << " ms = ";

    //setfill and setw allows us to add 0 when value is less than 2 digits
    cout << setfill('0') << setw(2) << total_days << "d ";

    cout << setfill('0') << setw(2) << total_hours << ":";

    cout << setfill('0') << setw(2) << total_minutes << ":";

    cout << setfill('0') << setw(2) << total_seconds << ".";
    
    cout << setfill('0') << setw(3) << total_cs << endl;

    return 0;

    //use setfill to replace 0g
}