#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	int counter = 0;
	double value;
	double difference;
	double sum = 0;
	double mean = 0;
	double stdDev = 0;
	string filename;

	//promt the user and read in the file name
	cout << "This program calculates the statistics on a file containing a series of numbers." << endl;
	cout << "Enter the file name: ";
	cin >> filename;

	//ADD LINES FOR TASK #4 HERE
	//open the file and put in a condition that tests that it is open (if not open, return 1 to indicate error)
	infile.open(filename);
	if (infile.fail()) {
		cout << "File failed to open.\n";
		return 1;
	}
	//read a value from the file as long as you are not at the end of the file
	//if you were able to read the value, add the value to the sum and increment the counter
	//when you exit the loop, calculate the mean by dividing the sum by the counter
	//close the file 
	while (!infile.eof()) {
		infile >> value;
		sum += value;
		counter++;
	}
	mean = sum / counter;
	infile.close();



	//ADD LINES FOR TASK #5 HERE
	//reinitialize sum and counter to 0;
	sum = 0;
	counter = 0;
	//open the file and put in a condition that tests that it is open (if not open, return 1 to indicate error)
	infile.open(filename);
	if (infile.fail()) {
		cout << "File failed to open.\n";
		return 1;
	}
	//read a number from the file as long as you are not at the end of the file
	//if you were able to read the value, subtract the mean from the value and store into difference
	//add the square of the difference to the sum and increment the counter
	//when you exit the loop, calculate the standard deviation by taking the square root of the quotient of the sum and the counter
	//close the file 
	while (!infile.eof()) {
		infile >> value;
		difference = value - mean;
		sum += pow(difference, 2.0);
		counter++;
	}
	stdDev = sqrt(sum / counter);
	infile.close();
	
	
	//ADD LINES FOR TASK #3 HERE
	//open the file "Results.txt" and put in a condition that tests that it is open (if not open, return 1 to indicate error)
	//format the output to have 3 decimal places
	//print the mean and the standard deviation to the file (both labeled)
	//close the output file
	outfile.open("results.txt");
	if (outfile.fail()) {
		cout << "File failed to open.\n";
		return 1;
	}
	outfile << fixed << setprecision(3) << "Standard Deviation = " << stdDev << endl;
	outfile << "Mean = " << mean << endl;

	return 0;
}