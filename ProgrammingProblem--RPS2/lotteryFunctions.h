#ifndef lotteryFunctions
#define lotteryFunctions

/*
Tyler Marefke
Date: 10/22/2019
Assignment: Programming Problem #2
*/

//function random generates the winning lottery numbers including the powerball in an array
//data out: an array containing 5 regular lottery numbers and 1 powerball
int* WinningLotteryNumbers();


//function takes user prediction on the lottery numbers and powerball and inserts them into an array
//data out: an array containing the user's lottery predictions
int* UserInputLotteryNumbers();


//function compares the first five values of the lotteryNumbers and userEnteredNumbers and counts the matches
//data in: lotteryNumbers array from the WinningLotteryNumbers function
//data in: userEnteredNumbers array from the UserInputLotteryNumbers
//data out: the number of matches between the lotteryNumbers array and userEnteredNumbers array
int LotteryNumberComparison(const int[], const int[]);


//function tests the last value of the lotteryNumbers and userEnteredNumbers and records true of false
//data in: lotteryNumbers array from the WinningLotteryNumbers function
//data in: userEnteredNumbers array from UserInputLotteryNumbers
//data out: a true or false value for whether the user got the powerball or not
bool PowerBallTest(const int[], const int[]);


//function determines the cash the user recieves based on their number of matches and powerball
//data in: counter from the LotteryNumberComparison function
//data in: powerball from the PowerBallTest function
//data out: the amount of cash recieved
int CashAmountRecieved(int, bool);


#endif
