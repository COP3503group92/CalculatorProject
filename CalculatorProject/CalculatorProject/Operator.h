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
#include "Root.h"
#include "Expression.h"
// #include "Operator.h"

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
private:
	string op;
	const string typeName = "Operator";
	bool operator==(Number* a);
};