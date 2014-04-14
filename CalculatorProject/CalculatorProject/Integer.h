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
// #include "Integer.h"
#include "Rational.h"
#include "SpecialCase.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"

class Integer :
	public Number
{
public:
	Integer();
	//MUY IMPORTANTE
	Integer(string value);
	Integer(int value);
	~Integer();
	//possibly worth implementing both a string and an int version...
	int getValue();
	void setValue(int value);
	//To appease the Number god
	void simplify();
	string getType();
	string toString();
	bool operator==(Number* a);
private:
	int value;
	const string typeName = "Integer";
};