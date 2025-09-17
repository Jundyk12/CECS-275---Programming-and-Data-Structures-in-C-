#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

//prototype
int numGeneratorInRange(int a, int b);
std::string numListGeneratorInRange(int, int, int);
void generateFakeStudentScore(int, int, int, int, int);

/*
*This function randomly returns an integer in the interval [a,b]
*@param a lower bound
*@param b upper bound
*@return an integer in [a,b]
*/
int numGeneratorInRange(int a, int b) {
    return a + rand() % (b - a + 1);
    //return a > 1; , this already makes it true or false no need to specify
}

/*
*Function randomly return n numbers of random integer in [a,b]
*@param a lower bound
*@param b upper bound
*@param n amount of numbers 
*@return a string of n randomly generated numbers in [a,b]
*/
std::string numListGeneratorInRange(int a, int b, int n) {
    std::string result = "";
    for (int i = 0; i < n; i++){
        result += std::to_string(numGeneratorInRange(a,b));
        result += " ";
    }
    return result;
    //return a > 1; , this already makes it true or false no need to specify
}

void generateFakeStudentScore(int numOfLabs, int numOfQuizzes, int numOfMidterms, int numOfProjects, int numOfFinals) {
    std::ofstream out;
    out.open("scores.txt");

    out << numOfLabs << " " << numOfQuizzes << " " << numOfMidterms
     << " " << numOfProjects << " " << numOfFinals << std::endl; 

     //max test case
     out << numListGeneratorInRange(5,5,numOfLabs);
     out << numListGeneratorInRange(10,10, numOfQuizzes);
     out << numListGeneratorInRange(50,50,numOfMidterms);
     out << numListGeneratorInRange(100,100,numOfProjects);
     out << numListGeneratorInRange(100,100,numOfFinals);

     out << std::endl;

     out << numListGeneratorInRange(0,5,numOfLabs);
     out << numListGeneratorInRange(7,10, numOfQuizzes);
     out << numListGeneratorInRange(30,50,numOfMidterms);
     out << numListGeneratorInRange(60,100,numOfProjects);
     out << numListGeneratorInRange(50,100,numOfFinals);
}

