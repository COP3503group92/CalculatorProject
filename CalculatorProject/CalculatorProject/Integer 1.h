#pragma once

#include "Includes.h"

class Integer :
	public Number
{
public:
	Integer();
	//MUY IMPORTANTE
	Integer(string value);
	Integer(int value);
	~Integer();
	//possibly worth implementing both a string and an int version...
	int getValue();
	void setValue(int value);
	//To appease the Number god
	void simplify();
	string getType();
	string toString();
	bool operator==(Number* a);
private:
	int value;
	const string typeName = "Integer";
};

#endif
