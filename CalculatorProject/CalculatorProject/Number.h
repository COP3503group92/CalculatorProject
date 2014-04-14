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
// #include "Number.h"
#include "Integer.h"
#include "Rational.h"
#include "SpecialCase.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"

class Number {
public:
	virtual ~Number();
	//May need to consider having an == overload for every class.
	virtual void simplify(); 
	virtual string getType();
	virtual string toString();
	virtual bool operator==(Number* a);
private:
	string typeName;
};
