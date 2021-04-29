#include <iostream>
#include "formulas.h"

using namespace std;

int main()
{
	int choice;			//the user's choice
	double value = 0;	//the value returned from the method
	char letter;		//the Y or N from the user's decision to exit
	double radius;		//the radius of the circle
	double length;		//the length of the rectangle
	double width;		//the width of the rectangle
	double base;		//the base of the triangle
	double height;		//the height of the triangle
	double side1;		//the first side of the triangle
	double side2;		//the second side of the triangle
	double side3;		//the third side of the triangle

	//do loop was chosen to allow the menu to be displayed first
	do
	{
		//call the printMenu function
		PrintMenu();

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the radius of the circle:  ";
			cin >> radius;

			//call the circleArea function and store the result in value
			value = CircleArea(radius);

			cout << "The area of the circle is " << value << endl;
			break;

		case 2:
			cout << "Enter the length of the rectangle:  ";
			cin >> length;
			cout << "Enter the width of the rectangle:  ";
			cin >> width;

			//call the rectangleArea function and store the result in value
			value = RectangleArea(length, width);

			cout << "The area of the rectangle is " << value << endl;
			break;

		case 3:
			cout << "Enter the height of the triangle:  ";
			cin >> height;
			cout << "Enter the base of the triangle:  ";
			cin >> base;

			//call the triangleArea function and store the result in value
			value = TriangleArea(base, height);

			cout << "The area of the triangle is " << value << endl;
			break; 
		
		case 4:
			cout << "Enter the radius of the circle:  ";
			cin >> radius;

			//call the circleCircumference function and store the result in value
			value = CircleCircumference(radius);

			cout << "The circumference of the circle is " << value << endl;
			break;

		case 5:
			cout << "Enter the length of the rectangle:  ";
			cin >> length;
			cout << "Enter the width of the rectangle:  ";
			cin >> width;
			//call the rectanglePerimeter function and store the result in value
			value = RectanglePerimeter(length, width);

			cout << "The perimeter of the rectangle is " << value << endl;
			break;

		case 6:
			cout << "Enter the length of side 1 of the triangle:  ";
			cin >> side1;
			cout << "Enter the length of side 2 of the triangle:  ";
			cin >> side2;
			cout << "Enter the length of side 3 of the triangle:  ";
			cin >> side3;

			//call the trianglePerimeter function and store the result in value
			value = TrianglePerimeter(side1, side2, side3);

			cout << "The perimeter of the triangle is " << value << endl;
			break;

		default:
			cout << "You did not enter a valid choice." << endl;
		}

		cout << "Do you want to exit the program (Y/N)? ";
		cin >> letter;

	} while (letter != 'Y' && letter != 'y');
}