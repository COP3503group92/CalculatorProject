#ifndef OPERATOR_H_
#define OPERATOR_H_

#define TYPE_NAME "Operator"

#include "Includes.h"

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

#endif

