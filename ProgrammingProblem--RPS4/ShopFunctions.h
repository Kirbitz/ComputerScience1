#ifndef ShopFunctions
#define ShopFunctions

#include <iostream>
#include <fstream>
#include <vector>
#include "Customer.h"

/*
CreateDownload funtions creates a vector of DigitalDownload objects that are readin from
digitaldownloadlist.txt file
*/
vector<DigitalDownload> CreateDownload();

/*
LoginCustomer function tests if myCustomer.GetLogin() is true
if true it logs out the customer
if false it prompts the customer to log in
*/
void LoginCustomer(Customer&);

/*
DownloadPrinter function takes in a vector and prints out the objects within that vector
data in: vector<DigitalDownload>
*/
void DownloadPrinter(vector<DigitalDownload>);

/*
Search function allows the user to search for specific titles, authors, or formats
Data in: downloads
*/
void Search(vector<DigitalDownload>);

/*
Adds a digital download to the customer's cart from the list of available downloads
Data in: myCustomer, downloads
*/
void AddBookToCart(Customer&, vector<DigitalDownload>);

/*
RemoveBookFromCart function prompts the user for the title of the download they want removed from their cart
Data in: myCustomer, downloads
*/
void RemoveBookFromCart(Customer& myCustomer, vector<DigitalDownload> downloads);

/*
PrintCustomerCart functions prints the DigitalDownloads currently in the customer's cart
Data in: myCustomer
*/
void PrintCustomerCart(Customer&);

/*
CustomerDoneShopping fuction prints out the customer's name, DigitalDownloads, and final price if the customer is loggedIn
Data in: myCustomer
*/
void CustomerDoneShopping(Customer&);

/*
PrintMenu function prints a menu for the customer based on whether or not they have logged in
*/
void PrintMenu(Customer&);

/*
MenuSelection function takes in the a number and selects the correct menu option accordingly
Data in: numAns, myCustomer, downloads
*/
void MenuSelection(int, Customer&, vector<DigitalDownload>);

#endif