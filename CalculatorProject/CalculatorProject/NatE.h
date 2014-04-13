#ifndef NATE_H_
#define NATE_H_

#include "Includes.h"

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

#endif