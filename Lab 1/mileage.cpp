//This program is used for calculating the miles per gallon on the users vehicle
//Tyler Marefke 9/6/2019

#include <iostream>
using namespace std;

int main()
{
	double miles;
	//Miles is used to indicate the amount of miles the user has driven
	double gallons;
	//Gallons is used to indicate how many gallons the user has used
	double total;
	//Total is the final calculation for miles per gallon by dividing miles by gallons

	cout << "This program is for calculating miles per gallon." << endl;
	cout << "How many miles have you driven?" << endl;
	cin >> miles;
	cout << "How many gallons were used?" << endl;
	cin >> gallons;

	//This section askes the user how many miles were driven and gallons used and applied to miles and gallons variables
	
	total = miles / gallons;

	//This calculates the miles per gallons the the user used in their vehicle

	cout << "Your vehicle uses " << total << " miles/gallon." << endl;

	//This shows the user what their miles per gallon is

	return 0;
}

