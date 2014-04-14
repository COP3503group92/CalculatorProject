#pragma once

#include "LibraryIncludes.h"

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
