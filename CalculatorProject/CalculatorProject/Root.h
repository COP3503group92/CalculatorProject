#pragma once

#include "SpecialCase.h"
#include "Integer.h"
#include "Rational.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Expression.h"
#include "Operator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"
#include "Number.h"

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
	Number* getExponent();
	void setRoot(Number* root);
	void setOperand(Number* oper);
	void setCoefficient(Number* coef);
	void setExponent(Number* exp);
	bool operator==(Number*a);
private:
	Number* operand;
	Number* root;
	Number* coefficient;
	Number* exponent;
	const string typeName = "Root";
};
