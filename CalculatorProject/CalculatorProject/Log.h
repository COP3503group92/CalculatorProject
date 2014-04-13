#pragma once
#include "SpecialCase.h"
class Log :
	public SpecialCase
{
public:
	Log();
	Log(Number* base,Number* operand);
	void simplify();
	string getType();
	~Log();
	Number* getCoefficient();
	Number* getExponent();
	Number* getBase();
	Number* getOperand();
	void setCoefficient(Number* co);
	void setExponent(Number* ex);
	void setBase(Number* ba);
	void setOperand(Number* oper);
private:
	Number* coefficient;
	Number* exponent;
	Number* base;
	Number* operand;
	const string typeName = "Log";
};

