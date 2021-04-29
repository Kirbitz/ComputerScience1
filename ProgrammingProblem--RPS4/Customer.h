#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "DigitalDownload.h"
class Customer
{
	friend ostream& operator<<(ostream& out, Customer& myCustomer);
private:
	string name;
	DigitalDownload* shoppingCart;
	int numItemsOrdered;
	bool loggedIn;
public:
	Customer();
	~Customer();
	void Login();
	void Logout();
	void AddToShoppingCart(DigitalDownload item);
	void RemoveItemFromCart(DigitalDownload item);
	void PrintCart();
	void SetName(string);
	string GetName();
	double GetTotalPrice();
	bool GetLogIn();
};

#endif