#pragma once
#include <string>
using namespace std;
class Song
{
private:
	string artist;
	string title;
	int minutes;
	int seconds;

public:
	Song(string title = "unknown", string artist = "unknown", int minutes = 0, int seconds = 0);
	string GetArtist() const;
	string GetTitle() const;
	int GetMinutes() const;
	int GetSeconds() const;
	void Display();

};

