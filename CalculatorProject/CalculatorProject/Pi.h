#pragma once
#include "SpecialCase.h"
class Pi :
	public SpecialCase
{
public:
	Pi();
	Pi(bool negative);
	~Pi();
	void simplify();
	Number* getCoefficent();
	void setCoefficient(Number* coefficient);
	string getType();
	Number* getExponent();
	void setExponent(Number* exponent);
	
private:
	Number* coefficient;
	Number* power;
	bool negative;
	const string typeName = "Pi"

};

