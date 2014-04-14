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
	void add();
	string getType();
	vector<Number*> getExpression();
	void setExpression(vector<Number*> expr);
private:
	Number* coefficent;
	vector<Number*> expr;
	const string typeName = "Expression";
};