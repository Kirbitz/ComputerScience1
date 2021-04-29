#include <iostream>
#include <cassert>
#include "Television.h"

using namespace std;

int main()
{
	Television bigScreen ("Visio", 70);
	Television portable("Sharp", 32);
	Television flatScreen;

	cout << "Testing bigScreen" << endl;
	assert(bigScreen.GetManufacturer() == "Visio");
	assert(bigScreen.GetScreenSize() == 70);
	assert(bigScreen.GetChannel() == 2);
	assert(bigScreen.GetVolume() == 20);
	bigScreen.IncreaseVolume();  //should only work if power is on
	assert(bigScreen.GetVolume() == 20);
	bigScreen.DecreaseVolume();  //should only work if power is on
	assert(bigScreen.GetVolume() == 20);
	bigScreen.SetChannel(5); //should only work if power is on
	assert(bigScreen.GetChannel() == 2);
	bigScreen.Power();  //turn power on
	bigScreen.DecreaseVolume();
	assert(bigScreen.GetVolume() == 19);
	bigScreen.IncreaseVolume();
	assert(bigScreen.GetVolume() == 20);
	cout << "Testing bigScreen complete" << endl;

	cout << "Testing portable" << endl;
	assert(portable.GetManufacturer() == "Sharp");
	assert(portable.GetScreenSize() == 32);
	cout << "Testing portable complete" << endl;
	
	cout << "Testing flatScreen" << endl;
	assert(flatScreen.GetManufacturer() == "LG");
	assert(flatScreen.GetScreenSize() == 54);
	cout << "Testing flatScren complete" << endl;
	
	
	cout << "All testing complete" << endl;
}