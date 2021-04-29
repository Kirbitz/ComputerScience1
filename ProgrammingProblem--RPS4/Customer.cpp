#include "Customer.h"
#include <iostream>

/*
Creates a Customer object and intializes numItemsOrdered to 0, shoppingCart to nullptr, and loggedIn to false
Data out: Customer object
*/
Customer::Customer() {
	//Initializes variables numItemsOrdered to 0, shoppingCart to nullptr, and loggedIn to false
	numItemsOrdered = 0;
	shoppingCart = nullptr;
	loggedIn = false;
}

/*
Calls the destroctor and deletes the array that shoppingCart is pointing to in the heap
*/
Customer::~Customer() {
	delete[] shoppingCart;
}

/*
Logs the customer in so long as they provide the correct username
Changes loggedIn to true
*/
void Customer::Login() {
	//Initializes variable answer
	string answer;
	do {
		//prompts the user for their login username
		cout << "Please enter your name for login:\n";
		getline(cin, answer);

		//Initializes nameUpper to "" and myNameUpper to ""
		string nameUpper = "";
		string myNameUpper = "";

		//for loop to make nameUpper an all caps version of answer
		for (int i = 0; i < answer.size(); ++i) {
			nameUpper += toupper(answer.at(i));
		}

		//for loop to make myNameUpper an all caps version of this Customer object's name
		for (int i = 0; i < this->name.size(); ++i) {
			myNameUpper += toupper(this->name.at(i));
		}

		//Tests if myNameUpper and nameUpper are equal to eachother
		if (myNameUpper == nameUpper) {
			//Changes loggedIn to true and sets answer to N
			this->loggedIn = true;
			answer = "N";
		}
		else {
			//Prompts the user that they entered the incorrect login and asks if they want to try again
			cout << "Login failed!\nIncorrect Username Entered!\n";
			cout << "Would you like to try again?(Y/N)\n";
			cin >> answer;
			cin.ignore();
			answer.at(0) = toupper(answer.at(0));
		}
	} while (answer.at(0) != 'N');
}

/*
Logs the customer out
Changes loggedIn to false
*/
void Customer::Logout() {
	//Sets loggedIn variable to false
	this->loggedIn = false;
}

/*
Adds a digital download to the customers shopping cart from the available downloads
Data in: item
*/
void Customer::AddToShoppingCart(DigitalDownload item) {
	//Tests if numItemsOrdered is equal to 0
	if (numItemsOrdered == 0) {

		//Initializes shoppingCart to an array of DigitalDownloads with size of 1 and puts item as the first object
		//also increments numItemsOrdered by 1
		shoppingCart = new DigitalDownload[1];
		shoppingCart[0] = item;
		numItemsOrdered++;
	}
	else {

		//Creates a new pointer biggerCart and makes it a DigitalDownload array 1 bigger than numItemsOrdered
		DigitalDownload* biggerCart = new DigitalDownload[numItemsOrdered + 1];

		//for loop puts all contents of shoppingCart in biggerCart
		for (int i = 0; i < numItemsOrdered; ++i) {
			biggerCart[i] = shoppingCart[i];
		}

		//Sets item as the object in the last position in biggerCart array and increments numItemsOrdered
		biggerCart[numItemsOrdered] = item;
		++numItemsOrdered;

		//Reclaims shoppingCart array memory from the heap and sets shoppingCart point location to biggerCart point location
		delete[] shoppingCart;
		shoppingCart = biggerCart;

		//Sets biggerCart to nullptr
		biggerCart = nullptr;
	}
}

/*
RemoveItemFromCart function removes the requested item from the customer's shopping cart and updates accordingly
Data in: item
*/
void Customer::RemoveItemFromCart(DigitalDownload item) {
	//Initializes numpos, and foundItem to false
	int numpos;
	bool foundItem = false;

	//Tests if numItemsOrdered is greater than 0
	if (numItemsOrdered > 0) {

		//for loop to find the location of item in shoppingCart array
		for (int i = 0; i < numItemsOrdered; ++i) {
			//Tests if shoppingCart at i is equal to item
			if (shoppingCart[i] == item) {
				//Sets numpos to i and sets foundItem to true
				numpos = i;
				foundItem = true;
				break;
			}
		}

		//tests if foundItem is true
		if (foundItem) {
			//Creates a smallerShoppingCart pointer and sets it to a DigitalDownloadArray that is 1 smaller than numItemsOrdered
			DigitalDownload* smallerShoppingCart = new DigitalDownload[numItemsOrdered - 1];
			//for loop that sets the items of shopping cart to smallShopping cart based on whether i is less than or greater than numpos
			for (int i = 0; i < numItemsOrdered; ++i) {
				if (i < numpos) {
					smallerShoppingCart[i] = shoppingCart[i];
				}
				else if (i > numpos) {
					smallerShoppingCart[i - 1] = shoppingCart[i];
				}
			}
			//Decrements numItemsOrdered by 1 and reclaims shoppingCart array from the heap
			numItemsOrdered--;
			delete[] shoppingCart;

			//Sets shoppingCart to smallShoppingCart and sets smallerShoppingCart to nullptr
			shoppingCart = smallerShoppingCart;
			smallerShoppingCart = nullptr;

			//Prompts the user that their cart has been updated
			cout << "Your cart has been successfully updated!\n";
		}
		else {
			//Prompts the user that the item they entered is not in their shopping cart
			cout << "That item does not exist in your shopping cart!\n";
		}
	}
	else {
		//Prompts the user that nothing is in their shopping cart
		cout << "Your currently have no items in your cart!\n";
	}
}

/*
Prints out the customers shopping cart also accounts for if nothing is in the cart
*/
void Customer::PrintCart() {
	//Tests if numItemsOrdered is equal to 0
	if (this->numItemsOrdered == 0) {
		//Prompts the user that nothing is in their cart
		cout << "Nothing is in your cart!\n";
	}
	else {
		//Prompts the user of what is currently in their cart
		cout << "Your cart currently has: \n";
		for (int i = 0; i < this->numItemsOrdered; ++i) {
			cout << this->shoppingCart[i];
		}
	}
}

/*
Sets the customer's name
Data in: name
*/
void Customer::SetName(string name) {
	this->name = name;
}

/*
Gets the customer's current name
*/
string Customer::GetName() {
	return this->name;
}

/*
Retrieves the total price of all the digital downloads in the shopping cart
*/
double Customer::GetTotalPrice() {
	double totalPrice = 0;
	for (int i = 0; i < numItemsOrdered; ++i) {
		totalPrice += shoppingCart[i].GetPrice();
	}
	return totalPrice;
}

/*
Gets the current value of loggedIn
*/
bool Customer::GetLogIn() {
	return this->loggedIn;
}

/*
Prints out the customer's name, shopping cart items, and total price for those items
*/
ostream& operator<<(ostream& out, Customer& myCustomer) {
	//Prints out myCustomer.name
	out << myCustomer.name << endl;
	//for loop to print out all of the contents in myCustomer.shoppingCart
	for (int i = 0; i < myCustomer.numItemsOrdered; ++i) {
		out << myCustomer.shoppingCart[i];
	}
	//prints the final total of all the items in the customer's shopping cart
	out << "The final price is: " << myCustomer.GetTotalPrice() << endl;
	return out;
}