#include <iostream>
#include <fstream>
#include <vector>
#include "Customer.h"

using namespace std;

/*
Tyler Marefke
Programming Project RPS--4
12/5/19
*/

/*
CreateDownload funtions creates a vector of DigitalDownload objects that are readin from
digitaldownloadlist.txt file
Data out: downloader
*/
vector<DigitalDownload> CreateDownload() {

	vector <DigitalDownload> downloader;
	ifstream infile;
	string title;
	string creator;
	string format;
	char answer;
	int pubYear;
	double price;

	//Opens the file called digitaldownloadlist.txt and tests if the file was opened
	infile.open("digitaldownloadlist.txt");
	if (!infile.is_open()) {
		cout << "File could not be opened!" << endl;
		return downloader;
	}

	//tests if the eof has been reached
	while (!infile.eof()) {
		getline(infile, title);
		getline(infile, creator);
		getline(infile, format);
		infile >> pubYear;
		infile >> price;
		infile.ignore();
		infile.ignore(1000, '\n');

		//adds a digital download created from the file to the vector downloader
		downloader.push_back(DigitalDownload(title, creator, format, pubYear, price));

	}
	//closes file and returns downloader
	infile.close();
	return downloader;

}

/*
LoginCustomer function tests if myCustomer.GetLogin() is true
if true it logs out the customer
if false it prompts the customer to log in
*/
void LoginCustomer(Customer& myCustomer) {
	if (myCustomer.GetLogIn()) {
		myCustomer.Logout();
	}
	else {
		myCustomer.Login();
	}
}

/*
DownloadPrinter function takes in a vector and prints out the objects within that vector
data in: vector<DigitalDownload>
*/
void DownloadPrinter(vector<DigitalDownload> downloads) {
	for (int i = 0; i < downloads.size(); i++) {
			cout << downloads.at(i);
	}
}

/*
Search function allows the user to search for specific titles, authors, or formats
Data in: downloads
*/
void Search(vector<DigitalDownload> downloads){
	//Initializes variables numAns, answer, and tester
	int numAns = 3;
	string numUserInput;
	string answer;
	bool tester = true;
	
	//do while loop that loops until the user enters a valid search type
	do {
		
		//prompts the user for the type of search they would like to do
		do {
			cout << "How do you want to search?\n1. Name\n2. Title\n3. Format\n\nPlease enter a number for selection: \n";
			getline(cin, numUserInput);
			if (isdigit(numUserInput.at(0))) {
				numUserInput = numUserInput.at(0);
				numAns = stoi(numUserInput);
			}
		} while (!isdigit(numUserInput.at(0)));

		//switch case which takes the user input and runs the correct search format
		switch (numAns) {
			case 1:
				//prompts the user for a creators name and searchs for that creator accordingly
				cout << "Please enter the name of a creator.\n";
				getline(cin, answer);
				for (int i = 0; i < downloads.size(); i++) {
					downloads.at(i).SearchName(answer);
				}
				tester = false;
				break;
			case 2:
				//prompts the user for a title name and searchs for that title accordingly
				cout << "Please enter a title.\n";
				getline(cin, answer);
				for (int i = 0; i < downloads.size(); i++) {
					downloads.at(i).SearchTitle(answer);
				}
				tester = false;
				break;
			case 3:
				//prompts the user for a format type and searchs for the format accordingly
				cout << "Please enter a format type.\n";
				getline(cin, answer);
				for (int i = 0; i < downloads.size(); i++) {
					downloads.at(i).SearchFormat(answer);
				}
				tester = false;
				break;
			default:
				cout << "Invalid Input!!!\n";
		}

	} while (tester);
}

/*
Adds a digital download to the customer's cart from the list of available downloads
Data in: myCustomer, downloads
*/
void AddBookToCart(Customer& myCustomer, vector<DigitalDownload> downloads) {
	//Initializes variables titleAns, upperTitleAns, upperTitle, and foundbook to false
	string titleAns;
	string upperTitleAns = "";
	string upperTitle;
	bool foundBook = false;
	cout << "Please enter the exact title of the download you would like to add to your cart.\n";
	getline(cin, titleAns);

	//for loop that sets upperTitleAns to an allcaps version of titleAns
	for (int i = 0; i < titleAns.size(); ++i)
		upperTitleAns += toupper(titleAns.at(i));

	//for loop that runs through all of the variables in downloads
	for (int i = 0; i < downloads.size(); i++) {
		//reinitializes upperTitle to ""
		upperTitle = "";
		//for loop that runs through all of the letters for the title of the current DigitalDownload
		for (int j = 0; j < downloads.at(i).GetTitle().size(); ++j) {
			//Sets upperTitle to an all cap version of the current title in downloads
			upperTitle += toupper(downloads.at(i).GetTitle().at(j));
		}
		//if upperTitle and upperTitleAns are true then the current download is added to the Customer's cart
		if (upperTitle == upperTitleAns) {
			myCustomer.AddToShoppingCart(downloads.at(i));
			foundBook = true;
		}
	}

	//Tests foundbook for true of false
	if (foundBook) {
		cout << "Your cart has been updated!\n";
	}
	else {
		cout << "The title you entered does not match any in the list!\n";
	}

}

/*
RemoveBookFromCart function prompts the user for the title of the download they want removed from their cart
Data in: myCustomer, downloads
*/
void RemoveBookFromCart(Customer& myCustomer, vector<DigitalDownload> downloads) {
	//Initializes variables titleAns, upperTitleAns, upperTitle, and foundbook to false
	string titleAns;
	string upperTitleAns = "";
	string upperTitle;
	bool foundBook = false;
	cout << "Please enter the exact title of the download you would like to remove to your cart.\n";
	getline(cin, titleAns);

	//for loop that sets upperTitleAns to an allcaps version of titleAns
	for (int i = 0; i < titleAns.size(); ++i)
		upperTitleAns += toupper(titleAns.at(i));

	//for loop that runs through all of the variables in downloads
	for (int i = 0; i < downloads.size(); i++) {
		//reinitializes upperTitle to ""
		upperTitle = "";
		//for loop that runs through all of the letters for the title of the current DigitalDownload
		for (int j = 0; j < downloads.at(i).GetTitle().size(); ++j) {
			//Sets upperTitle to an all cap version of the current title in downloads
			upperTitle += toupper(downloads.at(i).GetTitle().at(j));
		}
		//if upperTitle and upperTitleAns are true then the current download is added to the Customer's cart
		if (upperTitle == upperTitleAns) {
			myCustomer.RemoveItemFromCart(downloads.at(i));
		}
	}
}

/*
PrintCustomerCart functions prints the DigitalDownloads currently in the customer's cart
Data in: myCustomer
*/
void PrintCustomerCart(Customer& myCustomer) {
	myCustomer.PrintCart();
}

/*
CustomerDoneShopping fuction prints out the customer's name, DigitalDownloads, and final price if the customer is loggedIn
Data in: myCustomer
*/
void CustomerDoneShopping(Customer& myCustomer) {
	//do while loop to test if the customer has logged in
	do {
		//Tests myCustomer.GetLogIn() for true or false
		if (myCustomer.GetLogIn()) {
			//Prints out myCustomer variable
			cout << myCustomer << endl;
			break;
		}
		else {
			//Prompts the user that they are not currently logged in and runs the LoginCustomer function
			cout << "You are not currently logged in please login!\n";
			LoginCustomer(myCustomer);
		}
	} while (myCustomer.GetLogIn());
}

/*
PrintMenu function prints a menu for the customer based on whether or not they have logged in
*/
void PrintMenu(Customer& myCustomer){
	//Tests myCustomer.GetLogIn() for validity
	if (!myCustomer.GetLogIn()) {
		cout << "1. Login\n2. List all available items purchase" << endl;
		cout << "3. Search\n4. Add book to shopping cart" << endl;
		cout << "5. Remove Item from shopping cart\n";
		cout << "6. Display Shopping Cart\n7. Checkout\n8. Exit without purchase\n\n";
		cout << "Please enter the number for menu selection: \n";
	}
	else {
		cout << "1. Log out\n2. List all available items purchase" << endl;
		cout << "3. Search\n4. Add book to shopping cart" << endl;
		cout << "5. Remove Item from shopping cart\n";
		cout << "6. Display Shopping Cart\n7. Checkout\n8. Exit without purchase\n\n";
		cout << "Please enter the number for menu selection: \n";
	}
}

/*
MenuSelection function takes in the a number and selects the correct menu option accordingly
Data in: numAns, myCustomer, downloads
*/
void MenuSelection(int numAns, Customer& myCustomer, vector<DigitalDownload> downloads) {
	
	switch (numAns) {
		case 1:
			LoginCustomer(myCustomer);
			break;
		case 2:
			DownloadPrinter(downloads);
			break;
		case 3:
			Search(downloads);
			break;
		case 4:
			AddBookToCart(myCustomer, downloads);
			break;
		case 5:
			RemoveBookFromCart(myCustomer, downloads);
		case 6:
			PrintCustomerCart(myCustomer);
			break;
		case 7:
			CustomerDoneShopping(myCustomer);
			break;
		default:
			cout << "Invalid Input!\n";
	}
}