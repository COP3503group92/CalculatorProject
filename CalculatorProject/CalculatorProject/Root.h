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
#include "Log.h"
// #include "Root.h"
#include "Expression.h"
#include "Operator.h"

class Root :
	public SpecialCase
{
public:
	Root();
	~Root();
	Root(Number* operand, Number* root);
	Root(Number* operand, Number* root, Number* coefficient, Number* exponent);
	string getType();
	void simplify();
	string toString();
	Number* getRoot();
	Number* getCoefficient();
	Number* getOperand();
	Number* getexponent();
	void setRoot(Number* root);
	void setOperand(Number* oper);
	void setCoefficient(Number* coef);
	void setExponent(Number* exp);
private:
	Number* operand;
	Number* root;
	Number* coefficient;
	Number* exponent;
	const string typeName = "Root";
};