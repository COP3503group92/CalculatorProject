#pragma once
#include "Number.h"
using namespace std;
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
private:
	int value;
	const string typeName = "Integer";
};

