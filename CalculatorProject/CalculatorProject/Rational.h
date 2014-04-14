/*
 * Rational.h
 *
 *  Created on: Apr 5, 2014
 *      Author: mikeykem
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

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
	Number* getCoefficient();
	Number* getExponent();
	void setExponent(Number* exp);
	void setCoefficient(Number* coef);
private:
	Number* numerator;
	Number* denominator;
	const string typeName="Rational";
	void leastCommonDenom(int& n, int& d);
};

#endif /* RATIONAL_H_ */
