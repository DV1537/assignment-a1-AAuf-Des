#include <iostream>
#include <fstream>
#include <string>
#include "declarations.h"
using namespace std;

int main(int argc, const char * argv[])
{
    const string file = argv[1];
    int num = 0;
	int index = 0; 
	int arrCap = 1;
    bool validFile;
	int * arr = new int[arrCap];

	validFile = checkIfValid(file);

	if (validFile == false) {
		cout << "file error: invalid file" << endl;
	}
    if (validFile == true){

	    ifstream myReadFile;
	    myReadFile.open(file);

	    while (myReadFile >> num)
	    {
	    	if (index >= arrCap)
		    {
			    arrCap++;
			    int * tempArr = new int[arrCap];
			    for (int i = 0; i < index; i++)
			    {
				    tempArr[i] = arr[i];
			    }
			    delete[] arr;
			    arr = nullptr;
			    arr = tempArr;

		    }
		    arr[index] = num;
		    index++;
	    }
	    //printar alla nummer i filen.
	    printArr(arr, arrCap);

	    int sum = getSum(arr, arrCap);
	
	    double average = getAverage(sum, arrCap);
	
	    cout << endl << "sum: " << sum << endl;
	    cout << "amount of numbers: " << arrCap << endl;
	    cout << "average: " << average << endl << endl;

	    printAboveAverage(arr, average, arrCap);

	    delete[] arr;
	    arr = nullptr;
        system("pause");
    }
	return 0;
}
