#pragma once

#include "Includes.h"

class Rational:public Number {
public:
	Rational();
	Rational(Number* numerator);
	Rational(Number* numerator, Number* denominator);
	~Rational();
	void simplify(); 
	string getType();
	Number* getNumerator();
	Number* getDenominator();
	void setNumerator(Number* numer);
	void setDenominator(Number* denom);
	string toString();
	bool operator==(Number* a);
private:
	Number* numerator;
	Number* denominator;
	const string typeName="Rational";
	void leastCommonDenom(int& n, int& d);
};

#endif /* RATIONAL_H_ */
