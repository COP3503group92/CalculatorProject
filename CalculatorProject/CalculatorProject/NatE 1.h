#pragma once

#include "Includes.h"

class NatE :
	public SpecialCase
{
public:
	NatE();
	NatE(Number* coefficient, Number* exponent);
	NatE(bool negative);
	~NatE();
	string getType();
	Number* getCoefficient();
	Number* getExponent();
	void setExponent(Number* ex);
	void setCoefficient(Number* co);
	void simplify();
	bool operator==(Number* a);
	string toString();
private:
	bool negative;
	Number* coefficient;
	Number* exponent;
	const string typeName = "NatE";
};

#endif
