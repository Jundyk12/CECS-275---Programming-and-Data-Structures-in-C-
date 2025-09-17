#include <iomanip> 
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime> //for rand()
#include "utils.h" //for numGeneratorInRange function
using namespace std;

//function example
int numGeneratorInRange(int a, int b); //function header


int main(){
    srand(time(0)); //seed the random number generator
    //cout << numGeneratorInRange(10,30) << endl;
    //cout << numListGeneratorInRange(0,5,20) << endl;
    int choice;
    cout << "1. Generate fake data" << endl;
    cout << "2. Exit" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "Generating fake report..." << endl;
            generateFakeStudentScore(20,10,2,1,1);
            cout << "DONE! Successful!" << endl;
            break;
        case 2:
            cout << "Thank you for using our software" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice, exiting program..." << endl;
    }

    //generateFakeStudentScore(20,10,2,1,1) << endl;
}
/*
int main(){
    ofstream out;
    out.open("scores.txt");
    srand(time(0));
    //range [a,b]
    // a + rand() % (b - a + 1) << endl;
    int a = 10, b = 30;

    //generate random number 
 /*   int numOfLabs;
    for (int i = 0; i < 20; i++){
        numOfLabs = 10 + rand() % (30 - 0 + 1);
        out << a + rand() % (b - a + 1) << " "; //rand() % (b - a + 1) gives a number between a and b
    }

    int numOfLabs;
    for (int i = 0; i < 20; i++){
        numOfLabs = 0 + rand() % (5 - 0 + 1);
        out << numOfLabs << " ";
    }
    out << endl;
    out.close();
    return 0;
}
*/