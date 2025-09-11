#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

int main (){

    //To create a file
    ofstream out;
    out.open("scores.txt");

    srand(time(0)); //This will create a different sequence of random numbers each time the program is run
    //Range [a,b] 
    //a + rand() % (b - a + 1)
    cout << rand() << endl; //This will print a random number between 0 and RAND_MAX, however if its it by itself it will always print the same number
    cout << rand() % 30 << endl; //This will print a random number between 0 and 29; if you want the range rand from 10 - 30 you would do (rand() % 21) + 10

    int a = 10, b = 30;

    //generate random numbers of each assessments
    int numOfLabs, numOfProjects, numOfQuizzes, numOfExams, numOfFinals;

    numOfLabs = 10 + rand() % (30 - 10 + 1);
    out << numOfLabs << " "; //This will write a random number between 10 and 30 to the file

    numOfQuizzes = 3 + rand() % (10 - 3 + 1);
    out << numOfQuizzes << " "; //This will write a random number between 3 and 10 to the file

    numOfProjects = 1;
    out << numOfProjects << " "; //This will write a random number between 1 and 5 to the file

    numOfExams = 2 + rand() % (3 - 2 + 1);
    out << numOfExams << " "; //This will write a random number between 2 and 3 to the file

    numOfFinals = 1;
    out << numOfFinals << endl; //This will write a random number between 1 and 2 to the file

    int counter = 0; //This will count the number of scores generated
    for (int i = 0; i < 5; i++){
        counter++;
        cout << a + rand() % (b - a + 1) << " "; //This will print a random number between 10 and 30
        out << a + rand() % (b - a + 1) << " "; //This will write a random number between 10 and 30 to the file

    }

    for(int i = 0; i < numOfQuizzes; i++){
        counter++;
        out << 0 + rand() % (10 - 0 + 1) << " "; //This will write a random number between 0 and 10 to the file

    }
    out.close(); //This will close the file and write the data to the file

    cout << endl;
    return 0;
}