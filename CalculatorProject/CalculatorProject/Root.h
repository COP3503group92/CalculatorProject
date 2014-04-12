#pragma once
#include "SpecialCase.h"
class Root :
	public SpecialCase
{
public:
	Root();
	~Root();
	string getType;
	void simplify();
private:
	const string typeName = "Root";
};

