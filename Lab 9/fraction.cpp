//************************************************************ Fraction.cpp
// Purpose:
//   This file contains the class definitions for a class that does simple
//   fraction manipulation.
//*************************************************************************
#include <iostream>
using namespace std;
#include "Fraction.h"

// A Fraction constructor which allows the numerator and denominator
// to be specified.
Fraction::Fraction(int n, int d)
{
	numerator = n;
	if (d != 0)
	{
		denominator = d;
	}
	else
	{
		denominator = 1;
	}
}

// Get a fraction from standard input, in the form "numerator/denominator."
istream& operator>>(istream& in, Fraction& frac)
{
	char divSign;			// used to consume the '/' character during input
	in >> frac.numerator >> divSign >> frac.denominator;
	return in;
}

// Display a fraction, in the form "numerator/denominator."
void Fraction::Show()
{
	Reduce();
	if (denominator == 1)
	{
		cout << numerator;
	}
	else
	{
		cout << numerator << '/' << denominator;
	}
}

// Evaluate returns the decimal equivalent of the fraction
double Fraction::Evaluate()
{
	double n = numerator;		// convert numerator to float
	double d = denominator;	// convert denominator to float
	return (n / d);			// compute and return float representation
}

// This function reduces a fraction to its lowest terms.
void Fraction::Reduce()
{
	int dividend;       // the number to be divided
	int divisor;		// the number to divide into the dividend
	int remainder;		
	
	if (numerator == 0)
	{
		numerator = 1;
		return; //can't reduce 0
	}
	else if (numerator > denominator)
	{
		dividend = numerator;
		divisor = denominator;
	}
	else
	{
		dividend = denominator;
		divisor = numerator;
	}

	remainder = dividend % divisor;

	while (remainder != 0)
	{
		dividend = divisor;
		divisor = remainder;
		remainder = dividend % divisor;
	} 
	//reduce by dividing numerator and denominator by the LCD which is currently in the divisor
	if (divisor != 0)
	{
		numerator /= divisor;
		denominator /= divisor;
	}
}

Fraction Fraction::Add(const Fraction * f2)
{
	Fraction r;				// the return value of f1 + f2
	r.numerator = (this->numerator * f2->denominator) +
		(f2->numerator * this->denominator);// compute numerator
	r.denominator = this->denominator * f2->denominator;// compute denominator
	r.Reduce();
	return r;
}

// Overload of operator ++ for incrementing
Fraction Fraction::operator++ ()
{
	numerator = numerator + denominator;// compute numerator
	Reduce();
	return *this;							// return the result
}

Fraction::~Fraction() {
	cout << "Destructed\n";
}

Fraction::Fraction(const Fraction& myFrac) {
	cout << "Copy constructor called\n";
	this->denominator = myFrac.denominator;
	this->numerator = myFrac.numerator;
}

Fraction Fraction::operator=(const Fraction& myFrac) {
	cout << "Assignment copy called\n";
	this->denominator = myFrac.denominator;
	this->numerator = myFrac.numerator;
	return (*this);
}

Fraction Fraction::operator+(const Fraction& myFrac) {
	Fraction sum(0, 0);

	sum.numerator = (this->numerator * myFrac.denominator) + (this->denominator * myFrac.numerator);
	sum.denominator = this->denominator * myFrac.denominator;
	
	sum.Reduce();

	return sum;
}

ostream& operator<<(ostream& out, Fraction& myFrac) {
	myFrac.Reduce();
	if (myFrac.denominator == 1)
	{
		out << myFrac.numerator;
	}
	else
	{
		out << myFrac.numerator << '/' << myFrac.denominator;
	}
	return out;
}

Fraction Fraction::operator*(const Fraction& myFrac) {
	Fraction sum(0, 0);
	sum.numerator = this->numerator * myFrac.numerator;
	sum.denominator = this->denominator * myFrac.denominator;
	sum.Reduce();
	return sum;
}

bool Fraction::operator==(const Fraction& myFrac) {
	if (this->denominator * myFrac.numerator == this->numerator * myFrac.denominator) {
		return true;
	}
	else {
		return false;
	}
}