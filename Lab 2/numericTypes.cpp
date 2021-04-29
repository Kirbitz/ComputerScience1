#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
using namespace std;

//This program demonstrates how numeric types and operators behave in C++

int main()
{
	//identifier declarations
	const int NUMBER = 2;			// number of scores
	const int SCORE1 = 100;			// first test score
	const int SCORE2 = 95;			// second test score
	const int BOILING_IN_F = 212;  	// freezing temperature
	int fToC;						// temperature in celsius
	double average;					// arithmetic average
	string output;					// line of output to print out
	//TASK #2 declare variables used here
	string fullName;
	//TASK #3 declare variables used here
	char firstInitial;
	int nameLength;
	//TASK #4 declare variables used here
	double diameterSphere;
	double radiusSphere;
	double volumeSphere;
	const double pi = 3.14159265359;
	//TASK #5 declare variables used here
	int randVal1;
	int randVal2;
	int randVal3;

	// Find an arithmetic average
	average = ((double) SCORE1 + SCORE2) / NUMBER;
	cout << SCORE1 << " and " << SCORE2 << " have an average of " << average << endl;

	// Convert Fahrenheit temperatures to Celsius
	fToC = (double)5 / 9 * (BOILING_IN_F - 32);
	cout << BOILING_IN_F << " in Fahrenheit is " << fToC << " in Celsius." << endl;
	
	cout << endl;		// to leave a blank line
	
	// ADD LINES FOR TASK #2 HERE
	// prompt the user for full name
	cout << "Please enter your full name: \n";

	// read the user's full name
	getline(cin, fullName);
	// print out the user's full name 
	cout << "Your name is " << fullName;
	cout << endl;		// to leave a blank line

	// ADD LINES FOR TASK #3 HERE
	// get the first character from the user's full name
	firstInitial = fullName.at(0);
	nameLength = fullName.length();
	// print out the user's first initial
	cout << "Your first initial is " << firstInitial << ".\n";
	// print out the number of characters in the user's full name 
	cout << "Your Name has " << nameLength << " letters.\n";

	cout << endl;		// to leave a blank line

	// ADD LINES FOR TASK #4 HERE
	// prompt the user for a diameter of a sphere
	cout << "Please enter the diameter of your sphere.\n";
	// read the diameter
	cin >> diameterSphere;
	// calculate the radius
	radiusSphere = diameterSphere / 2;
	// calculate the volume 
	volumeSphere = (4.0 / 3) * pi * pow(radiusSphere, 3.0);
	// print out the volume
	cout << "The volume of your sphere is " << volumeSphere << ".\n";
	
	cout << endl;		// to leave a blank line
	
	// ADD LINES FOR TASK #5 HERE
	// generate three winning numbers 0-9
	srand(time(NULL));
	randVal1 = rand() % 10;
	randVal2 = rand() % 10; 
	randVal3 = rand() % 10;
	// print the three numbers
	cout << "The winning lottery numbers are " << randVal1 << ", " << randVal2 << ", and " << randVal3 << ".\n";
	
	return 0;
}