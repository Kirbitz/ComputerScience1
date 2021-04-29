#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main() {
	
	//Declared variables for the do while loop
	string line;
	char test;
	bool contin = true;
	
	//Declared variables for computer and user input for the game
	bool choiceMade = true;
	int compSelect;
	int userAns;
	char userSelect;
	string userInput;
	string upperUserInput;

	do{

		//Sets the upperUserInput to blank
		upperUserInput = "";
	//Menu prompt for the user to play traditional or Big Bang rock paper scissors
	cout << "Do you want to play Rock, Paper, Scissors traditional or Big Bang Version: (T/B)\n";
	getline(cin, userInput);

	//Sets users input to upper case
	for (int i = 0; i < userInput.size(); i++)
		upperUserInput += toupper(userInput.at(i));

	//Tests user input for Big Bang
	if (upperUserInput == "BIG BANG" || upperUserInput == "B") {

		while(choiceMade){
			//Reset upperUserInput variable
			upperUserInput = "";

			//Prompt user for their choice in the game
			cout << "Choose rock, paper, scissors, lizard, and spock: \n";
			cin >> userInput;

			//Sets userInput to uppercase
			for (int i = 0; i < userInput.size(); i++)
				upperUserInput += toupper(userInput.at(i));

			//Tests if user has entered a valid input and then sets appropriate char variable
			if (upperUserInput == "ROCK") {
				userSelect = 'R';
				choiceMade = false;
			}else if (upperUserInput == "PAPER") {
				userSelect = 'P';
				choiceMade = false;
			}else if (upperUserInput == "SCISSORS") {
				userSelect = 'S';
				choiceMade = false;
			}else if (upperUserInput == "LIZARD") {
				userSelect = 'L';
				choiceMade = false;
			}else if (upperUserInput == "SPOCK") {
				userSelect = 'C';
				choiceMade = false;
			}else
				cout << "Invalid Input!\n";
		}
		
		//Computer randomly selects a number for its anwser
		srand(time(NULL));
		compSelect = rand() % 5;

		//Tests the computer's input vs. the user's input through nested switches then gives final verdict
		switch (toupper(userSelect)) {
		case 'R':

			switch (compSelect) {
			case 0:
				cout << "Rock v Rock...Tie Game.\n";
				break;
			case 1:
				cout << "Rock v Paper...You Lose.\n";
				break;
			case 2:
				cout << "Rock v Scissors...You Win!\n";
				break;
			case 3:
				cout << "Rock v Lizard...You Win!\n";
				break;
			case 4:
				cout << "Rock v Spock...You Lose.\n";
				break;
			}
			break;
		case 'P':
			switch (compSelect) {
			case 0:
				cout << "Paper v Rock...You Win!\n";
				break;
			case 1:
				cout << "Paper v Paper...Tie Game.\n";
				break;
			case 2:
				cout << "Paper v Scissors...You Lose.\n";
				break;
			case 3:
				cout << "Paper v Lizard...You Lose.\n";
				break;
			case 4:
				cout << "Paper v Scissors...You Win!\n";
				break;
			}
			break;
		case 'S':
			switch (compSelect) {
			case 0:
				cout << "Scissors v Rock...You Lose.\n";
				break;
			case 1:
				cout << "Scissors v Paper...You Win!\n";
				break;
			case 2:
				cout << "Scissors v Scissors...Tie Game.\n";
				break;
			case 3:
				cout << "Scissors v Lizard...You Win!\n";
				break;
			case 4:
				cout << "Scissors v Spock...You Lose.\n";
				break;
			}
			break;
		case 'C':
			switch (compSelect) {
			case 0:
				cout << "Spock v Rock...You Win!\n";
				break;
			case 1:
				cout << "Spock v Paper...You Lose!\n";
				break;
			case 2:
				cout << "Spock v Scissors...You Win!\n";
				break;
			case 3:
				cout << "Spock v Lizard...You Lose.\n";
				break;
			case 4:
				cout << "Spock v Spock...Tie Game.\n";
				break;
			}
			break;
		case 'L':
			switch (compSelect) {
			case 0:
				cout << "Lizard v Rock...You Lose.\n";
				break;
			case 1:
				cout << "Lizard v Paper...You Win!\n";
				break;
			case 2:
				cout << "Lizard v Scissors...You Lose.\n";
				break;
			case 3:
				cout << "Lizard v Lizard...Tie Game.\n";
				break;
			case 4:
				cout << "Lizard v Spock...You Win!\n";
				break;
			}
			break;
		default:
			cout << "NOT AN ANWSER!!!  YOU LOSE!!!\n";
		}
	
	
	}
	//Tests the userInput for traditional
	else if(upperUserInput == "TRADITIONAL" || upperUserInput == "T"){

		//Loop to make sure the user enters a valid choice
		while (choiceMade) {
			//resets upperUserInput variable
			upperUserInput = "";


			cout << "Choose rock, paper, or scissors: \n";
			cin >> userInput;

			//Sets userInput to uppercase
			for (int i = 0; i < userInput.size(); i++)
				upperUserInput += toupper(userInput.at(i));

			//Tests if user has entered a valid input and then sets appropriate char variable
			if (upperUserInput == "ROCK") {
				userSelect = 'R';
				choiceMade = false;
			}
			else if (upperUserInput == "PAPER") {
				userSelect = 'P';
				choiceMade = false;
			}
			else if (upperUserInput == "SCISSORS") {
				userSelect = 'S';
				choiceMade = false;
			}else
				cout << "Invalid Input!\n";
		}
		//Computer makes a random choice for its anwser
		srand(time(NULL));
		compSelect = rand() % 3;

		//Switch cases test the User's input vs the computer through nested switch statments and displays outcome
		switch (toupper(userSelect)) {
			case 'R':
				
				switch (compSelect) {
					case 0:
						cout << "Rock v Rock...Tie Game.\n";
						break;
					case 1:
						cout << "Rock v Paper...You Lose.\n";
						break;
					case 2:
						cout << "Rock v Scissors...You Win!\n";
						break;
				}
				break;
			case 'P':
				switch (compSelect) {
				case 0:
					cout << "Paper v Rock...You Win!\n";
					break;
				case 1:
					cout << "Paper v Paper...Tie Game.\n";
					break;
				case 2:
					cout << "Paper v Scissors...You Lose.\n";
					break;
				}
				break;
			case 'S':
				switch (compSelect) {
				case 0:
					cout << "Scissors v Rock...You Lose.\n";
					break;
				case 1:
					cout << "Scissors v Paper...You Win!\n";
					break;
				case 2:
					cout << "Scissors v Scissors...Tie Game.\n";
					break;
				}
				break;
			default:
				cout << "NOT AN ANWSER!!!  YOU LOSE!!!\n";
		}

	}
	//Throws statement for invalid input from the user
	else {
		cout << "Invalid Input!\n";
	}

	//Resets variable choice made to true
	choiceMade = true;
		
		//Prompts the user whether or not they want to play again
		cout << "Would you like to play again? (Y/N)\n";
		cin >> line;
		cin.ignore();
		test = line.at(0);

		//Tests the user input for starting character N or S
		if ((toupper(test) == 'N') || (toupper(test) == 'S'))
			contin = false;
	} while (contin);

	return 0;
}