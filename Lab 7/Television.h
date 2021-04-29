#ifndef Television_H
#define Television_H
#include <string>

using namespace std;

class Television
{
private:
	string manufacturer;
	int screenSize;
	bool powerOn = false;
	int channelStation = 2;
	int volume = 20;
public:
	Television();
	Television(string, int);
	void SetChannel(int);
	void Power();
	void IncreaseVolume();
	void DecreaseVolume();
	const int GetChannel();
	const int GetVolume();
	const int GetScreenSize();
	string GetManufacturer();
};

#endif