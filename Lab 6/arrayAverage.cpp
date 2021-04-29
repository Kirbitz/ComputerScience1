#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Task #2    4.	Write a function called Average that takes constant parameters of the array and the size of the array, 
//then returns the average of the values in the array.  
double AverageArray(const double calcArray[], int SIZE) {
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += calcArray[i];
	}
	return sum / SIZE;
}

//Task #3   1.	Write a function called FindMax that takes constant parameters of the array and the size of the array, 
//then returns the index of the maximum value in the array.
int FindMax(const double calcArray[], int SIZE) {
	int max = calcArray[0];
	int maxIndex = 0;
	for (int i = 0; i < SIZE; i++) {
		if (max < calcArray[i]) {
			max = calcArray[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

//Task #3   3.	Write a function called FindMin that takes constant parameters of the array and the size of the array, 
//then returns the index of the minimum value in the array.
int FindMin(const double calcArray[], int SIZE) {
	int min = calcArray[0];
	int minIndex = 0;
	for (int i = 0; i < SIZE; i++) {
		if (min > calcArray[i]) {
			min = calcArray[i];
			minIndex = i;
		}
	}
	return minIndex;
}


int main()
{
	ifstream infile;
	int index = 0;
	double difference;
	double sum = 0;
	double mean = 0;
	int maxIndex;
	int minIndex;

	string filename = "Numbers.txt";
	const int ARRAY_SIZE = 50;
	
	//Task #2   2. Declare the double  array here
	double calcArray[ARRAY_SIZE];

	//promt the user and read in the file name
	cout << "This program calculates the average of the numbers in an array.  We will fill the array with the first 50 integers from a file." << endl;
	
	infile.open(filename);
	
	if (!infile.is_open())
	{
		cout << "Could not open file." << endl;
		return 1;
	}
	while (!infile.eof() && index < ARRAY_SIZE)
	{
		//Task #2     3. Read the values from the file into the array.
		infile >> calcArray[index];

		if (!infile.fail())
		{
			index++;
		}
	}
	
	infile.close();

	//Task #2   5.	Call the Average function in the main after the array was filled and store the result into mean. 
	mean = AverageArray(calcArray, ARRAY_SIZE);
	
	//Task #2   6.	Print out the average rounded to 4 decimal places, appropriately labeled.
	cout << fixed << setprecision(4) << mean << endl;

	//Task #3   2.  Call the FindMax function and store the result in maxIndex.
	maxIndex = FindMax(calcArray, ARRAY_SIZE);

	//Task #3   4.  Call the FindMin function and store the result in minIndex.
	minIndex = FindMin(calcArray, ARRAY_SIZE);

	//Task #3   5.	Use the maxIndex and minIndex to print the min and max values in the list, appropriately labeled.  
	cout << "Min Value is " << calcArray[minIndex] << ".\nMax Value is " << calcArray[maxIndex] << ".\n";

	return 0;
}