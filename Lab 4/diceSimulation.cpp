#include <iostream>
#include <time.h>
using namespace std;

// This class simulates rolling a pair of dice 10,000 times and
// counts the number of times doubles of are rolled for each different
// pair of doubles.

int main()
{
	const int NUMBER = 10000;	//the number of times to roll the dice

	int die1Value;      	// number of spots on the first die
	int die2Value;      	// number of spots on the second die
	int count = 0;	     	// number of times the dice were rolled
	int snakeEyes = 0;  	// number of times snake eyes is rolled
	int twos = 0;			// number of times double two is rolled
	int threes = 0;			// number of times double three is rolled
	int fours = 0;			// number of times double four is rolled
	int fives = 0;			// number of times double five is rolled
	int sixes = 0;			// number of times double six is rolled

	srand(time(NULL));
	//ENTER YOUR CODE FOR THE ALGORITHM HERE
	/*while (count < 10000) {

		die1Value = rand() % 6;
		die2Value = rand() % 6;

		if (die1Value == die2Value) {
			if (die1Value == 0)
				snakeEyes += 1;
			else if (die1Value == 1)
				twos += 1;
			else if (die1Value == 2)
				threes++;
			else if (die1Value == 3)
				fours++;
			else if (die1Value == 4)
				fives++;
			else if (die1Value == 5)
				sixes++;
		}
		count++;
	}
	*/

	/*do {

		die1Value = rand() % 6;
		die2Value = rand() % 6;

		if (die1Value == die2Value) {
			if (die1Value == 0)
				snakeEyes += 1;
			else if (die1Value == 1)
				twos += 1;
			else if (die1Value == 2)
				threes++;
			else if (die1Value == 3)
				fours++;
			else if (die1Value == 4)
				fives++;
			else if (die1Value == 5)
				sixes++;
		}
		count++;
	} while (count < 10000);
	*/

	for(; count < 10000; count++) {

		die1Value = rand() % 6;
		die2Value = rand() % 6;

		if (die1Value == die2Value) {
			if (die1Value == 0)
				snakeEyes += 1;
			else if (die1Value == 1)
				twos += 1;
			else if (die1Value == 2)
				threes++;
			else if (die1Value == 3)
				fours++;
			else if (die1Value == 4)
				fives++;
			else if (die1Value == 5)
				sixes++;
		}
	}
	cout << "You rolled snake eyes " << snakeEyes << " out of " << count << " rolls." << endl;
	cout << "You rolled double twos " << twos << " out of " << count << " rolls." << endl;
	cout << "You rolled double threes " << threes << " out of " << count << " rolls." << endl;
	cout << "You rolled double fours " << fours << " out of " << count << " rolls." << endl;
	cout << "You rolled double fives " << fives << " out of " << count << " rolls." << endl;
	cout << "You rolled double sixes " << sixes << " out of " << count << " rolls." << endl;
}