#include "DigitalDownload.h"

/*
Constructor that creates a DigitalDownload object from the recieved variables
Data in: creator, format, pubYear, price
Data out: DigitalDownload object
*/
DigitalDownload::DigitalDownload(string title, string creator, string format, int pubYear, double price) {
	this->title = title;
	this->creator = creator;
	this->format = format;
	this->pubYear = pubYear;
	this->price = price;
}

/*
SetTitle function allows for the title of the DigitalDownload object to be changed
data in: title
*/
void DigitalDownload::SetTitle(string title) {
	this->title = title;
}

/*
SetCreator function allows for the creator of the DigitalDownload object to be changed
data in: creator
*/
void DigitalDownload::SetCreator(string creator) {
	this->creator = creator;
}

/*
SetFormat function allows for the format of the DigitalDownload object to be changed
data in: format
*/
void DigitalDownload::SetFormat(string format) {
	this->format = format;
}

/*
SetYear function allows for the pubYear of the DigitalDownload object to be changed
data in: pubYear
*/
void DigitalDownload::SetYear(int pubYear) {
	this->pubYear = pubYear;
}

/*
SetPrice function allows for the title of the DigitalDownload object to be changed
data in: title
*/
void DigitalDownload::SetPrice(double price) {
	this->price = price;
}

/*
GetTitle function provides the current title of the DigitalDownload object
data out: title
*/
string DigitalDownload::GetTitle() const{
	return this->title;
}

/*
GetCreator function provides the current creator of the DigitalDownload object
data out: creator
*/
string DigitalDownload::GetCreator() const {
	return this->creator;
}

/*
GetFormat function provides the current format of the DigitalDownload object
data out: format
*/
string DigitalDownload::GetFormat() const {
	return this->format;
}

/*
GetYear function provides the current pubYear of the DigitalDownload object
data out: pubYear
*/
int DigitalDownload::GetYear() const {
	return this->pubYear;
}

/*
GetPrice function provides the current price of the DigitalDownload object
data out: price
*/
double DigitalDownload::GetPrice() const {
	return this->price;
}

/*
Display function prints out the current DigitalDownload object in a two line format
data out: example print:
The audiobook Gone with the Wind by Margaret Mitchell
Published in 1936 costs: 10.00
*/
void DigitalDownload::Display() {
	if (!(this->GetPrice() >= 25)) {
		cout << "The " << this->GetFormat() << " " << this->GetTitle() << " by " << this->GetCreator() << endl;
		cout << "Published in " << this->GetYear() << " costs: " << fixed << setprecision(2) << this->GetPrice() << endl;
	}
}

/*
Overloaded Display function prints out the current DigitalDownload object in a two line format
also prompts the user for a specific author they want to see
data in: creator
example print:
The audiobook Gone with the Wind by Margaret Mitchell
Published in 1936 costs: 10.00
*/
void DigitalDownload::Display(string creator) {
	bool tester = true;
	for (int i = 0; i < creator.size(); i++) {
		if (!isspace(this->creator.at(i))) {
			if (toupper(this->creator.at(i)) != toupper(creator.at(i))) {
				tester = false;
				break;
			}
		}
	}

	if (!(this->GetPrice() >= 25) && tester) {
		cout << "The " << this->GetFormat() << " " << this->GetTitle() << " by " << this->GetCreator() << endl;
		cout << "Published in " << this->GetYear() << " costs: " << fixed << setprecision(2) << this->GetPrice() << endl;
	}
}