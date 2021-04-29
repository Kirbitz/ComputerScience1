#include "Customer.h"
#include <cassert>

using namespace std;

int main() {

	cout << "Start Testing!!!\n";
	Customer testCustomer;
	DigitalDownload testDownload("Code book", "Tyler", "book", 2019, 12.99);
	DigitalDownload testDownload2("Art Book", "Qiana", "book", 2018, 13.99);
	DigitalDownload testDownload3("Death Note", "Quinn", "audiobook", 2000, 1.99);
	testCustomer.SetName("Jim");
	assert(testCustomer.GetName() == "Jim");
	testCustomer.AddToShoppingCart(testDownload);
	cout << testCustomer;
	testCustomer.AddToShoppingCart(testDownload2);
	cout << testCustomer;
	testCustomer.AddToShoppingCart(testDownload3);
	cout << testCustomer;
	//testCustomer.Login();
	/*assert(testCustomer.GetLogIn() == true);
	testCustomer.Logout();
	assert(testCustomer.GetLogIn() == false);
	testCustomer.Login();
	assert(testCustomer.GetLogIn() == true);*/
	testCustomer.RemoveItemFromCart(testDownload3);
	cout << testCustomer;
	cout << "End Testing!!!\n";

	return 0;
}