#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "Includes.h"

class Expression :
	public SpecialCase
{
public:
	Expression();
	~Expression();
	void add();
	string getType();
private:
	const string typeName = "Expression";
};
#endif
