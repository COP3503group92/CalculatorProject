#ifndef LOG_H_
#define LOG_H_

#include "Includes.h"

class Log :
	public SpecialCase
{
public:
	Log();
	Log(Number* base,Number* operand);
	void simplify();
	string getType();
	~Log();

private:
	Number* coefficient;
	Number* exponent;
	Number* base;
	Number* operand;
	const string typeName = "Log";
};

#endif

