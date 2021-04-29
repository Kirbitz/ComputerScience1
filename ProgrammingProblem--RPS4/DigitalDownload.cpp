#include "DigitalDownload.h"

/*
Constructor that creates a DigitalDownload object
Data out: DigitalDownload object
*/
DigitalDownload::DigitalDownload() {
	this->title = "";
	this->creator = "";
	this->format = "";
	this->pubYear = 0;
	this->price = 0;
}

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
operator<< function prints out the current DigitalDownload object in a two line format
data out: example print:
The audiobook Gone with the Wind by Margaret Mitchell
Published in 1936 costs: 10.00
*/
ostream& operator<<(ostream& out, DigitalDownload& myDownload) {
	out << "The " << myDownload.GetFormat() << " " << myDownload.GetTitle() << " by " << myDownload.GetCreator() << endl;
	out << "Published in " << myDownload.GetYear() << " costs: " << fixed << setprecision(2) << myDownload.GetPrice() << endl;
	return out;
}

/*
SearchName function prints out the current DigitalDownload object in a two line format
also prompts the user for a specific author they want to see
data in: creator
example print:
The audiobook Gone with the Wind by Margaret Mitchell
Published in 1936 costs: 10.00
*/
void DigitalDownload::SearchName(string creator) {
	//Initializes variables tester to true, myCreatorUpper to "", and creatorUpper to ""
	bool tester = true;
	string myCreatorUpper = "";
	string creatorUpper = "";

	//for loop to make createrUpper an all caps version of creator
	for (int i = 0; i < creator.size(); i++) {
		creatorUpper += toupper(creator.at(i));
	}
	
	//for loop to make myCreatorUpper an all caps version of this downloads creator
	for (int i = 0; i < this->creator.size(); ++i) {
		myCreatorUpper += toupper(this->creator.at(i));
	}

	//Tests to see if the string creatorUpper exists within myCreatorUpper and prints the download if true
	if (myCreatorUpper.find(creatorUpper) != std::string::npos) {
		cout << "The " << this->GetFormat() << " " << this->GetTitle() << " by " << this->GetCreator() << endl;
		cout << "Published in " << this->GetYear() << " costs: " << fixed << setprecision(2) << this->GetPrice() << endl;
	}
}

/*
SearchTitle function prints out the current DigitalDownload object in a two line format
also prompts the user for a specific title they want to see
data in: title
example print:
The audiobook Gone with the Wind by Margaret Mitchell
Published in 1936 costs: 10.00
*/
void DigitalDownload::SearchTitle(string title) {
	//Initializes variables tester to true, myTitleUpper to "", and titleUpper to ""
	bool tester = true;
	string titleUpper = "";
	string myTitleUpper = "";

	//for loop to make titleUpper an all caps version of title
	for (int i = 0; i < title.size(); ++i) {
		titleUpper += toupper(title.at(i));
	}

	//for loop to make myTitleUpper an all caps version of this downloads title
	for (int i = 0; i < this->title.size(); ++i) {
		myTitleUpper += toupper(this->title.at(i));
	}

	//Tests to see if the string titleUpper exists within mytitleUpper and prints the download if true
	if (myTitleUpper.find(titleUpper) != std::string::npos) {
		cout << "The " << this->GetFormat() << " " << this->GetTitle() << " by " << this->GetCreator() << endl;
		cout << "Published in " << this->GetYear() << " costs: " << fixed << setprecision(2) << this->GetPrice() << endl;
	}
}

/*
SearchFormat function prints out the current DigitalDownload object in a two line format
also prompts the user for a specific format they want to see
data in: format
example print:
The audiobook Gone with the Wind by Margaret Mitchell
Published in 1936 costs: 10.00
*/
void DigitalDownload::SearchFormat(string format) {
	//Initializes variables tester to true, myFormatUpper to "", and formatUpper to ""
	bool tester = true;
	string myFormatUpper = "";
	string formatUpper = "";

	//for loop to make formatUpper an all caps version of format
	for (int i = 0; i < format.size(); ++i) {
		formatUpper += toupper(format.at(i));
	}

	//for loop to make myFormatUpper an all caps version of this downloads format
	for (int i = 0; i < this->format.size(); ++i) {
		myFormatUpper += toupper(this->format.at(i));
	}

	//Tests to see if the string formatUpper exists within myFormatUpper and prints the download if true
	if (myFormatUpper.find(formatUpper) != std::string::npos) {
		cout << "The " << this->GetFormat() << " " << this->GetTitle() << " by " << this->GetCreator() << endl;
		cout << "Published in " << this->GetYear() << " costs: " << fixed << setprecision(2) << this->GetPrice() << endl;
	}
}

/*
Overloads the == operator in order to test if two DigitalDownload objects are equal to eachother
Data in: myDownload
Data out: true or false
*/
bool DigitalDownload::operator==(DigitalDownload myDownload) {
	if (myDownload.creator == this->creator && myDownload.title == this->title && myDownload.format == this->format && myDownload.pubYear == this->pubYear) {
		if (abs(myDownload.price - this->price) < 0.01)
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}