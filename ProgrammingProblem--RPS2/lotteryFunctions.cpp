#include <iostream>
#include <time.h>

using namespace std;

/*
Tyler Marefke
Date: 10/22/2019
Assignment: Programming Problem #2
*/

//function random generates the winning lottery numbers including the powerball in an array
//data out: an array containing 5 regular lottery numbers and 1 powerball
int* WinningLotteryNumbers() {

	//variables declared for the array size, temp number, index, counter, lottery numbers array, and duplicate boolean
	const int ARRAY_SIZE = 5;
	int index = 0;
	int counter = 1;
	int tempNum;
	static int lotteryNumbers[6];
	bool notDuplicate;

	//seeds the random number generator
	srand(time(NULL));
	
	//loop the keeps running until index is equal to or greater than ARRAY_SIZE
	while (index < ARRAY_SIZE) {

		//sets notDuplicate to true
		notDuplicate = true;

		//sets the tempNum to a random number
		tempNum = rand() % 99 + 1;

		//tests the index value for zero and sets the value accordingly
		if (index == 0) {
			lotteryNumbers[index] = tempNum;
			index++;
		}
		else {
			//A for loop to test the tempNum against the other values in the area for duplicates
			for (int i = 0; i < counter; i++) {

				//sets notDuplicate for false if duplicate is found
				if (tempNum == lotteryNumbers[i]) {
					notDuplicate = false;
					break;
				}
			}
			
			//adds number to the array if notDuplicate is true
			if (notDuplicate) {
				lotteryNumbers[index] = tempNum;
				counter++;
				index++;
			}

		}
	}

	//inputs the final powerball value into the array from 1 to 99
	lotteryNumbers[5] = rand() % 98 + 1;

	return lotteryNumbers;
}


//function takes user prediction on the lottery numbers and powerball and inserts them into an array
//data out: an array containing the user's lottery predictions
int* UserInputLotteryNumbers() {

	//declares variables for the array size, index, counter, temp number, userEnteredNumbers array, notDuplicate boolean
	const int ARRAY_SIZE = 5;
	int index = 0;
	int counter = 1;
	int tempNum;
	static int userEnteredNumbers[6];
	bool notDuplicate;

	//while loop the runs until index is greater than or equal to ARRAY_SIZE
	while (index < ARRAY_SIZE) {

		//sets notDuplicate to true
		notDuplicate = true;

		//prompts the user for input then assigns it to tempNum
		cout << "Please enter a numter between 1 and 99: \n";
		cin >> tempNum;

		//tests if the users input is between 1 and 99
		if (tempNum > 0 && tempNum < 100) {

			//test if index is 0 and assigns the value to the array accordingly
			if (index == 0) {
				userEnteredNumbers[index] = tempNum;
				index++;
			}
			else {
				
				//for loop the tests the user input against the other numbers in the array
				//to test for duplicates
				for (int i = 0; i < counter; i++) {
					
					//Tests if tempNum is equal to userEnteredNumbers at i
					if (tempNum == userEnteredNumbers[i]) {
						cout << "Invalid Input!  Your input must not match any previous inputs!\n";
						notDuplicate = false;
						break;
					}
				}

				//tests for notDuplicate and sets the userEnteredNumbers[index] to tempNum
				if (notDuplicate) {
					userEnteredNumbers[index] = tempNum;
					counter++;
					index++;
				}

			}
		}
		//Tests input validity
		else {
			cout << "Invalid Input!  Your number must be between 1 and 99!\n";
		}
	}

	//While loop to loop until the user enters a valid value for the powerball
	while (notDuplicate) {
		//prompts the user for a input of the powerball
		cout << "Please enter a powerball value between 1 and 99.\n";
		cin >> tempNum;

		//if tempNum is between 1 and 99 it is set to the last value of the array
		if (tempNum > 0 && tempNum < 100) {
			userEnteredNumbers[5] = tempNum;
			notDuplicate = false;
		}
		else {
			//prompts the user that their input was not between 1 and 99
			cout << "Invalid Input!  Your number must be between 1 and 99!\n";
		}
	}

	return userEnteredNumbers;
}


//function compares the first five values of the lotteryNumbers and userEnteredNumbers and counts the matches
//data in: lotteryNumbers array from the WinningLotteryNumbers function
//data in: userEnteredNumbers array from the UserInputLotteryNumbers
//data out: the number of matches between the lotteryNumbers array and userEnteredNumbers array
int LotteryNumberComparison(const int lotteryNumbers[], const int userEnteredNumbers[]) {
	//declared variables for the array's size and a counter at 0
	const int ARRAY_SIZE = 5;
	int counter = 0;

	//two for loops in order to test all the values of the array against eachother
	for (int index = 0; index < ARRAY_SIZE; index++) {
		for (int index2 = 0; index2 < ARRAY_SIZE; index2++) {
			//tests the values of the array against eachother and increments counter if they are
			if (lotteryNumbers[index] == userEnteredNumbers[index2])
				counter++;
		}
	}

	return counter;
}


//function tests the last value of the lotteryNumbers and userEnteredNumbers and records true of false
//data in: lotteryNumbers array from the WinningLotteryNumbers function
//data in: userEnteredNumbers array from UserInputLotteryNumbers
//data out: a true or false value for whether the user got the powerball or not
bool PowerBallTest(const int lotteryNumbers[], const int userEnteredNumbers[]) {

	//tests the final values of the array and returns true or false accordingly
	return lotteryNumbers[5] == userEnteredNumbers[5];
}


//function determines the cash the user recieves based on their number of matches and powerball
//data in: counter from the LotteryNumberComparison function
//data in: powerball from the PowerBallTest function
//data out: the amount of cash recieved
int CashAmountRecieved(int counter, bool powerball) {

	//declared variable for the cashAmount to recieve
	int cashAmount;

	//Tests powerball for true or false and goes to the corresponding switch statement
	if (powerball) {
		//Tests counter for case and sets cashAmount to the corresponding value
		switch (counter) {
			case 1:
				cashAmount = 25;
				break;
			case 2:
				cashAmount = 75;
				break;
			case 3:
				cashAmount = 200;
				break;
			case 4:
				cashAmount = 1000;
				break;
			case 5:
				cashAmount = 50000;
				break;
			default:
				cashAmount = 10;
		}
	}
	else {
		//Tests counter for the case and sets cashAmount to the corresponding value
		switch (counter) {
			case 1:
				cashAmount = 5;
				break;
			case 2:
				cashAmount = 15;
				break;
			case 3:
				cashAmount = 50;
				break;
			case 4:
				cashAmount = 100;
				break;
			case 5:
				cashAmount = 500;
				break;
			default:
				cashAmount = 0;
		}
	}

	return cashAmount;
}