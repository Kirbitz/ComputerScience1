#include <iostream>
#include <fstream>
#include <vector>
#include "DigitalDownload.h"

using namespace std;

/*
Tyler Marefke
Programming Project RPS--3
11/26/19
*/

/*
CreateDownload funtions creates a vector of DigitalDownload objects that are readin from 
digitaldownloadlist.txt file
*/
vector<DigitalDownload> CreateDownload();

/*
DownloadPrinter function takes in a vector and prints out the objects within that vector
data in: vector<DigitalDownload>
*/
void DownloadPrinter(vector<DigitalDownload>);

int main() {

	vector<DigitalDownload> downloads = CreateDownload();
	DownloadPrinter(downloads);

	return 0;
}

vector<DigitalDownload> CreateDownload() {
	
	vector <DigitalDownload> downloader;
	ifstream infile;
	string title;
	string creator;
	string format;
	char answer;
	int pubYear;
	double price;

	infile.open("digitaldownloadlist.txt");
	if (!infile.is_open()) {
		cout << "File could not be opened!" << endl;
		return downloader;
	}

	while (!infile.eof()) {
		getline(infile, title);
		getline(infile, creator);
		getline(infile, format);
		infile >> pubYear;
		infile >> price;
		infile.ignore();
		infile.ignore(1000, '\n');

		downloader.push_back(DigitalDownload(title, creator, format, pubYear, price));

	}
	infile.close();
	return downloader;

}

void DownloadPrinter(vector<DigitalDownload> downloads) {
	char answer;
	string creator;

	cout << "Would you like to enter an artist?(Y/N): \n";
	cin >> answer;
	cin.ignore();
	if (toupper(answer) == 'Y') {
		cout << "Please enter an artist.\n";
		getline(cin, creator);
		cout << creator << " has made: \n";
		for (int i = 0; i < downloads.size(); i++) {
			downloads.at(i).Display(creator);
		}
	}
	else {
		for (int i = 0; i < downloads.size(); i++) {
			downloads.at(i).Display();
		}
	}
}