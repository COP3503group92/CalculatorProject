#ifndef ROOT_H_
#define ROOT_H_

#include "Includes.h"

class Root :
	public SpecialCase
{
public:
	Root();
	~Root();
	Root(Number* operand, Number* root);
	string getType();
	void simplify();
	string toString();
	Number* getRoot();
	Number* getCoefficient();
	Number* getOperand();
	void setRoot(Number* root);
	void setOperand(Number* oper);
	void setCoefficient(Number* coef);
private:
	Number* operand;
	Number* root;
	Number* coefficient;
	const string typeName = "Root";
};

#endif

