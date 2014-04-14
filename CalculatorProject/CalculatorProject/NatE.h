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
#include "Rational.h"
#include "SpecialCase.h"
#include "Pi.h"
// #include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"

class NatE :
	public SpecialCase
{
public:
	NatE();
	NatE(Number* coefficient, Number* exponent);
	NatE(bool negative);
	~NatE();
	string getType();
	Number* getCoefficient();
	Number* getExponent();
	void setExponent(Number* ex);
	void setCoefficient(Number* co);
	void simplify();
	bool operator==(Number* a);
	string toString();
private:
	bool negative;
	Number* coefficient;
	Number* exponent;
	const string typeName = "NatE";
};