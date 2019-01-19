#include <iostream>
#include <fstream>
#include <string>
#include "declarations.h"
using namespace std;

//final commit//

//a
int main(int argc, const char * argv[])
{
    int num = 0;
	int index = 0; 
	int arrCap = 1;
    bool validFile;
	int * arr = new int[arrCap];

	validFile = checkIfValid(argv[1]);

	if(validFile == false){
		cout << "invalid file" << endl;
	}

    if (validFile == true){

	    ifstream myReadFile;
	    myReadFile.open(argv[1]);

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
	    int sum = getSum(arr, arrCap);
	
	    double average = getAverage(sum, arrCap);

	    printAboveAverage(arr, average, arrCap);

	    delete[] arr;
	    arr = nullptr;
    }
	return 0;
}
