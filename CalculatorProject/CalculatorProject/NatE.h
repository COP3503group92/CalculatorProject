#pragma once
#include "SpecialCase.h"
class NatE :
	public SpecialCase
{
public:
	NatE();
	NatE(bool negative);
	~NatE();
	string getType();
	Number* getCoefficient();
	Number* getExponent();
	void setExponent(Number* ex);
	void setCoefficient(Number* co);
	void simplify();
private:
	bool negative;
	Number* coefficient;
	Number* exponent;
	const string typeName = "NatE";
};

