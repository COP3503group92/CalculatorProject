#pragma once
#include "SpecialCase.h"
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
private:
	Number* operand;
	Number* root;
	const string typeName = "Root";
};

