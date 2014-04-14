#pragma once

#include "Includes.h"

class Expression :
	public SpecialCase
{
public:
	Expression();
	~Expression();
	void add();
	string getType();
	vector<Number*> getExpression();
	void setExpression(vector<Number*> expr);
private:
	Number* coefficent;
	vector<Number*> expr;
	const string typeName = "Expression";
};

#endif
