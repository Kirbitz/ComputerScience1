#include "Television.h"

//Creates a new Television Object
//Sets manufaturer to the default of LG and sets screenSize to the default of 54
Television::Television() {
	manufacturer = "LG";
	screenSize = 54;
}

//Creates a new Television Object
//Input: myBrand string and int myScreenSize
//Sets the manufacturer as myBrand and screenSize as myScreenSize
Television::Television(string myBrand, int myScreenSize) {
	manufacturer = myBrand;
	screenSize = myScreenSize;
}

//Sets the channel in the television object
//Input: int myChannel
//Output: sets channelStation variable to myChannel
void Television::SetChannel(int myChannel) {
	if(powerOn)
		channelStation = myChannel;
}

//Changes powerOn from true to false and false to true
void Television::Power() {
	powerOn = !powerOn;
}

//Increments the volume variable by 1
void Television::IncreaseVolume() {
	if(powerOn)
		volume++;
}

//deincrements the volume variable by 1
void Television::DecreaseVolume() {
	if(powerOn)
		volume--;
}

//returns the current channelStation of the object
const int Television::GetChannel() {
	return channelStation;
}

//returns the current volume of the object
const int Television::GetVolume() {
	return volume;
}

//returns the screenSize of the object
const int Television::GetScreenSize() {
	return screenSize;
}

//returns the manufacturer name of the object
string Television::GetManufacturer() {
	return manufacturer;
}