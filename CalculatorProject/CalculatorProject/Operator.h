#pragma once
#include "Number.h"
#define TYPE_NAME "Operator"
class Operator :
	public Number
{
	//Future constructors MUST watch out for these!
	
public:
	Operator();
	Operator(string oper);
	string getOperator();
	string getType();
	//To appease the Number god
	void simplify();
	~Operator();
private:
	string op;
};

