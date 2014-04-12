#pragma once
#include "SpecialCase.h"
class NatE :
	public SpecialCase
{
public:
	NatE();
	~NatE();
	string getType();
private:
	bool negative;
	const string typeName = "NatE";
};

