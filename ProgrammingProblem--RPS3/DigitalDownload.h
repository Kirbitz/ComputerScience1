#ifndef DigitalDownload_H
#define DigitalDownload_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

//This class is Digital Downloads
class DigitalDownload
{
	private:
		string title;
		string creator;
		string format;
		int pubYear;
		double price;
	public:
		DigitalDownload(string, string, string, int, double);
		void SetTitle(string);
		void SetCreator(string);
		void SetFormat(string);
		void SetYear(int);
		void SetPrice(double);
		string GetTitle() const;
		string GetCreator() const;
		string GetFormat() const;
		int GetYear() const;
		double GetPrice() const;
		void Display();
		void Display(string);

};

#endif