#pragma once

#include "SpecialCase.h"
#include "Integer.h"
#include "Rational.h"
#include "Pi.h"
#include "NatE.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"

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
	vector<Number*> getComplex();
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
