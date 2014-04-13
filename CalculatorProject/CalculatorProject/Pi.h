#ifndef PI_H_
#define PI_H_

#include "Includes.h"

class Pi :
	public SpecialCase
{
public:
	Pi();
	Pi(bool negative);
	~Pi();
	void simplify();
	Number* getCoefficient();
	void setCoefficient(Number* coefficient);
	string getType();
	Number* getExponent();
	void setExponent(Number* exponent);
	
private:
	Number* coefficient;
	Number* power;
	bool negative;
	const string typeName = "Pi";

};


#endif

