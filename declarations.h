#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include <string>
using namespace std;

bool checkIfValid(string file);

bool checkForEmpty(string file);

void printArr(int arr[], int cap);

int getSum(int arr[], int cap);

double getAverage(int sum, int cap);

void printAboveAverage(int arr[], double average, int cap);



#endif