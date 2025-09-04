/*




*/


#include <iostream>
#include <iomanip> //This function allows to use setprecision
#include <cmath>  //Different functions for calculations

using namespace std;

int main(){

    cout << fixed << setprecision(2);
    const double pie = 3.14; //Should not have any floating # always make constant 
    int num; // initialize variable
    double radius; //Double acts like both float/double precision

    cout << "Enter a number: "; //This is a prompt
    cin >> num; //This is willl create an input

    //Display the radius info
    cout << "Enter a radius of a circle: ";
    cin >> radius;
    cout << "Radius (m) " << radius << endl;   

    //Calculate the are aof the circle
    //double area = (radius * radius * pie);
    long double area = pie * pow(radius, 2.0);

    //Display the area of the circle 
    cout << "Area of a circle (m^2): " << area << endl;

    /*Be careful with double type the #s behind it might not be the same
      DO NOT long double x = 0.1;
                if (x == 0.1) you will fail if you compare the two double since they are not the same   
            To fix this is using double or cmath to combat this or if(abs(0.1-x)) <= 10^-16
    */

    return 0;
}