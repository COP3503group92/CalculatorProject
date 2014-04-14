#pragma once

#include "Number.h"
#include "Integer.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"

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
