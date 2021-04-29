#include <iostream>
using namespace std;


int main()
{
	string artists[] = { "Bach", "Tchaikovsky", "Brahms", "Beethoven", "Strauss" };
	string songs[] = { "Ode to Joy", "The Sleeping Beauty", "Lullaby", "Symphony No. 5", "The Blue Danube Waltz" };

	//Task #1   
	//Write a for loop to print the contents of the artists array
	//Write a for loop to print out the contents of the artists array in reverse order.
	//Write a for loop using the parallel arrays that give you the output requested in the instructions
	for (int i = 0; i < 5; i++) {
		cout << artists[i] << endl;
	}
	for (int i = 4; i >= 0; i--) {
		cout << songs[i] << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". " << songs[i] << " by " << artists[i] << endl;
	}
	
	return 0;
}

