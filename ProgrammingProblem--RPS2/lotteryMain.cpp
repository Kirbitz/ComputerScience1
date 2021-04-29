#include <iostream>
#include "lotteryFunctions.h"

using namespace std;

/*
Tyler Marefke
Date: 10/22/2019
Assignment: Programming Problem #2
*/

int main() {

	//declared variables including the array lotteryNumbers, array userEnteredNumbers, testing array testArray
	//correctNums, cashValue, and powerball
	int* userEnteredNumbers;
	int* lotteryNumbers;
	int testArray[6] = { 1, 2, 3, 4, 5, 1};
	int correctNums;
	int cashValue;
	bool powerball;

	/*
	Test functions
	correctNums = LotteryNumberComparison(userEnteredNumbers, testArray);

	powerball = PowerBallTest(testArray, userEnteredNumbers);
	*/

	//calls function UserInputLotteryNumbers and sets it equal to userEnterNumbers array
	userEnteredNumbers = UserInputLotteryNumbers();

	//calls function WinningLotteryNumbers and sets it equal to lotteryNumbers array
	lotteryNumbers = WinningLotteryNumbers();

	//calls function LotteryNumberComparison and inputs userEnteredNumbers array and lotteryNumbers array
	//and sets it to correctNums
	correctNums = LotteryNumberComparison(userEnteredNumbers, lotteryNumbers);

	//calls function PowerBallTest and inputs lotteryNumbers array and userEnteredNumbers array and sets
	//it to powerball
	powerball = PowerBallTest(lotteryNumbers, userEnteredNumbers);

	//calls function CashAmountRecieved and inputs correctNums and powerball and sets it to cashValue
	cashValue = CashAmountRecieved(correctNums, powerball);
	
	//Tests for powerball and prints out accordingly
	if (powerball) {
		cout << "You got " << correctNums << " correct and powerball.\n";
		cout << "You earned $" << cashValue << endl;
	}
	else {
		cout << "You got " << correctNums << " correct.\n";
		cout << "You earned $" << cashValue << endl;
	}

	return 0;
}