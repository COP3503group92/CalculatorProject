#pragma once

#include "Number.h"

class SpecialCase:public Number {
public:
	virtual string toString();
	virtual ~SpecialCase();
	virtual void simplify();
	virtual string getType();
private:
	Number* coefficient;
	Number* power;
	string typeName;

};
