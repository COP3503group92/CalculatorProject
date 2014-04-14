#pragma once

#include "Number.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"

class Operator :
	public Number
{
	//Future constructors MUST watch out for these!
	
public:
	Operator();
	Operator(string oper);
	string getOperator();
	string getType();
	//To appease the Number god
	void simplify();
	~Operator();
	string toString();
	Number* getCoefficient();
	Number* getExponent();
	void setExponent(Number* exp);
	void setCoefficient(Number coef);
private:
private:
	string op;
	const string typeName = "Operator";
	bool operator==(Number* a);
};
