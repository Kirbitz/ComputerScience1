#include "Time.h"
#include <iostream>

using namespace std;

int main() {
	Time tim1("00:00");
	Time tim2("12:00");
	Time tim3("04:05");
	Time tim4("10:15");
	Time tim5("23:59");
	Time tim6("00:35");
	cout << tim1 << endl << tim2 << endl << tim3 << endl << tim4 << endl << tim5 << endl << tim6 << endl;
	Time tim7("7:56");
	Time tim8("08:60");
	Time tim9("24:00");
	Time tim10("3e:33");
	Time tim11("15:78");
	Time tim12("1:111");
	return 0;
}