#pragma once

#include "LibraryIncludes.h"

class Number {
public:
	virtual ~Number();
	//May need to consider having an == overload for every class.
	virtual void simplify()=0; 
	virtual string getType()=0;
	virtual string toString()=0;
	virtual bool operator==(Number* a)=0;
	virtual Number* getCoefficient()=0;
	virtual Number* getExponent()=0;
	virtual void setExponent(Number* exp)=0;
	virtual void setCoefficient(Number* coef)=0;
private:
	string typeName;
};
