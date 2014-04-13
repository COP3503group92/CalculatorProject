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
private:
	Number* operand;
	Number* root;
	const string typeName = "Root";
};

#endif

