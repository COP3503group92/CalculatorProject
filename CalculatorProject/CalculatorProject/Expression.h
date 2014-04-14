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
	vector<Number*> getExpression();
	void setExpression(vector<Number*> expr);
	Number* getCoefficient();
	void setCoefficient(Number*);
private:
	Number* coefficent;
	vector<Number*> expr;
	const string typeName = "Expression";
};

#endif
