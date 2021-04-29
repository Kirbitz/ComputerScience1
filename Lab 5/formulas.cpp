#include <iostream>
const double pi = 3.1415926535897932384626;

using namespace std;
//Function prints a menu for the user to select one of the six options they want to calculate
void PrintMenu() {
	cout << "This is a geometry calculator.\n";
	cout << "Choose what you would like to calculate.\n";
	cout << "1. Find the area of a circle\n";
	cout << "2. Find the area of a rectangle\n";
	cout << "3. Find the area of a triangle\n";
	cout << "4. Find the circumference of a circle\n";
	cout << "5. Find the perimeter of a rectangle\n";
	cout << "6. Find the perimeter of a triangle\n";
	cout << "Enter the number of your choice: \n";
}

//Calculates the area of a circle based on the radius recieved
//returns area of the circle
double CircleArea(double radius) {
	return pi * radius * radius;
}

//Calculates the area of a rectangle based on the length and width recieved
//returns area of the rectangle
double RectangleArea(double length, double width) {
	return length * width;
}

//Calculates the area of a triangle based on the base and height recieved
//returns area of the triangle
double TriangleArea(double base, double height) {
	return (1.0 / 2.0) * base * height;
}

//Calculates the circumference of a circle based on the radius recieved
//returns circumference of the circle
double CircleCircumference(double radius) {
	return 2 * pi * radius;
}

//Calculates the perimeter of a rectangle based on the length and width recieved
//returns perimeter of the rectangle
double RectanglePerimeter(double length, double width) {
	return (2 * length) + (2 * width);
}

//Calculates the perimeter of a triangle based on the base and height recieved
//returns perimeter of the triangle
double TrianglePerimeter(double side1, double side2, double side3) {
	return side1 + side2 + side3;
}