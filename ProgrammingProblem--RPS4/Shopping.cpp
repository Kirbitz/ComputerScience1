#include "ShopFunctions.h"

using namespace std;


/*
Tyler Marefke
Programming Project RPS--4
12/8/2019
*/
int main() {
	//Initializes numAns to 8, userAnswer, downloads to CreateDownload() function, and johnWick
	int numAns = 8;
	string userAnswer;
	vector<DigitalDownload> downloads = CreateDownload();
	Customer johnWick;

	//Sets the name of johnWick to John Wick
	johnWick.SetName("John Wick");
	
	//Greets the user
	cout << "Hello " << johnWick.GetName() << " please select one of the following options.\n";

	do {
		//Calls the PrintMenu function from the ShopFunctions.cpp
		PrintMenu(johnWick);
		do {
			//Takes in the user input and tests to make sure it is a number
			getline(cin, userAnswer);
			if (isdigit(userAnswer.at(0))) {
				userAnswer = userAnswer.at(0);
				numAns = stoi(userAnswer);
			}
			else {
				cout << "Invalid input!\nPlease enter a valid input!\n";
			}
		} while (!isdigit(userAnswer.at(0)));
		//tests if numAns if equal to 8
		if (numAns == 8) {
			//Prints a thank you to the user and ends the program
			cout << "Thank you for shopping with us today.\n";
			return 1;
		}
		else {
			//Runs the MenuSelection function from the ShopFunctions.cpp
			MenuSelection(numAns, johnWick, downloads);
		}
	} while (numAns != 7 || !johnWick.GetLogIn());


	return 0;
}