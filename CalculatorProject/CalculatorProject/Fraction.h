#ifndef FRACTION_H_
#define FRACTION_H_

#include <string>

using namespace std;

class Fraction{

public:
	Fraction();
	Fraction(string numerator, string denomenator);
	Fraction(string numerator);
	string getNumerator();
	string getDenomenator();
	void setNumerator(string numerator);
	void setDenomenator(string denomenator);
	string toString();

private:
	string numerator;
	string denomenator;

};

#endif