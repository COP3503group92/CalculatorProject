#pragma once

#include "Includes.h"

class Pi :
	public SpecialCase
{
public:
	Pi();
	Pi(Number* coefficient, Number* exponent);
	Pi(bool negative);
	~Pi();
	void simplify();
	Number* getCoefficient();
	void setCoefficient(Number* coefficient);
	string getType();
	Number* getExponent();
	void setExponent(Number* exponent);
	string toString();
	bool operator==(Number* a);

	
private:
	Number* coefficient;
	Number* exponent;
	bool negative;
	const string typeName = "Pi";

};

#endif

