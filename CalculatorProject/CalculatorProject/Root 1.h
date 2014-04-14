#pragma once

#include "Includes.h"

class Root :
	public SpecialCase
{
public:
	Root();
	~Root();
	Root(Number* operand, Number* root);
	Root(Number* operand, Number* root, Number* coefficient, Number* exponent);
	string getType();
	void simplify();
	string toString();
	Number* getRoot();
	Number* getCoefficient();
	Number* getOperand();
	Number* getexponent();
	void setRoot(Number* root);
	void setOperand(Number* oper);
	void setCoefficient(Number* coef);
	void setExponent(Number* exp);
private:
	Number* operand;
	Number* root;
	Number* coefficient;
	Number* exponent;
	const string typeName = "Root";
};

#endif

