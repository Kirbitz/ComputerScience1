#include <iostream>
using namespace std;

void DoubleValue(int myArray[], int size);
void TripleValue(int* arrayPtr, int size);

int main()
{
	const int SIZE = 5;
	int numbers[SIZE];
	
	//fill the array
	for (int i = 0; i < SIZE; i++)
	{
		numbers[i] = 5 * i;
	}

	//print the array
	for (int i = 0; i < SIZE; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	
	//Call DoubleValue
	//print the array
	DoubleValue(numbers, SIZE);
	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
	
	//call TripleValue
	//print the array
	TripleValue(numbers, SIZE);
	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
	
	return 0;
}

void DoubleValue(int myArray[], int size) {
	for (int i = 0; i < size; i++) {
		myArray[i] *= 2;
	}
}

void TripleValue(int* arrayPtr, int size) {
	for (int i = 0; i < size; i++) {
		*(arrayPtr + i) *= 3;
	}
}