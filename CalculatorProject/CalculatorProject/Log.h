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
#include "NatE.h"
// #include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"

class Log :
	public SpecialCase
{
public:
	Log();
	Log(Number* base,Number* operand);
	Log(Number* base, Number* operand, Number* coefficient, Number* exponent);
	void simplify();
	string getType();
	~Log();
	Number* getCoefficient();
	Number* getExponent();
	Number* getBase();
	Number* getOperand();
	void setCoefficient(Number* co);
	void setExponent(Number* ex);
	void setBase(Number* ba);
	void setOperand(Number* oper);
	string toString();
	bool operator==(Number* a);
private:
	vector<Number*> complex;
	Number* coefficient;
	Number* exponent;
	Number* base;
	Number* operand;
	const string typeName = "Log";
};