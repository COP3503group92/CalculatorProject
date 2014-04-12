#pragma once
#include "SpecialCase.h"
class Root :
	public SpecialCase
{
public:
	Root();
	~Root();
	string getType;
private:
	const string typeName = "Root";
};

