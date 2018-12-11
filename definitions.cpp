#include <iostream>
#include <fstream>
#include <string>
#include "declarations.h"
using namespace std;

bool checkIfValid(string file){
    char num;
	bool isValid = true;

	ifstream myReadFile;
	myReadFile.open(file);

	isValid = checkForEmpty(file);

	while (myReadFile >> num && isValid == true)
	{
		if (isdigit(num) || num == '-') {
			isValid = true;
		}
		else {
			isValid = false;
		}
	}
	
	myReadFile.close();


	return isValid;
}
//checks so that the file contains anything. 
bool checkForEmpty(string file){
	ifstream myReadFile;
	string str;
	bool haveContent = true;
	bool haveLetters = false;
	bool isValid;
	myReadFile.open(file);

	getline(myReadFile, str);

	if (str.size() == 0){
		haveContent = false;
		isValid = false;
	}


	 
	if (haveContent != false){
		for (int i = 0; i < str.size() && haveLetters == false; i++){
			if (str[i] != ' '){
				haveLetters = true;
				isValid = true;
			}
		}
	}

	myReadFile.close();

	return isValid;
}

void printArr(int arr[], int cap) {
	cout << "the numbers in the file are: " << endl;

	for (int i = 0; i <cap; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int getSum(int arr[], int cap) {
	int sum = 0;
	for (int i = 0; i < cap; i++) {
		sum = sum + arr[i];
	}

	return sum;
}

double getAverage(int sum, int cap) {
	double average = 0;

	average = (double)sum / cap;

	return average;
}

void printAboveAverage(int arr[], double average, int cap) {
	cout << "numbers above average are: " << endl;
	for (int i = 0; i < cap; i++) {
		if (arr[i] > average) {
			cout << arr[i] << ", ";
		}
	}
	cout << endl;
}
