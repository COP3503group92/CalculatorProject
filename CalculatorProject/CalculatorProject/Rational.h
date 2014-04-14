#pragma once

// LIBRARY INCLUDES
#include "LibraryIncludes.h"

// CONTROLLER
#include "Controller.h"

// OPERATIONS
#include "Operations.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"

// NUMBER
#include "Number.h"
#include "Integer.h"
// #include "Rational.h"
#include "SpecialCase.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"

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
