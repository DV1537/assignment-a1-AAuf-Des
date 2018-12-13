#include <iostream>
#include <fstream>
#include <string>
#include "declarations.h"
using namespace std;

//final commit//

//checks all criterias for the file to be valid.
bool checkIfValid(string file){
    bool isValid;
	bool fileExist;

	fileExist = checkIfFileExist(file);

	if (fileExist == true){
		isValid = checkForEmpty(file);

		if (isValid == true){
			isValid = checkForCharacters(file);
		}

		if (isValid == true){
			isValid = checkForMultipleLines(file);
		}

		if (isValid == true){
			isValid = checkForFewNums(file);
		}
	}
	else{
		isValid = false;
	}

	return isValid;
}
//checks so that file exist i.e. that argv is correct.
bool checkIfFileExist(string file){
	string str;
	bool fileExist;

    ifstream myFile(file);
    if (myFile.fail()){
        cout << "error: " << file << " does not exist." << endl;
		fileExist = false;
    }
    else{
		
        fileExist = true;
    }
    myFile.close();
    return fileExist;
}

//checks for completly empty file.
bool checkForEmpty(string file){
	ifstream myReadFile;
	string str;
	bool isValid = true;
	myReadFile.open(file);

	getline(myReadFile, str);

	if (str.size() == 0){
		isValid = false;
		cout << "Error: file contains nothing." << endl;
	}

	myReadFile.close();

	return isValid;
}

// check if inputfile have more than 1 line.
bool checkForMultipleLines(string file){
	string str;
	bool isValid = true;
    ifstream myFile;
    int count = 0;

    myFile.open(file);
    while (!(myFile.eof())){
        getline(myFile, str);
        count++;
    }
    
	if (count > 1){
		isValid = false;
		cout << "error: the file contains to many lines." << endl;
	}
	else{
		isValid = true;
	}
    myFile.close();

    return isValid;
}



//checks file so that is contains more than 1 characters. 
bool checkForFewNums(string file){
	ifstream myFile;
	bool isValid = true;
	int x;
	int count = 0;

	myFile.open(file);

	while (!(myFile.eof())){
		myFile >> x;
		count ++;
	}

	if (count <= 1){
		isValid = false;
		cout << "error: the files contains to few numbers." << endl;
	}
	else if (count > 1){
		isValid = true;
	}
	
	myFile.close();
	return isValid;
}
//check file so that it does not contain any chars other than space or " - "
bool checkForCharacters(string file){
	char num;
	bool isValid = true;

	ifstream myReadFile;
	myReadFile.open(file);

	while (myReadFile >> num && isValid == true)
	{
		if (isdigit(num) || num == '-') {
			isValid = true;
		}
		else {
			isValid = false;
			cout << "error: file contains characters" << endl;
		}
	}
	
	myReadFile.close();
	return isValid;
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
	for (int i = 0; i < cap; i++) {
		if (arr[i] > average) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
