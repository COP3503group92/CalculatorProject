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
bool Integer::operator==(Number* a){
	if (a->getType() == "Integer"){
		Integer* in = dynamic_cast<Integer*>(a);
		if (in->getValue() == this->value){
			return true;
		}
	}
	return false;
}
string Integer::toString(){
	string str = to_string(this->value);
	return str;
}
Number* Integer::getCoefficient(){
	return this;
}

Number* Integer::getExponent(){
	return new Integer(1);
}

void Integer::setExponent(Number* exp){

}
void Integer::setCoefficient(Number* coef){

}