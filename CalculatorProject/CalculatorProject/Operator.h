#pragma once
#include "Number.h"
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
	string toString();
private:
	string op;
	const string typeName = "Operator";
};

