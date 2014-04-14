#pragma once

#include "SpecialCase.h"
#include "Integer.h"
#include "Rational.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Operator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"

class Expression :
	public SpecialCase
{
public:
	Expression();
	~Expression();
	void add(Number* first, Number* second, Number* op);
	string getType();
	vector<Number*> getExpression();
	void setExpression(vector<Number*> expr);
	Number* getCoefficient();
	void setCoefficient(Number* coef);
	Number* getExponent();
	void setExponent(Number*);
	string toString();
	bool operator==(Number* a);
	void simplify();
private:
	Number* coefficent;
	Number* exponent;
	vector<Number*> expr;
	const string typeName = "Expression";
};
