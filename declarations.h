#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include <string>
using namespace std;

//final commit//

bool checkIfValid(string file);

bool checkIfFileExist(string file);

bool checkForEmpty(string file);

bool checkForMultipleLines(string file);

bool checkForFewNums(string file);

bool checkForCharacters(string file);

int getSum(int arr[], int cap);

double getAverage(int sum, int cap);

void printAboveAverage(int arr[], double average, int cap);



#endif