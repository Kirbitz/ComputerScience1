#include <iostream>
#include <fstream>
#include <string>
#include "Song.h"

using namespace std;

int main()
{
	
	//declare pointer to the first playlist
	Song* playList1Ptr = nullptr;
	//declare pointer to the second playlist
	Song* playList2Ptr = nullptr;
	
	ifstream infile;
	int numTracks;
	string title;
	string artist;
	int minutes;
	int seconds;
	string newline;
	int trackNum = 0;

	infile.open("cdTracks.txt");
	if (!infile.is_open())
	{
		cout << "Could not open file." << endl;
		return 1;
	}
	
	infile >> numTracks;

	//create a dynamic array of Songs to hold the first playlist of size numTracks
	playList1Ptr = new Song[numTracks];
	
	
	while (!infile.eof())
	{
		infile.ignore();  //consumes the new line character after the number 
		getline(infile, title);
		getline(infile, artist);
		infile >> minutes >> seconds;
		
		if (!infile.fail())
		{
			//construct a Song from the information and put it in the playlist
			playList1Ptr[trackNum] = Song(title, artist, minutes, seconds);
			trackNum++;
		}	
	}

	infile.close();
	cout << "Initial playlist" << endl << endl;

	//write a loop to display the songs in the playlist
	for (int index = 0; index < numTracks; index++) {
		(playList1Ptr + index)->Display();
	}
	
	


	//create a dynamic array of Songs for the second playlist that is one longer than the first playlist
	playList2Ptr = new Song[numTracks + 1];

	//copy the songs from the first playlist to the second playlist
	for (int index = 0; index < numTracks; index++) {
		playList2Ptr[index] = playList1Ptr[index];
	}
	
	cout << endl << "Add a song to the playlist" << endl;
	cout << "Enter Title: ";
	getline(cin, title);
	cout << "Enter Artist: ";
	getline(cin, artist);
	cout << "Enter the length of the song as the number of minutes followed by a space and the number of seconds: ";
	cin >> minutes >> seconds;
	cout << endl << "The new playlist" << endl << endl;
	cin.ignore();

	//construct a song from the information and put it on the second playlist
	playList2Ptr[numTracks] = Song(title, artist, minutes, seconds);
	//write a loop to display the second playlist
	for (int index = 0; index < numTracks + 1; index++) {
		(playList2Ptr + index)->Display();
	}

	//allow the user to search for a title
	string search;
	cout << "Enter a keyword to search the playlist for: ";
	getline(cin, search);
	
	for (int index = 0; index < numTracks + 1; index++) {
		if (playList2Ptr[index].GetTitle().find(search) != std::string::npos) {
			(playList2Ptr + index)->Display();
		}
	}
	
	
	//reclaim the dynamic memory
	delete[] playList1Ptr;
	delete[] playList2Ptr;
	//set the pointers to nullptr
	playList1Ptr = nullptr;
	playList2Ptr = nullptr;

	return 0;
}