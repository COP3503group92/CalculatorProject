#include "Integer.h"


Integer::Integer()
{
	value = 1;
}

Integer::Integer(string value){
	this->value = atoi(value.c_str());
}

Integer::Integer(int value){
	this->value = value;
}

Integer::~Integer()
{
}

int Integer::getValue(){
	return this->value;
}

void Integer::setValue(int value){
	this->value = value;
}

void Integer::simplify(){
}

string Integer::getType(){
	return typeName;
}
