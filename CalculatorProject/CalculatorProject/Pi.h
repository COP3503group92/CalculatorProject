#pragma once

#include "SpecialCase.h"
#include "Integer.h"
#include "Rational.h"
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

class Pi :
	public SpecialCase
{
public:
	Pi();
	Pi(Number* coefficient, Number* exponent);
	Pi(bool negative);
	~Pi();
	void simplify();
	Number* getCoefficient();
	void setCoefficient(Number* coefficient);
	string getType();
	Number* getExponent();
	void setExponent(Number* exponent);
	string toString();
	bool operator==(Number* a);

	
private:
	Number* coefficient;
	Number* exponent;
	bool negative;
	const string typeName = "Pi";

};