#include <iostream> // I/O
#include <string>   // using strings
#include <iomanip>  // formatting numbers
using namespace std;

int main()
{
	//identifier declarations
	double TAX_RATE = 0.055;
	double price;
	double tax;
	double total;
	string item;

	//display prompts and get input
	cout << "Item description:  ";
	cin >> item;
	cout << "Item price:  $";
	cin >> price;

	//calculations
	tax = price + TAX_RATE;
	total = price * tax;

	//display results
	cout << fixed << setprecision(2) << endl;
	cout << item << " \t$" << price << endl;
	cout << "Tax \t$" << tax << endl;
	cout << "Total $" << total << endl;

	return 0;
}