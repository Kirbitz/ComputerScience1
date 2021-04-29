#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 12;
	char ssNum[SIZE];
	bool isValid = true;	

	cout << "Enter a social security number in the format ###-##-####" << endl;
	//this version of getline stores the typed characters into a c-string 
	cin.getline(ssNum, SIZE); 
	//this is to prove that a c-string ends in 
	if (ssNum[SIZE-1] == '\0') cout << "null character" << endl;

	//validate the format to be ###-##-####
	bool tester = true;
	for (int i = 0; i < SIZE - 1; ++i) {
		if (i == 3 || i == 6) {
			if (ssNum[i] != '-') {
				cout << "Invalid Input!\nDash not located at position " << i + 1 << "!\n";
				tester = false;
			}
		}
		else if (!isdigit(ssNum[i])) {
			cout << "Invalid Input!\nNumber not located at position " << i + 1 << "!\n";
			tester = false;
		}
	}

	if (tester) {
		cout << "Your social security number is " << ssNum << endl;
	}
	
	
	
	
	return 0;
}