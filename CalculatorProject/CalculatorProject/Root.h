#ifndef ROOT_H_
#define ROOT_H_

#include "Includes.h"

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

#endif

