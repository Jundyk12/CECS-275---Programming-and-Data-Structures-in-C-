#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
void generateFakeStudentScore(int, int, int, int, int);



void generateFakeStudentScore(int numOfLabs, int numOfQuizzes, int numOfMidterms, int numOfProjects, int numOfFinals) {
    std::ofstream out;
    out.open("scores.txt");
    //print the first line of lab 5
    out << numOfLabs << " " << numOfQuizzes << " " << numOfMidterms
     << " " << numOfProjects << " " << numOfFinals << std::endl; 

     //max test case
     out << numListGeneratorInRange(5,5,numOfLabs);
     out << numListGeneratorInRange(10,10, numOfQuizzes);
     out << numListGeneratorInRange(50,50,numOfMidterms);
     out << numListGeneratorInRange(100,100,numOfProjects);
     out << numListGeneratorInRange(100,100,numOfFinals);

     out << std::endl;
    //new test case
     out << numListGeneratorInRange(0,5,numOfLabs);
     out << numListGeneratorInRange(7,10, numOfQuizzes);
     out << numListGeneratorInRange(30,50,numOfMidterms);
     out << numListGeneratorInRange(60,100,numOfProjects);
     out << numListGeneratorInRange(50,100,numOfFinals);
     out.close();
}