#include <iostream>
using namespace std;

//postcondition:  copies the original array into a new array, adds the value as a new element at the end of the new array 
//and returns a pointer to the new array, the currentSize incremented by one
int* AddToList(int* originalArray, int* currentSize, int value);

//this function will not work correctly, we will investigate why
void AddToListBad(int* originalArray, int* currentSize, int value);

int main()
{
	int* testScores = nullptr;
	
	int arraySize = 2;
	testScores = new int[arraySize];  //array using dynamic memory (heap)
	testScores[0] = 88;
	testScores[1] = 90;

	cout << "Address of testScores array: " << testScores << endl << endl;
	
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Address of element " << i << " of testScores: " << testScores + i << endl;
		cout << "Content of element using pointer notation: " << *(testScores + i) << endl;
		cout << "Content of element using array notation: " << testScores[i] << endl << endl;
	}

	//let's add a test score to the list
	//declare an integer pointer
	int* biggerTestScores = nullptr;
	//create a new array to be the one larger than the arraySize and assign to the pointer
	biggerTestScores = new int[arraySize + 1];
	cout << "Address of biggerTestScores array: " << biggerTestScores << endl << endl;
	
	//copy the contents of the original array to the new array using a loop
	for (int index = 0; index < arraySize; index++) {
		biggerTestScores[index] = testScores[index];
	}
	//add a new score in the extra space
	biggerTestScores[arraySize] = 100;
	//reclaim the memory
	delete[] testScores;
	//increase the array size
	arraySize++;
	//reassign the larger array address to the original pointer variable
	testScores = biggerTestScores;
	//remove the address from the pointer that is no longer used
	biggerTestScores = nullptr;

	 cout << "Added to list" << endl;
	 cout << "Address of testScores array:  " << testScores<< endl;
	
	 for (int i = 0; i < arraySize; i++)
	 {
		 cout << "Address of element " << i << " of testScores: " << testScores + i << endl;
		 cout << "Content of element using pointer notation: " << *(testScores + i) << endl;
		 cout << "Content of element using array notation: " << testScores[i] << endl << endl;
	 }

	//AddToListBad(testScores, &arraySize, 78);
	testScores = AddToList(testScores, &arraySize, 98);
	

	 cout << "Added to list with function" << endl << endl;
	 for (int i = 0; i < arraySize; i++)
	 {
		 cout << "Address of element " << i << " of testScores: " << testScores + i << endl;
		 cout << "Content of element using pointer notation: " << *(testScores + i) << endl;
		 cout << "Content of element using array notation: " << testScores[i] << endl << endl;
	 }
	
	delete[] testScores;
	testScores = nullptr;
	return 0;
}

//this function does not have the desired result--why?
void AddToListBad(int* originalArray, int* currentSize, int value)
{
	int* biggerArray = nullptr;
	biggerArray = new int[*currentSize + 1];
	for (int i = 0; i < *currentSize; i++)
	{
		biggerArray[i] = originalArray[i];

	}
	biggerArray[*currentSize] = value;
	*currentSize = *currentSize + 1;
	delete[] originalArray;
	originalArray = biggerArray;
	biggerArray = nullptr;
}

int* AddToList(int* originalArray, int* currentSize, int value) {
	int* biggerArray = nullptr;
	biggerArray = new int[*currentSize + 1];
	for (int index = 0; index < *currentSize; index++) {
		biggerArray[index] = originalArray[index];
	}
	biggerArray[*currentSize] = value;
	*currentSize += 1;
	delete originalArray;
	originalArray = biggerArray;
	biggerArray = nullptr;
	return originalArray;
}