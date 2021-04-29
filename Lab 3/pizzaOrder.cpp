#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string input;					//user input
	bool discount = false;			//flag, true if user is eligible for discount
	int inches = 0;					//size of the pizza
	char crustType;					//type of crust
	string crust = "Hand-tossed";	//name of crust
	double cost = 0;				//cost of the pizza
	const double TAX_RATE = .08;	//sales tax rate
	double tax;						//amount of tax
	char choice;					//user's choice
	string toppings = "Cheese ";	//list of toppings
	int numberOfToppings = 0;		//number of toppings

	//prompt user and get first name
	cout << "Welcome to Mike and Diane's Pizza" << endl;
	cout << "Are you a new customer? (Y/N)  ";
	cin >> input;

	//determine if user is eligible for discount by
	//by being a new customer
	//ADD LINES HERE FOR TASK #1
	choice = input.at(0);
	if (toupper(choice) == 'Y') 
		discount = true;

	//prompt user and get pizza size choice
	cout << "Pizza Size (inches)   Cost" << endl;
	cout << "        10            $10.99" << endl;
	cout << "        12            $12.99" << endl;
	cout << "        14            $14.99" << endl;
	cout << "        16            $16.99" << endl;
	cout << "What size pizza would you like?" << endl;
	cout << "10, 12, 14, or 16 (enter the number only): "<< endl;
	cin >> inches;

	//set price and size of pizza ordered
	//ADD LINES HER FOR TASK #2
	

	if (inches == 10)
		cost = 10.99;
	else if (inches == 12)
		cost = 12.99;
	else if (inches == 14)
		cost = 14.99;
	else if (inches == 16)
		cost = 16.99;
	else {
		cost = 12.99;
		inches = 12;
	}

	cout << "What type of crust do you want? " << endl;
	cout << "(H)Hand-tossed, (T) Thin-crust, or (D) Deep-dish (enter H, T, or D): ";
	cin >> input;
	crustType = input.at(0);

	//set user's crust choice on pizza ordered
	//ADD LINES FOR TASK #3
	switch (toupper(crustType)) {
		case 'H':
			crust = "Hand-tossed";
			break;
		case 'T':
			crust = "Thin-crust";
			break;
		case 'D':
			crust = "Deep-dish";
			break;
		default:
			crust = "Hand-tossed";
	}

	//prompt user and get topping choices one at a time
	cout << "All pizzas come with cheese." << endl;
	cout << "Additional toppings are $1.25 each, choose from" << endl;
	cout << "Pepperoni, Sausage, Onion, Mushroom" << endl;

	//if topping is desired,
	//add to topping list and number of toppings
	cout << "Do you want Pepperoni?  (Y/N):  ";
	cin >> input;
	choice = input.at(0);

	if (choice == 'Y' || choice == 'y')
	{
		numberOfToppings += 1;
		toppings = toppings + "Pepperoni ";
	}
	cout << "Do you want Sausage?  (Y/N):  ";
	cin >> input;
	choice = input.at(0);
	if (choice == 'Y' || choice == 'y')
	{
		numberOfToppings += 1;
		toppings = toppings + "Sausage ";
	}
	cout << "Do you want Onion?  (Y/N):  ";
	cin >> input;
	choice = input.at(0);
	if (choice == 'Y' || choice == 'y')
	{
		numberOfToppings += 1;
		toppings = toppings + "Onion ";
	}
	cout << "Do you want Mushroom?  (Y/N):  ";
	cin >> input;
	choice = input.at(0);
	if (choice == 'Y' || choice == 'y')
	{
		numberOfToppings += 1;
		toppings = toppings + "Mushroom ";
	}

	//add additional toppings cost to cost of pizza
	cost = cost + (1.25 * numberOfToppings);

	//display order confirmation
	cout << endl;
	cout << "Your order is as follows:  " << endl;
	cout << inches << " inch pizza" << endl;
	cout << crust + " crust" << endl;
	cout << toppings << endl;

	//apply discount if user is eligible
	//ADD LINES FOR TASK #4 HERE
	if (discount) {
		cout << "Congratulations!!!  Since you are a new customer you are eligable for our $2.00 discount.\n";
		cost -= 2;
	}

	//EDIT PROGRAM FOR ASK #5
	//SO ALL MONEY OUTPUT APPEARS WITH 2 DECIMAL PLACES
	cout << "Price: $" << cost << endl;

	//calculate and display tax and total cost
	//calculate and display tax and total cost
	tax = cost * TAX_RATE;
	cout << "Tax:  $" << fixed << setprecision(2) << tax << endl;
	cout << "Total: $" << (tax + cost) << endl;
	cout << "Your order will be ready for pickup in 30 minutes." << endl;

	return 0;
}