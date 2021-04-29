#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

class Time
{
	friend ostream& operator<< (ostream& out, Time time);
private:
	int hours;
	int minutes;
	bool isAfternoon;
public:
	Time(string time);
	Time();

};
#endif
