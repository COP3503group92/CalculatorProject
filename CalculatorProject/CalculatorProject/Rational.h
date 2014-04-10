/*
 * Rational.h
 *
 *  Created on: Apr 5, 2014
 *      Author: mikeykem
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include "Number.h"

class Rational:public Number {
public:
	Rational(int numeratorInt);
	Rational(Number* numeratorSpec, int denominatorInt);
	Rational(int numeratorInt, int denominatorInt);
	Rational(int numeratorInt, Number* denominatorSpec);
	Rational(Number* numeratorSpec, Number* denominatorSpec);
	virtual ~Rational();
private:
	int numeratorInt;
	int denominatorInt;
	Number* numeratorSpec;
	Number* denominatorSpec;
};

#endif /* RATIONAL_H_ */
