#include "Time.h"

#include <iostream>
using namespace std;

Time::Time(string time)
{
	hours = 0;
	minutes = 0;
	isAfternoon = false;

	//check to make sure there are 5 characters
	if (time.size() != 5)
	{
		cout << "You must enter a valid military time in the format 00:00" << endl;
	}
	else
	{
		//check to make sure the colon is in the correct spot
		if (time.find(':') != 2)
		{
			cout << "You must enter a valid military time in the format 00:00" << endl;
		}
		//check to make sure all other characters are digits
		else if (!isdigit(time.at(0)))
		{
			cout << "You must enter a valid military time in the format 00:00" << endl;
		}
		else if (!isdigit(time.at(1)))
		{
			cout << "You must enter a valid military time in the format 00:00" << endl;
		}
		else if (!isdigit(time.at(3)))
		{
			cout << "You must enter a valid military time in the format 00:00" << endl;
		}
		else if (!isdigit(time.at(4)))
		{
			cout << "You must enter a valid military time in the format 00:00" << endl;
		}
		else
		{
			/*separate the string into hours and minutes converting them to integers
			and storing them into the instance variables*/
			hours = stoi(time.substr(0, 2));
			minutes = stoi(time.substr(3, 2));

			//validate that hours and minutes are valid values
			if (hours > 23)
			{
				cout << "You must enter a valid military time in the format 00:00" << endl;
			}
			else if (minutes > 59)
			{
				cout << "You must enter a valid military time in the format 00:00" << endl;
			}
			//convert military time to conventional time for afternoon times, morning times don't need converting
			else if (hours > 12)
			{
				hours = hours - 12;
				isAfternoon = true;
			}
			//account for noon
			else if (hours == 12)
			{
				isAfternoon = true;
			}
			//account for midnight
			else if (hours == 0)
			{
				hours = 12;
			}


		}
	}
}

Time::Time()
{
	hours = 12;
	minutes = 0;
	isAfternoon = true;
}

ostream& operator<< (ostream& out, Time time)
{
	//write the time in conventional form including am or pm
	string ampm;
	if (time.isAfternoon)
		ampm = "pm";
	else
		ampm = "am";
	out << time.hours << ":";

	if (time.minutes < 10)
		out << "0" << time.minutes;
	else
		out << time.minutes;
	out << ampm;
	return out;
}