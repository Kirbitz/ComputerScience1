#ifndef formulas
#define formulas

//Function prints a menu for the user to select one of the six options they want to calculate
void PrintMenu();

//Calculates the area of a circle based on the radius recieved
//returns area of the circle
double CircleArea(double radius);

//Calculates the area of a rectangle based on the length and width recieved
//returns area of the rectangle
double RectangleArea(double length, double width);

//Calculates the area of a triangle based on the base and height recieved
//returns area of the triangle
double TriangleArea(double base, double height);

//Calculates the circumference of a circle based on the radius recieved
//returns circumference of the circle
double CircleCircumference(double radius);

//Calculates the perimeter of a rectangle based on the length and width recieved
//returns perimeter of the rectangle
double RectanglePerimeter(double length, double width);

//Calculates the perimeter of a triangle based on the base and height recieved
//returns perimeter of the triangle
double TrianglePerimeter(double side1, double side2, double side3);

#endif
