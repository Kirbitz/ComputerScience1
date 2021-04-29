#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//Task #2    4.	Write a function called Average that takes constant parameters of the array and the size of the array, 
//then returns the average of the values in the array.  
double AverageArray(vector<double> value) {
	double sum = 0;
	for (int i = 0; i < value.size(); i++) {
		sum += value[i];
	}
	return sum / value.size();
}

//Task #3   1.	Write a function called FindMax that takes constant parameters of the array and the size of the array, 
//then returns the index of the maximum value in the array.
int FindMax(vector<double> value) {
	int max = value[0];
	int maxIndex = 0;
	for (int i = 0; i < value.size(); i++) {
		if (max < value[i]) {
			max = value[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

//Task #3   3.	Write a function called FindMin that takes constant parameters of the array and the size of the array, 
//then returns the index of the minimum value in the array.
int FindMin(vector<double> value) {
	int min = value[0];
	int minIndex = 0;
	for (int i = 0; i < value.size(); i++) {
		if (min > value[i]) {
			min = value[i];
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
	double inputValues;

	string filename = "Numbers.txt";
	const int ARRAY_SIZE = 50;
	
	//Task #2   2. Declare the double  array here
	double calcArray[ARRAY_SIZE];

	vector<double> value;
	//promt the user and read in the file name
	cout << "This program calculates the average of the numbers in an array.  We will fill the array with the first 50 integers from a file." << endl;
	
	infile.open(filename);
	
	if (!infile.is_open())
	{
		cout << "Could not open file." << endl;
		return 1;
	}
	
	while (!infile.eof())
	{
		//Task #2     3. Read the values from the file into the array.
		infile >> inputValues;
		value.push_back(inputValues);

		if (!infile.fail())
		{
			index++;
		}
	}
	
	infile.close();

	//Task #2   5.	Call the Average function in the main after the array was filled and store the result into mean. 
	mean = AverageArray(value);
	
	//Task #2   6.	Print out the average rounded to 4 decimal places, appropriately labeled.
	cout << fixed << setprecision(4) << mean << endl;

	//Task #3   2.  Call the FindMax function and store the result in maxIndex.
	maxIndex = FindMax(value);

	//Task #3   4.  Call the FindMin function and store the result in minIndex.
	minIndex = FindMin(value);

	//Task #3   5.	Use the maxIndex and minIndex to print the min and max values in the list, appropriately labeled.  
	cout << "Min Value is " << value[minIndex] << ".\nMax Value is " << value[maxIndex] << ".\n";

	for(int i = 0; i < 3; i++)
		value.pop_back();

	mean = AverageArray(value);
	cout << mean << endl;
	return 0;
}