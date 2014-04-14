#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "Includes.h"

class Expression :
	public SpecialCase
{
public:
	Expression();
	~Expression();
	void add(Number* first, Number* second, Number* op);
	string getType();
	vector<Number*> getExpression();
	void setExpression(vector<Number*> expr);
	Number* getCoefficient();
	void setCoefficient(Number* coef);
	Number* getExponent();
	void setExponent(Number*);
	string toString();
	bool operator==(Number* a);
	void simplify();
private:
	Number* coefficent;
	Number* exponent;
	vector<Number*> expr;
	const string typeName = "Expression";
};

#endif
