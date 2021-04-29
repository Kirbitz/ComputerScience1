#include <iostream>
#include <assert.h>
#include "DigitalDownload.h"

using namespace std;

int main() {

	DigitalDownload tester("Gone", "Tim", "video", 2019, 9.99);
	cout << "Started Testing" << endl;
	assert(tester.GetTitle() == "Gone");
	assert(tester.GetCreator() == "Tim");
	assert(tester.GetFormat() == "video");
	assert(tester.GetYear() == 2019);
	assert(abs(tester.GetPrice() - 9.99) <= 0.01);
	tester.Display();
	tester.SetCreator("John");
	tester.SetTitle("Here");
	tester.SetFormat("audiobook");
	tester.SetYear(2000);
	tester.SetPrice(25.99);
	assert(tester.GetTitle() == "Here");
	assert(tester.GetCreator() == "John");
	assert(tester.GetFormat() == "audiobook");
	assert(tester.GetYear() == 2000);
	assert(abs(tester.GetPrice() - 25.99) <= 0.01);
	tester.Display();
	tester.Display("tim");
	tester.Display("john");
	cout << "Testing finish" << endl;

	return 0;
}