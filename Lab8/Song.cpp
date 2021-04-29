#include <string>
#include <iostream>
#include "Song.h"
using namespace std;

Song::Song(string title, string artist, int minutes, int seconds)
{
	this->title = title;
	this->artist = artist;
	this->minutes = minutes;
	this->seconds = seconds;
}
string Song::GetArtist() const
{
	return artist;
}

string Song::GetTitle() const
{
	return title;
}

int Song::GetMinutes() const
{
	return minutes;
}

int Song::GetSeconds() const
{
	return seconds;
}

void Song::Display()
{
	cout << this->GetTitle() << " by " << this->GetArtist() << ", length: " << this->GetMinutes() << ":";
	if (this->GetSeconds() < 10)
		cout << "0" << this->GetSeconds() << endl;
	else
		cout << this->GetSeconds() << endl;
}
