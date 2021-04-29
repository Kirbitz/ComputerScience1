#include <iostream>;	//needed for input/output
using namespace std;	//needed for input/output

//This program calculates the user's gross pay
int main()
{
	//identifier declarations
	double hours;  //hours worked
	double rate;	//hourly pay rate
	double pay;		//gross pay

	//display prompts and get input
	cout << "How many hours did you work? ";
	cin >> hours;
	cout << "How much do you get paid per hour? ";
	cin >> rate;

	//calculations
	if (hours <= 40)
		pay = hours * rate;
	else
		pay = (hours - 40) * (1.5 * rate) + 40 * rate;

	//display results
	cout << "You will get paid $" << pay;

	return 0;
}