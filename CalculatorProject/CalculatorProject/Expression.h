#pragma once
#include "SpecialCase.h"
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

